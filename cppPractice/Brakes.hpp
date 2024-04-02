#ifndef BRAKES_HPP
#define BRAKES_HPP

#include <string>
#include <iostream>

using namespace std;

class Brakes {
private:
    string brand;
    string type;
    int pieces;
public:
    Brakes(string brand, string type, int pieces);

    void print() const;
};

#endif