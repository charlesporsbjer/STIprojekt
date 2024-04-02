#include <iostream>
#include <string>

#include "Vehicle.hpp"
#include "Engine.hpp"
#include "Transmission.hpp"
#include "car.hpp"

using namespace std;

// TODO: code other functionalitites in other files.

// TODO: Create Race method to pit one Vehicle against another. A new class?


Car::Car(string owner, string category, string make, int year, Chassis chassis, Tyres tyres, Brakes brakes, string model, string body, string drivetrain, Engine engine, Transmission transmission, int weight, int mileage, int fuelCapacity, float fuel, float consumption) 
    : Vehicle(owner, category, make, year, chassis, tyres, brakes, weight), model(model), body(body), drivetrain(drivetrain), engine(engine), transmission(transmission), mileage(mileage), fuelCapacity(fuelCapacity), fuel(fuel), consumption(consumption) {}

void Car::print() const {
    cout << "Car specifications: \n\n" <<
    "Owner: " << owner << "\n" <<
        "Make: " << make << "\n" <<
            "Model: " << model << "\n" <<
                "Body: " << body << "\n" << 
                    "Drivetrain: " << drivetrain << "\n" << 
                        "Production year: " << productionYear << "\n" << 
                            "Weight: " << weight << "\n" <<
                                "Mileage: " << mileage << "\n" <<
                                    "Fuel capacity : " << fuelCapacity << "\n" <<
                                        "Fuel: " << fuel << "\n" <<
                                            "Consumption: " << consumption << "\n";
                            
    cout << "\n";                
    chassis.print();
    cout << "\n";
    engine.print();
    cout << "\n";
    transmission.print();
    cout << "\n";
    tyres.print();
    cout << "\n";
    brakes.print();
}
void Car::drive(int kilometers) {
    fuel -= consumption * (kilometers / 10);
    if (fuel < 5.0)
        cout << "Car needs to refuel. \n";
    if (fuel <= 0.0) {
        fuel = 0.0;
        cout << "Car ran out of fuel. \n"; 
    }
    cout << "Drove " << kilometers << " kilometers. Tank is now at " << fuel << ". \n";
}
void Car::refuel(float volume) {
    fuel += volume;
    if(fuel >= fuelCapacity) {
        fuel = fuelCapacity;
        cout << "Tank is full. \n";
    }
    else 
        cout << "Filled with " << volume << " liters. Tank is now at " << fuel << "\n";
}
double Car::calculateSpeed() {
    double speed;
    double ratio = this->engine.getHorsepower() / weight;
    
    if (drivetrain == "FWD")        speed = (ratio * 0.95);
    else if (drivetrain == "AWD")   speed = (ratio * 1.2);
    else                            speed = ratio;
    
    return speed;
}

string Car::getModel() { return model; }

