from time import sleep
from fastapi import FastAPI, HTTPException, Depends, status
from pydantic import BaseModel, UUID4
from uuid import uuid4
import requests
import os
from dotenv import load_dotenv
from random import random
from rich import print
from fastapi.security import OAuth2PasswordBearer, OAuth2PasswordRequestForm
from jose import JWTError, jwt
from passlib.context import CryptContext
from datetime import datetime, timedelta
from typing import Optional



# TODO: Prio 1: Merge get_thermostat_setting and get_current_sensor_temp (return a nice dict) , make sensors and blinds connected to a certain room.
# TODO: Prio 2: Let weather conditions affect temperature in house, let heater location affect sensor temp locally. (These changes only make simulation more realistic)




# GLOBALS

STD_TEMP = 20

load_dotenv()

app = FastAPI()

house_db = {}

username_db = {}



# API CLASSES

class Weather(BaseModel):
    temperature_2m: float
    rain: float
    showers: float
    snowfall: float
    cloud_cover: float
    wind_speed_10m: float

class Sensor(BaseModel):
    room: str
    current_temp: float
    thermostat: float

class Heater(BaseModel):
    name: str | None = None
    is_on: bool = False
    # Should be associated with a certain room at a later date.

class Blind(BaseModel):
    name: str | None = None
    is_down: bool = False
    # Should be associated with sun direction at a later date.
    # Should be a value from 0.0 to 1.0 for amount pulled down.

class Location(BaseModel):
    lat: float
    lon: float
    # Address should be kept in this class.

class House(BaseModel):
    name: str
    house_id: UUID4
    sensors: list[Sensor] = []
    location: Location
    heaters: list[Heater] = []
    blinds: list[Blind] = []
    # There should be a raw adress field extracted from the users input in create_house for user experience.
    # Door locks and lights could be added at a later date.

class User(BaseModel):
    username: str
    # Eventual user info should be added to this class at a later date.




# SECURITY VARIABLES & CLASSES

# to get a string like this run:
# openssl rand -hex 32
SECRET_KEY = os.getenv('SECRET_KEY')
if not SECRET_KEY:
    print({"error": "Secret key not found"})
    # When login is fully online make sure program crashes if no secret key or algorithm found!!!!!!!
ALGORITHM = os.getenv('ALGORITHM')
if not ALGORITHM:
    print({"error": "Algorithm not found"})
ACCESS_TOKEN_EXPIRE_MINUTES = 30

pwd_context = CryptContext(schemes=["bcrypt"], deprecated="auto")
oauth2_scheme = OAuth2PasswordBearer(tokenUrl="token")

class Token(BaseModel):
    access_token: str
    token_type: str

class TokenData(BaseModel):
    username: Optional[str] = None





# SECURITY FUNCTIONS

def verify_password(plain_password, hashed_password):
    return pwd_context.verify(plain_password, hashed_password)

def get_password_hash(password):
    return pwd_context.hash(password)

def authenticate_user(db, username: str, password: str):
    user = db.get(username)
    if not user:
        return False
    if not verify_password(password, user['hashed_password']):
        return False
    return user

def create_access_token(data: dict, expires_delta: Optional[timedelta] = None):
    to_encode = data.copy()
    if expires_delta:
        expire = datetime.utcnow() + expires_delta
    else:
        expire = datetime.utcnow() + timedelta(minutes=15)
    to_encode.update({"exp": expire})
    encoded_jwt = jwt.encode(to_encode, SECRET_KEY, algorithm=ALGORITHM)
    return encoded_jwt





# API FUNCTIONS

@app.get("/")
def read_root():
    return {"message": "Welcome to your smart home temperature API!"}





# USER SECURITY FUNCTIONS

@app.post("/register", status_code=201)
def register_user(username: str, password: str):
    """Register user in in username database."""
    if username in username_db:
        raise HTTPException(status_code=400, detail="Username already registered")
    hashed_password = get_password_hash(password)
    username_db[username] = {
        "username": username,
        "hashed_password": hashed_password,
        "disabled": False
    }
    return {"message": "Username registered successfully"}

@app.post("/token", response_model=Token)
async def login_for_access_token(form_data: OAuth2PasswordRequestForm = Depends()):
    """Let's user log in."""
    user = authenticate_user(username_db, form_data.username, form_data.password)
    if not user:
        raise HTTPException(
            status_code=status.HTTP_401_UNAUTHORIZED,
            detail="Incorrect username or password",
            headers={"WWW-Authenticate": "Bearer"},
        )
    access_token_expires = timedelta(minutes=ACCESS_TOKEN_EXPIRE_MINUTES)
    access_token = create_access_token(
        data={"sub": user['username']}, expires_delta=access_token_expires
    )
    return {"access_token": access_token, "token_type": "bearer"}

