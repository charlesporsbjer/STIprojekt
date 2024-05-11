#include "car.hpp"
#include "Engine.hpp"
#include "Chassis.hpp"
#include "Transmission.hpp"
#include "Tyres.hpp"
#include "Brakes.hpp"
#include "Dragrace.hpp"

#include <vector>

using namespace std;

// TODO: Make a Driver class that have different skillsets and reliability in their driving. And add them as arguments to the Race method.

int main() {
    Chassis blackSteel("Black", "Steel/Plastic");
    Engine v6("Petrol", 2.5, 'V', 6, 170);
    Transmission manual5(5, "Manual");
    Tyres summerTyres("Michelin", "Summer", 1999, 4);
    Brakes brembos("Brembo", "Disc", 4);
    Car cougar("Charlie", "Car", "Ford", 2001, blackSteel, summerTyres, brembos, "Cougar", "Coupe", "FWD", v6, manual5, 1405, 490255, 50, 45.5, 1.2);
    
    vector<Car> cars {cougar};

    Race a1;

    cougar.print();

    cougar.drive(200);
    
    cougar.refuel(20);

    a1.start(cars, 10000);

    return 0;
}