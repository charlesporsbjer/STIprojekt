#include <iostream>
#include <string>

class Vehicle {
public:
    Vehicle(std::string make, std::string model, int year) : make_(make), model_(model), year_(year) {}

    void print() {
        std::cout << "Make: " << make_ << std::endl;
        std::cout << "Model: " << model_ << std::endl;
        std::cout << "Year: " << year_ << std::endl;
    }

private:
    std::string make_;
    std::string model_;
    int year_;
};

class Engine {
public:
    Engine(std::string type, int horsepower, int engineSize) : type_(type), horsepower_(horsepower), engineSize_(engineSize) {}

    void print() {
        std::cout << "Engine Type: " << type_ << std::endl;
        std::cout << "Horsepower: " << horsepower_ << std::endl;
        std::cout << "Engine Size: " << engineSize_ << " liters" << std::endl;
    }

private:
    std::string type_;
    int horsepower_;
    int engineSize_;
};

class Transmission {
public:
    Transmission(std::string type, int numGears) : type_(type), numGears_(numGears) {}

    void print() {
        std::cout << "Transmission Type: " << type_ << std::endl;
        std::cout << "Number of Gears: " << numGears_ << std::endl;
    }

private:
    std::string type_;
    int numGears_;
};

class Car : public Vehicle {
public:
    Car(std::string make, std::string model, int year, Engine engine, Transmission transmission) : Vehicle(make, model, year), engine_(engine), transmission_(transmission) {}

    void print() {
        Vehicle::print();
        std::cout << "Engine Details:" << std::endl;
        engine_.print();
        std::cout << "Transmission Details:" << std::endl;
        transmission_.print();
    }

private:
    Engine engine_;
    Transmission transmission_;
};

int main() {
    Engine engine("V6", 200, 3500);
    Transmission transmission("5-speed manual", 5);
    Car car("Ford", "Cougar", 2001, engine, transmission);

    car.print();

    return 0;
}