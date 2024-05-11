#include <iostream>
#include <string>

#include "Vehicle.hpp"
#include "Chassis.hpp"
#include "Tyres.hpp"
#include "Brakes.hpp"

using namespace std;

Vehicle::Vehicle(string owner, string category, string make, int productionYear, Chassis chassis, Tyres tyres, Brakes brakes, int weight)
    : owner(owner), category(category), make(make), productionYear(productionYear), chassis(chassis), tyres(tyres), brakes(brakes), weight(weight) {}


Vehicle::~Vehicle() {}