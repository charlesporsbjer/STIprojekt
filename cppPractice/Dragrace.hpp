#ifndef RACE_HPP
#define RACE_HPP

#include <vector>

#include "car.hpp"

using namespace std;

class Race {
public:
    Race();

    void start(vector<Car>& participants, int distance);

private:
    vector<double> speeds;
    vector<Car> participants;
    int distance;
};

#endif