def get_current_user(token: str = Depends(oauth2_scheme)):
    credentials_exception = HTTPException(
        status_code=status.HTTP_401_UNAUTHORIZED,
        detail="Could not validate credentials",
        headers={"WWW-Authenticate": "Bearer"},
    )
    try:
        payload = jwt.decode(token, SECRET_KEY, algorithms=[ALGORITHM])
        username: str = payload.get("sub")
        if username is None:
            raise credentials_exception
    except JWTError:
        raise credentials_exception

    user_data = username_db.get(username)
    if not user_data:
        raise credentials_exception

    return User(**user_data)

@app.get("/users/me")
async def read_users_me(current_user: User = Depends(get_current_user)):
    """Returns current user."""
    return current_user





# USER FUNCTIONS

@app.post("/new_house/{house_location}/{house_name}", status_code=201)
def create_house(house_location: str, house_name: str, current_user: User = Depends(get_current_user)) -> House:
    """Creates a house."""
    if current_user.username not in username_db:
        raise HTTPException(status_code=404, detail="User not authenticated")

    geocode_apikey = os.getenv('GEOCODE_API')
    if not geocode_apikey:
        raise HTTPException(status_code=500, detail="Geocode API key not found")

    geocode_url = f"https://geocode.maps.co/search?q={house_location}&api_key={geocode_apikey}"
    geocode_response = requests.get(geocode_url)
    geocode_response.raise_for_status()
    geocode_data = geocode_response.json()
    
    if not geocode_data:
        raise HTTPException(status_code=404, detail="No location found for specified address")

    lat = geocode_data[0]['lat']
    lon = geocode_data[0]['lon']
    
    new_location = Location(lat=lat, lon=lon)
    new_user = House(name=house_name, house_id=uuid4(), sensors=[], location=new_location, heaters=[], blinds=[])
    house_db[str(new_user.house_id)] = new_user

    return new_user

@app.get("/house/{house_id}")
def get_house_info(house_id: UUID4, current_user: User = Depends(get_current_user)) -> House:
    """Returns the house class for viewing."""
    house_id_str = str(house_id)
    if not house_id_str in house_db or current_user.username not in username_db:
        raise HTTPException(status_code=404, detail="House not found or user not authenticated.")
    return house_db[house_id_str]

@app.patch("/house/{house_id}")
def change_location(house_id: UUID4, house_location:str, current_user: User = Depends(get_current_user)) -> dict[str, str]:
    """Changes house location."""
    house_id_str = str(house_id)
    if not house_id_str in house_db or current_user.username not in username_db:
        raise HTTPException(status_code=404, detail="House not found or user not authenticated.")
    else:
        geocode_apikey = os.getenv('GEOCODE_API')
    if not geocode_apikey:
        raise HTTPException(status_code=500, detail="Geocode API key not found")

    geocode_url = f"https://geocode.maps.co/search?q={house_location}&api_key={geocode_apikey}"
    geocode_response = requests.get(geocode_url)
    geocode_response.raise_for_status()
    geocode_data = geocode_response.json()
    
    if not geocode_data:
        raise HTTPException(status_code=404, detail="No location found for the specified address")  

    house_db[house_id_str].location = Location(lat=geocode_data[0]['lat'], lon=geocode_data[0]['lon'])

    return {"message": f"House {house_db[house_id_str].name} changed location to {house_location} successfully"}

@app.delete("/house/{house_id}")
def remove_house(house_id: UUID4, current_user: User = Depends(get_current_user)) -> dict[str, str]:
    """Removes house from database."""
    house_id_str = str(house_id)
    if house_id_str not in house_db or current_user.username not in username_db:
        raise HTTPException(status_code=404, detail="House not found or user not authenticated.")
    else:
        removed_user_name = house_db[house_id_str].name
        del house_db[house_id_str]
        return {"message": f"removed user {removed_user_name}"}





# HEATER FUNCTIONS

@app.get("/heaters/{house_id}")
def get_heaters(house_id: UUID4, current_user: User = Depends(get_current_user)) -> list[Heater]:
    """Returns all heaters."""
    house_id_str = str(house_id)
    if house_id_str not in house_db or current_user.username not in username_db:
        raise HTTPException(status_code=404, detail="House not found or user not authenticated.")
    else:
        return house_db[house_id_str].heaters
    
