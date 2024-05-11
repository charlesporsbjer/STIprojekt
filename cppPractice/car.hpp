#ifndef CAR_HPP
#define CAR_HPP

#include <string>
#include <iostream>

#include "Vehicle.hpp" 
#include "Chassis.hpp" 
#include "Tyres.hpp"  
#include "Brakes.hpp" 
#include "Engine.hpp" 
#include "Transmission.hpp"

using namespace std;

class Car : public Vehicle {
private:
    string model;
    string body;
    string drivetrain;
    Engine engine;
    Transmission transmission;
    int mileage;
    int fuelCapacity;
    float fuel;
    float consumption;
public:
    Car(string owner, string category, string make, int year, Chassis chassis, Tyres tyres, Brakes brakes, string model, string body, string drivetrain, Engine engine, Transmission transmission, int weight, int mileage, int fuelCapacity, float fuel, float consumption);
    
    void print() const override;
    void drive(int kilometers);
    void refuel(float volume);
    double calculateSpeed();
    string getModel();
};

#endif // CAR_HPP