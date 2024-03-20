#include <iostream>
#include <string>

using namespace std;

class Chassi {
private:
    string color;
    string material;
public:
    Chassi(string color, string material) : color(color), material(material) {}

    void print() const {
        cout << "Chassi specifications: \n" << 
        "Color: " << color << "\n" <<
            "Material: " << material << "\n"; 
    }
};

class Engine {
private:
    string fuel;
    float volume;
    int cylinders;
    int horsepower;
public:
    Engine(string fuel, float volume, int cylinders, int horsepower)
        : fuel(fuel), volume(volume), cylinders(cylinders), horsepower(horsepower) {
        }
    void print() const {
        cout << "Engine specifications: \n" << 
            "Fuel type: " << fuel << "\n" <<
                "Volume: " << volume << "\n" <<
                    "Cylinders: " << cylinders << "\n"
                        "Horsepower: " << horsepower << "\n";
    }
};

class Transmission {
private:
    int gears;
    string type;
public:
    Transmission(int gears, string type) : gears(gears), type(type) {}

    void print() const {
        cout << "Transmission specifications: \n" <<
            "Gears: " << gears << "\n" <<
                "Type: " << type << "\n";
    }
};

class Tyres {
private:
    string brand;
    string season;
    int year;
public:
    Tyres(string brand, string season, int year) : brand(brand), season(season), year(year) {}

    void print() const {
        cout << "Tyre specifications: \n" << 
            "Brand: " << brand << "\n" <<
                "Season: " << season << "\n" <<
                    "Production year: " << year << "\n";
    }
};

class Vehicle {
public:
    Vehicle(string category, string make, int productionYear, Chassi chassi)
        : category(category), make(make), productionYear(productionYear), chassi(chassi) {}

    virtual void print() const = 0;

    virtual ~Vehicle() {}
protected:
    string category;
    string make;
    int productionYear;
    Chassi chassi;
};

class Car : public Vehicle {
private:
    string model;
    string body;
    Engine engine;
    Transmission transmission;
    Tyres tyres;
public:
    Car(string category, string make, int year, Chassi chassi, string model, string body, Engine engine, Transmission transmission, Tyres tyres) 
        : Vehicle(category, make, year, chassi), model(model), body(body), engine(engine), transmission(transmission), tyres(tyres) {}

    void print() const override {
        cout << "Car specifications: \n\n" <<
            "Make: " << make << "\n" <<
                "Model: " << model << "\n" <<
                    "Body: " << body << "\n" << 
                        "Production year: " << productionYear << "\n";
        cout << "\n";                
        chassi.print();
        cout << "\n";
        engine.print();
        cout << "\n";
        transmission.print();
        cout << "\n";
        tyres.print();

    }
};


int main() {
    Chassi blackSteel("Black", "Steel/Plastic");
    Engine v6("Petrol", 2.5, 6, 165);
    Transmission manual5(5, "Manual");
    Tyres summerTyres("Michelin", "Summer", 1999);
    Car cougar("Car", "Ford", 2001, blackSteel, "Cougar", "Coupe", v6, manual5, summerTyres);

    cougar.print();

    return 0;
}