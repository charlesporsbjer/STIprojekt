#include <iostream>
#include <string>

#include "Transmission.hpp"

using namespace std;

Transmission::Transmission(int gears, string type) : gears(gears), type(type) {}

void Transmission::print() const {
    cout << "Transmission specifications: \n" <<
        "Gears: " << gears << "\n" <<
            "Type: " << type << "\n";
}