@app.post("/heaters/{house_id}/{heater_name}")
def add_heater(house_id: UUID4, heater_name: str, current_user: User = Depends(get_current_user)) -> Heater:
    """Adds heater to heaters."""
    house_id_str = str(house_id)
    if house_id_str not in house_db or current_user.username not in username_db:
        raise HTTPException(status_code=404, detail="House not found or user not authenticated.")
    else:
        new_heater = Heater(name=heater_name, is_on=False)
        house_db[house_id_str].heaters.append(new_heater)

        return new_heater
    
@app.delete("/heaters/{house_id}/{heater_name}")
def remove_heater(house_id: UUID4, heater_name: str, current_user: User = Depends(get_current_user)) -> dict[str, str]:
    """Removes heater from heaters."""
    house_id_str = str(house_id)
    if house_id_str not in house_db or current_user.username not in username_db:
        raise HTTPException(status_code=404, detail="House not found or user not authenticated.")
    else:
        # Filtering out the heater to be removed and updating the list
        house_db[house_id_str].heaters = [heater for heater in house_db[house_id_str].heaters if heater.name != heater_name]
        
        return {"message": f"removed {heater_name} from heaters."}




# BLIND FUNCTIONS

@app.post("/blinds/{house_id}/{blind_name}", status_code=201)
def add_blind(house_id: UUID4, blind_name: str, current_user: User = Depends(get_current_user)) -> Blind:
    """Adds new blind to blinds."""
    house_id_str = str(house_id)
    if house_id_str not in house_db or current_user.username not in username_db:
        raise HTTPException(status_code=404, detail="House not found or user not authenticated.")    
    else:
        new_blind = Blind(name=blind_name, is_down=False)
        house_db[house_id_str].blinds.append(new_blind)
        
        return new_blind

@app.get("/blinds/{house_id}")
def get_blinds(house_id: UUID4, current_user: User = Depends(get_current_user)) -> list[Blind]:
    """Returns blinds from house."""
    house_id_str = str(house_id)
    if house_id_str not in house_db or current_user.username not in username_db:
        raise HTTPException(status_code=404, detail="House not found or user not authenticated.")        
    else:
        return house_db[house_id_str].blinds

@app.delete("/blinds/{house_id}")
def remove_blind(house_id: UUID4, blind_name: str, current_user: User = Depends(get_current_user)) -> dict[str, str]:
    """Removes blind from blinds."""
    house_id_str = str(house_id)
    if house_id_str not in house_db or current_user.username not in username_db:
        raise HTTPException(status_code=404, detail="House not found or user not authenticated.")      
    else:
        # Filter out the sensor with the matching room
        original_len = len(house_db[house_id_str].blinds)
        house_db[house_id_str].blinds = [blind for blind in house_db[house_id_str].blinds if blind.name != blind_name]
        
        if len(house_db[house_id_str].blinds) < original_len:
            return {"message": f"removed {blind_name} from blinds."}
        else:
            return {"error": f"{blind_name} not found."}

@app.patch("/blinds/{house_id}/{blind_name}")
def toggle_blind(house_id: UUID4, blind_name: str, current_user: User = Depends(get_current_user)) -> dict[str, str]:
    """Toggles blind up or down."""
    house_id_str = str(house_id)
    if house_id_str not in house_db or current_user.username not in username_db:
        raise HTTPException(status_code=404, detail="House not found or user not authenticated.")
    
    house = house_db[house_id_str]
    blind_found = False
    for blind in house.blinds:
        if blind.name == blind_name:
            blind_found = True
            blind.is_down = not blind.is_down
            status = "down" if blind.is_down else "up"
            return {"message": f"{blind_name} toggled to {status}."}
    
    if not blind_found:
        raise HTTPException(status_code=404, detail="Blind not found.")
    
@app.patch("/blinds/{house_id}/{direction}")
def set_all_blinds(house_id: UUID4, direction: str, current_user: User = Depends(get_current_user)) -> dict[str, str]:
    """Sets all blinds to desired setting."""
    house_id_str = str(house_id)
    if house_id_str not in house_db or current_user.username not in username_db:
        raise HTTPException(status_code=404, detail="House not found or user not authenticated.")    
    
    blinds = house_db[house_id_str].blinds
    if direction == "up":
        for blind in blinds:
            blind.is_down = False
    elif direction == "down":
        for blind in blinds:
            blind.is_down = True
    else:
        raise HTTPException(status_code=400, detail="Direction keyword invalid.")    
    
    return {"message": f"All blinds pulled {direction}."}
                
            



