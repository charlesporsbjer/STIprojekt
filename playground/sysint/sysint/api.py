from fastapi import FastAPI, HTTPException, Body
from pydantic import BaseModel, UUID4
from uuid import uuid4
import requests
import os
from dotenv import load_dotenv
from random import random
from rich import print
import asyncio
from contextlib import asynccontextmanager

# TODO: Prio 1: Login, rullgardiner?, simulation. (simulationskod i test.py)

# TODO: Prio 2: Let weather conditions affect temperature in house.

load_dotenv()

app = FastAPI()

# This class isnt used so far. It might be a good idea to use it.
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

class Location(BaseModel):
    lat: float
    lon: float

class User(BaseModel):
    name: str
    user_id: UUID4
    sensors: list[Sensor] = []
    location: Location
    heaters: list[Heater] = []

user_db = {}

# API functions.
@app.get("/")
def read_root():
    return {"message": "Welcome to your smart home temperature API!"}

# USER FUNCTIONS

@app.post("/new_user/{house_location}/{username}")
def create_user(house_location: str, username: str) -> User:
    """Creates a user."""
    geocode_apikey = os.getenv('GEOCODE_API')
    if not geocode_apikey:
        return {"error": "Geocode API key not found"}

    geocode_url = f"https://geocode.maps.co/search?q={house_location}&api_key={geocode_apikey}"
    geocode_response = requests.get(geocode_url)
    geocode_response.raise_for_status()
    geocode_data = geocode_response.json()
    
    if not geocode_data:
        return {"error": "No location found for the specified address"}

    lat = geocode_data[0]['lat']
    lon = geocode_data[0]['lon']
    
    new_location = Location(lat=lat, lon=lon)
    new_user = User(name=username, user_id=uuid4(), sensors=[], location=new_location, heaters=[])
    user_db[str(new_user.user_id)] = new_user

    return new_user

@app.patch("/user/{user_id}")
def change_location(user_id: UUID4, house_location:str) -> dict[str, str]:
    """Changes user location."""
    user_id_str = str(user_id)
    if not user_id_str in user_db:
        raise HTTPException(status_code=404, detail="User not found")
    else:
        geocode_apikey = os.getenv('GEOCODE_API')
    if not geocode_apikey:
        return {"error": "Geocode API key not found"}

    geocode_url = f"https://geocode.maps.co/search?q={house_location}&api_key={geocode_apikey}"
    geocode_response = requests.get(geocode_url)
    geocode_response.raise_for_status()
    geocode_data = geocode_response.json()
    
    if not geocode_data:
        return {"error": "No location found for the specified address"}

    user_db[user_id_str].location = Location(lat=geocode_data[0]['lat'], lon=geocode_data[0]['lon'])

    return {"message": f"User {user_db[user_id_str].name} changed location to {house_location} successfully"}

@app.delete("/user/{user_id}")
def remove_user(user_id: UUID4) -> dict[str, str]:
    """Removes user from database."""
    user_id_str = str(user_id)
    if user_id_str not in user_db:
        raise HTTPException(status_code=404, detail="User not found")
    else:
        removed_user_name = user_db[user_id_str].name
        del user_db[user_id_str]
        return {"message": f"removed user {removed_user_name}"}

# HEATER FUNCTIONS

@app.get("/heaters/{user_id}")
def get_heaters(user_id: UUID4) -> list[Heater]:
    """Returns all heaters."""
    user_id_str = str(user_id)
    if user_id_str not in user_db:
        raise HTTPException(status_code=404, detail="User not found")
    else:
        return user_db[user_id_str].heaters
    
@app.post("/heaters/{user_id}/{heater_name}")
def add_heater(user_id: UUID4, heater_name: str) -> Heater:
    """Adds heater to heaters."""
    user_id_str = str(user_id)
    if user_id_str not in user_db:
        raise HTTPException(status_code=404, detail="User not found")
    else:
        new_heater = Heater(name=heater_name, is_on=False)
        user_db[user_id_str].heaters.append(new_heater)

        return new_heater
    
@app.delete("/heaters/{user_id}/{heater_name}")
def remove_heater(user_id: UUID4, heater_name: str) -> dict[str, str]:
    """Removes heater from heaters."""
    user_id_str = str(user_id)
    if user_id_str not in user_db:
        raise HTTPException(status_code=404, detail="User not found")
    else:
        for heater in user_db[user_id_str].heaters:
            if heater.room == heater_name:
                del heater
        return {"message": f"removed {heater_name} from heaters."}

# SENSOR FUNCTIONS

@app.get("/temp_setting/{user_id}/{room}")
def get_thermostat_setting(user_id: UUID4, room: str) -> dict[str, str]:
    """Returns chosen thermostat setting."""
    user_id_str = str(user_id)
    if not user_id_str in user_db:
        raise HTTPException(status_code=404, detail="User not found")
    else:
        if not room in user_db[user_id_str].sensors:
            raise HTTPException(status_code=404, detail="Sensor not found")
        else:
            for sensor in user_db[user_id_str].sensors:
                if sensor.room == room:
                    current_temp = sensor.thermostat
                    return {"message": f"Thermostat is currently set to {current_temp}°C"}

@app.get("/sensors/{user_id}/{room}/temp")
def get_current_sensor_temp(user_id: UUID4, room: str) -> dict[str, str]:
    """Returns current sensor temperature."""
    user_id_str = str(user_id)
    if user_id_str not in user_db:
        raise HTTPException(status_code=404, detail="User not found")
    else:
        for sensor in user_db[user_id_str].sensors:
            if sensor.name == room:
                current_temp = sensor.current_temp
                return {"message": f"The current temperature reading from {room} is {current_temp}°C"}

