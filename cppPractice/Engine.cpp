#include <iostream>
#include <string>

#include "Engine.hpp"

using namespace std;

Engine::Engine(string fuel, float volume, char shape, int cylinders, int horsepower)
    : fuel(fuel), volume(volume), shape(shape), cylinders(cylinders), horsepower(horsepower) {
}

void Engine::print() const {
    cout << "Engine specifications: \n" << 
        "Fuel type: " << fuel << "\n" <<
            "Volume: " << volume << "\n" <<
                "Shape: " << shape << "\n" <<
                    "Cylinders: " << cylinders << "\n"
                        "Horsepower: " << horsepower << "\n";
}

int Engine::getHorsepower() { return horsepower; }
