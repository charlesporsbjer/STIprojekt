#include <iostream>
#include <string>

#include "Brakes.hpp"

using namespace std;


Brakes::Brakes(string brand, string type, int pieces) : brand(brand), type(type), pieces(pieces) {}

void Brakes::print() const {
    cout << "Brakes specifications: " << "\n" <<
        "Brand: " << brand << "\n" <<
            "Type: " << type << "\n" <<
                "Pieces: " << pieces << "\n";
}