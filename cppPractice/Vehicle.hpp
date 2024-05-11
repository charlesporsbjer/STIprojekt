#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <iostream>
#include <string>
#include "Chassis.hpp" 
#include "Tyres.hpp"   
#include "Brakes.hpp"  

using namespace std;

class Vehicle {
public:
    Vehicle(string owner, string category, string make, int productionYear, Chassis chassis, Tyres tyres, Brakes brakes, int weight);
    
    virtual void print() const = 0;

    virtual ~Vehicle();

protected:
    string owner;
    string category;
    string make;
    int productionYear;
    Chassis chassis;
    Tyres tyres;
    Brakes brakes;
    int weight;
};

#endif // VEHICLE_HPP