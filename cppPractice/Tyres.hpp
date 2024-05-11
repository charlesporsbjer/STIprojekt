#ifndef TYRES_HPP
#define TYRES_HPP

#include <iostream>
#include <string>

using namespace std;

class Tyres {
private:
    string brand;
    string season;
    int year;
    int pieces;
public:
    Tyres(string brand, string season, int year, int pieces);

    void print() const;
};

#endif