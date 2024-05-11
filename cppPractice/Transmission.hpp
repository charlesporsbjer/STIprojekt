#ifndef TRANSMISSION_HPP
#define TRANSMISSION_HPP

#include <iostream>
#include <string>

using namespace std;

class Transmission {
private:
    int gears;
    string type;
public:
    Transmission(int gears, string type);

    void print() const;
};

#endif