@app.get("/sensors/{user_id}")
def get_sensors(user_id: UUID4) -> list[Sensor]:
    """Returns users sensors."""
    user_id_str = str(user_id)
    if user_id_str not in user_db:
        raise HTTPException(status_code=404, detail="User not found")
    else:
        return user_db[user_id_str].sensors

@app.get("/current_avg_temp/{user_id}")
def get_current_avg_temp(user_id: UUID4) -> dict[str, str]:
    """Returns average temperature between sensors."""
    user_id_str = str(user_id)
    if user_id_str not in user_db:
        raise HTTPException(status_code=404, detail="User not found")
    else:
        tot = 0.0
        avg = 0.0
        for sensor in user_db[user_id_str].sensors:
            tot += sensor.current_temp
            avg = tot / len(user_db[user_id_str].sensors) 
        return {"message": f"Current temperate in house is {avg}°C"}

@app.post("/sensors/{user_id}/{room}")
def add_sensor(user_id: UUID4, room: str) -> Sensor:
    """Adds a sensor to sensors."""
    user_id_str = str(user_id)
    if user_id_str not in user_db:
        raise HTTPException(status_code=404, detail="User not found")
    else:
        new_sensor = Sensor(room=room, current_temp=get_dummy_temp(), thermostat=20)
        user_db[user_id_str].sensors.append(new_sensor)
        return new_sensor

@app.put("/sensors/{user_id}/{room}/{new_temp}")
def set_thermostat(user_id: UUID4, room: str, new_temp: float) -> dict[str, str]:
    """Sets chosen thermostat."""
    user_id_str = str(user_id)
    if user_id_str not in user_db:
        raise HTTPException(status_code=404, detail="User not found")
    else:
        if room not in user_db[user_id_str].sensors:
            raise HTTPException(status_code=404, detail="Sensor not found")
        else:
            for sensor in user_db[user_id_str].sensors:
                if sensor.room == room:
                    user_db[user_id_str].sensors.thermostat = new_temp
                    return {"message": f"{room} thermostat set to {new_temp}"}
    
@app.patch("/sensors/{user_id}/{old_room}/{new_room}")
def move_sensor(user_id: UUID4, old_room: str, new_room: str) -> dict[str, str]:
    """Lets user move sensor to another room while keeping settings."""
    user_id_str = str(user_id)
    if user_id_str not in user_db:
        raise HTTPException(status_code=404, detail="User not found")
    else:
        for sensor in user_db[user_id_str].sensors:
            if sensor.room == old_room:
                old_temp = sensor.current_temp
                moved_room = Sensor(room=new_room, current_temp=get_dummy_temp, thermostat=old_temp)
                del sensor
                user_db[user_id_str].sensors.append(moved_room)
                return {"message": f"Sensor moved from {old_room} to {new_room}"}
            else:
                return {"error": f"{old_room} not found."}
    
@app.delete("/sensors/{user_id}/{room}")
def remove_sensor(user_id: UUID4, room: str) -> dict[str, str]:
    """Removes sensor from sensors."""
    user_id_str = str(user_id)
    if user_id_str not in user_db:
        raise HTTPException(status_code=404, detail="User not found")
    else:
        for sensor in user_db[user_id_str].sensors:
            if sensor.room == room:
                del sensor
                return {"message": f"removed {room} from sensors."}
            else:
                return {"error": f"{room} not found."}

# WEATHER FUNCTIONS

def get_outdoor_temp_internal(user_id: UUID4) -> dict[str, str]:
    user_id_str = str(user_id)
    if user_id_str in user_db:
        user_location = user_db[user_id_str].location
        weather_url = f"https://api.open-meteo.com/v1/forecast?latitude={user_location.lat}&longitude={user_location.lon}&current=temperature_2m"
        
        weather_response = requests.get(weather_url)
        weather_response.raise_for_status()
        weather_data = weather_response.json()
        temp = weather_data['current']['temperature_2m']

        return {"temperature": temp}
    else:
        raise HTTPException(status_code=404, detail="User not found")

@app.get("/outdoor_temp/{user_id}")
def get_outdoor_temp(user_id: UUID4) -> dict[str, str]:
    """Returns temperature outside house."""
    return get_outdoor_temp_internal(user_id)

def get_weather_internal(user_id: UUID4) -> Weather:
    user_id_str = str(user_id)
    if user_id_str in user_db:
        user_location = user_db[user_id_str].location
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
        raise HTTPException(status_code=404, detail="User not found")
        
@app.get("/weather/{user_id}")
def get_weather(user_id: UUID4) -> Weather:
    """Returns weather outside house."""
    return get_weather_internal(user_id)

# SIMULATION FUNCTIONS

# Dummy for initializing house temp.
def get_dummy_temp():
    return random() * 10 + 10

# Toggles heater to reach target thermostat temp.
def auto_toggle_heaters():
    for user in user_db.items():
        if user.current_temp < user.thermostat:
            for heater in user.heaters:
                    heater.is_on = True
        else:
            for heater in user.heaters:
                    heater.is_on = False

# Simulates outdoor temp influence on indoor temp. 
def simulate_passive_temp_change():
    for user in user_db.items():
        if get_outdoor_temp_internal(UUID4(user.user_id)) < user.current_temp:
            if not any(heater.is_on for heater in user.heaters):
                user.current_temp -= random()
        elif get_outdoor_temp_internal(UUID4(user.user_id)) > user.current_temp:
            if any(heater.is_on for heater in user.heaters):
                user.current_temp += random()

# Simulates heat sources influence on indoor temp.
def simulate_heater_heating():
    for user in user_db:
        for heater in user.heaters:
            if heater.is_on:
                user.current_temp += random()/2 + 0.5

if __name__ == "__main__":
    pass