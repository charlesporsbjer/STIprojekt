#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <iostream>
#include <string>

using namespace std;

class Engine {
private:
    string fuel;
    float volume;
    char shape;
    int cylinders;
    int horsepower;
public:
    Engine(string fuel, float volume, char shape, int cylinders, int horsepower);

    void print() const;
    int getHorsepower();
};

#endif