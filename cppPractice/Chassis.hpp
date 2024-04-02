#ifndef CHASSIS_HPP
#define CHASSIS_HPP

#include <iostream>
#include <string>

using namespace std;

class Chassis {
private:
    string color;
    string material;
public:
    Chassis(string color, string material);

    void print() const;
};

#endif