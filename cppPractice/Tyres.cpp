#include <iostream>
#include <string>

#include "Tyres.hpp"

using namespace std;

Tyres::Tyres(string brand, string season, int year, int pieces) : brand(brand), season(season), year(year), pieces(pieces) {}

void Tyres::print() const {
    cout << "Tyre specifications: \n" << 
        "Brand: " << brand << "\n" <<
            "Season: " << season << "\n" <<
                "Production year: " << year << "\n" <<
                    "Pieces: " << pieces << "\n";
}