# SENSOR FUNCTIONS

@app.get("/temp_setting/{house_id}/{room}")
def get_thermostat_setting(house_id: UUID4, room: str, current_user: User = Depends(get_current_user)) -> dict[str, str]:
    """Returns chosen thermostat setting."""
    house_id_str = str(house_id)
    if not house_id_str in house_db or current_user.username not in username_db:
        raise HTTPException(status_code=404, detail="House not found or user not authenticated.")
    else:
        if not room in house_db[house_id_str].sensors:
            raise HTTPException(status_code=404, detail="Sensor not found")
        else:
            for sensor in house_db[house_id_str].sensors:
                if sensor.room == room:
                    current_temp = sensor.thermostat
                    return {"message": f"Thermostat is currently set to {current_temp}°C"}

@app.get("/sensors/{house_id}/{room}/temp")
def get_current_sensor_temp(house_id: UUID4, room: str, current_user: User = Depends(get_current_user)) -> dict[str, str]:
    """Returns current sensor temperature."""
    house_id_str = str(house_id)
    if house_id_str not in house_db or current_user.username not in username_db:
        raise HTTPException(status_code=404, detail="House not found or user not authenticated.")
    else:
        for sensor in house_db[house_id_str].sensors:
            if sensor.name == room:
                current_temp = sensor.current_temp
                return {"message": f"The current temperature reading from {room} is {current_temp}°C"}

@app.get("/sensors/{house_id}")
def get_sensors(house_id: UUID4, current_user: User = Depends(get_current_user)) -> list[Sensor]:
    """Returns users sensors."""
    house_id_str = str(house_id)
    if house_id_str not in house_db or current_user.username not in username_db:
        raise HTTPException(status_code=404, detail="House not found or user not authenticated.")
    else:
        return house_db[house_id_str].sensors

@app.get("/current_avg_temp/{house_id}")
def get_current_avg_temp(house_id: UUID4, current_user: User = Depends(get_current_user)):
    """Returns average temperature between all sensors."""
    user_id_str = str(house_id)  # UUID4 of the house
    if user_id_str not in house_db or current_user.username not in username_db:
        raise HTTPException(status_code=404, detail="House not found or User not authenticated.")
    
    house = house_db[user_id_str]
    tot = sum(sensor.current_temp for sensor in house.sensors)
    avg = tot / len(house.sensors)
    return {"message": f"Current temperature in house is {avg}°C"}

@app.post("/sensors/{house_id}/{room}" status_code=201)
def add_sensor(house_id: UUID4, room: str, current_user: User = Depends(get_current_user)) -> Sensor:
    """Adds a sensor to sensors."""
    house_id_str = str(house_id)
    if house_id_str not in house_db or current_user.username not in username_db:
        raise HTTPException(status_code=404, detail="House not found or user not authenticated.")
    else:
        new_sensor = Sensor(room=room, current_temp=get_dummy_temp(), thermostat=STD_TEMP)
        house_db[house_id_str].sensors.append(new_sensor)
        return new_sensor

@app.put("/sensors/{house_id}/{room}/{new_temp}")
def set_thermostat(house_id: UUID4, room: str, new_temp: float, current_user: User = Depends(get_current_user)) -> dict[str, str]:
    """Sets chosen thermostat."""
    house_id_str = str(house_id)
    if house_id_str not in house_db or current_user.username not in username_db:
        raise HTTPException(status_code=404, detail="House not found or user not authenticated.")
    else:
        if room not in house_db[house_id_str].sensors:
            raise HTTPException(status_code=404, detail="Sensor not found")
        else:
            for sensor in house_db[house_id_str].sensors:
                if sensor.room == room:
                    house_db[house_id_str].sensors.thermostat = new_temp
                    return {"message": f"{room} thermostat set to {new_temp}"}
    
@app.patch("/sensors/{house_id}/{old_room}/{new_room}")
def move_sensor(house_id: UUID4, old_room: str, new_room: str, current_user: User = Depends(get_current_user)) -> dict[str, str]:
    """Lets user move sensor to another room while keeping settings."""
    house_id_str = str(house_id)
    if house_id_str not in house_db or current_user.username not in username_db:
        raise HTTPException(status_code=404, detail="House not found or user not authenticated.")
    
    found = False
    new_sensors = []
    for sensor in house_db[house_id_str].sensors:
        if sensor.room == old_room:
            sensor.room = new_room
            found = True
        new_sensors.append(sensor)

    if not found:
        raise HTTPException(status_code=404, detail=f"Sensor in room '{old_room}' not found.")
    
    house_db[house_id_str].sensors = new_sensors
    return {"message": f"Sensor moved from {old_room} to {new_room}"}
    
