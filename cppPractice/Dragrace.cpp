#include "Dragrace.hpp"
#include <iostream>

#include <vector>

using namespace std;

Race::Race() {}

void Race::start(vector<Car>& participants, int distance) {
    int fastest = 0;
    double time;
    vector<double> times;
    // Get participants speeds and find fastest.
    for (size_t i = 0; i < participants.size(); i++) {
        cout << "Participants are: \n";
        cout << "Car #" << i << " " << participants[i].getModel() << ". \n";
        speeds.push_back(participants[i].calculateSpeed());
        times.push_back((double)distance / speeds[i]);
        cout << "Participant no. " << i << " got " << times[i] << "\n"; 
    }
}