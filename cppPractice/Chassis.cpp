#include <iostream>
#include <string>

#include "Chassis.hpp"

using namespace std;

Chassis::Chassis(string color, string material) : color(color), material(material) {}

void Chassis::print() const {
    cout << "Chassis specifications: \n" << 
    "Color: " << color << "\n" <<
        "Material: " << material << "\n"; 
}