@app.delete("/sensors/{house_id}/{room}")
def remove_sensor(house_id: UUID4, room: str, current_user: User = Depends(get_current_user)) -> dict[str, str]:
    """Removes sensor from sensors."""
    house_id_str = str(house_id)
    if house_id_str not in house_db or current_user.username not in username_db:
        raise HTTPException(status_code=404, detail="House not found or user not authenticated.")
    else:
        # Filter out the sensor with the matching room
        original_len = len(house_db[house_id_str].sensors)
        house_db[house_id_str].sensors = [sensor for sensor in house_db[house_id_str].sensors if sensor.room != room]
        
        if len(house_db[house_id_str].sensors) < original_len:
            return {"message": f"removed {room} from sensors."}
        else:
            raise HTTPException(status_code=404, detail=f"{room} not found.")  





# WEATHER FUNCTIONS

# Removed and replaced with get_weather because of unknown bug.
"""
def get_outdoor_temp_internal(house_id: UUID4) -> dict[str, str]:
    house_id_str = str(house_id)
    if house_id_str in house_db:
        user_location = house_db[house_id_str].location
        weather_url = f"https://api.open-meteo.com/v1/forecast?latitude={user_location.lat}&longitude={user_location.lon}&current=temperature_2m"
        
        weather_response = requests.get(weather_url)
        weather_response.raise_for_status()
        weather_data = weather_response.json()
        temp = weather_data['current']['temperature_2m']

        return {"temperature": temp}
    else:
        raise HTTPException(status_code=404, detail="House not found.")

@app.get("/outdoor_temp/{house_id}")
def get_outdoor_temp(house_id: UUID4) -> dict[str, str]:
    
    return get_outdoor_temp_internal(house_id)
"""
def get_weather_internal(house_id: UUID4) -> Weather:
    house_id_str = str(house_id)
    if house_id_str in house_db:
        user_location = house_db[house_id_str].location
        url = "https://api.open-meteo.com/v1/forecast"
        params = {
            "latitude": user_location.lat,
            "longitude": user_location.lon,
            "current": ["temperature_2m", "rain", "showers", "snowfall", "cloud_cover", "wind_speed_10m"]
        }
        response = requests.get(url, params=params)
        if response.status_code == 200:
            data = response.json()
            current_weather = data.get('current', {})

            return Weather(**current_weather)
    else:
        raise HTTPException(status_code=404, detail="House not found.")
        
@app.get("/weather/{house_id}")
def get_weather(house_id: UUID4) -> Weather:
    """Returns weather outside house."""
    return get_weather_internal(house_id)





# SIMULATION FUNCTIONS

# Dummy for initializing house temp.
def get_dummy_temp():
    return random() * 10 + 10

# Toggles heater to reach target thermostat temp.
def auto_toggle_heaters():
    for house in house_db.values():
        for sensor in house.sensors:
            if sensor.current_temp < sensor.thermostat:
                for heater in house.heaters:
                        heater.is_on = True
            else:
                for heater in house.heaters:
                        heater.is_on = False

# Simulates outdoor temp influence on indoor temp. 
def simulate_passive_temp_change():
    for house in house_db.values():
        outdoor_temp = get_weather_internal(house.house_id).temperature_2m
        for sensor in house.sensors:
            if outdoor_temp < sensor.current_temp:
                if not any(heater.is_on for heater in house.heaters):
                    sensor.current_temp -= random() / 4 + 0.2
            elif outdoor_temp > sensor.current_temp:
                if any(heater.is_on for heater in house.heaters):
                    sensor.current_temp += random() / 2

# Simulates heat sources influence on indoor temp.
def simulate_heater_heating():
    for house in house_db.values():
        for heater in house.heaters:
            if heater.is_on:
                for sensor in house.sensors:
                    sensor.current_temp += random()/4 + 0.25




# SIMULATION

@app.post("/run_simulation")
def run_simulation():
    auto_toggle_heaters()
    simulate_passive_temp_change()
    simulate_heater_heating()

    return house_db

if __name__ == "__main__":
    while True:
        print(requests.post("http://127.0.0.1:8000/run_simulation").text)
        sleep(5.0)