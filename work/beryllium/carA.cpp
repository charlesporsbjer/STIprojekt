#include <iostream>
#include <string>

class Car {
public:
    Car(std::string make, std::string model, int year) : make(make), model(model), year(year) {}

    void print() {
        std::cout << "Make: " << make << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Year: " << year << std::endl;
    }

protected:
    std::string make;
    std::string model;
    int year;
};

class Engine {
public:
    Engine(int horsepower, int torque, std::string type) : horsepower(horsepower), torque(torque), type(type) {}

    void print() {
        std::cout << "Horsepower: " << horsepower << std::endl;
        std::cout << "Torque: " << torque << std::endl;
        std::cout << "Type: " << type << std::endl;
    }

protected:
    int horsepower;
    int torque;
    std::string type;
};

class Transmission {
public:
    Transmission(int gears, std::string type) : gears(gears), type(type) {}

    void print() {
        std::cout << "Gears: " << gears << std::endl;
        std::cout << "Type: " << type << std::endl;
    }

protected:
    int gears;
    std::string type;
};

class Chassis {
public:
    Chassis(std::string material, int weight) : material(material), weight(weight) {}

    void print() {
        std::cout << "Material: " << material << std::endl;
        std::cout << "Weight: " << weight << std::endl;
    }

protected:
    std::string material;
    int weight;
};

int main() {
    Car car("Ford", "Cougar", 2001);
    Engine engine(260, 250, "V6");
    Transmission transmission(5, "Automatic");
    Chassis chassis("Aluminum", 1300);

    car.print();
    std::cout << std::endl;
    engine.print();
    std::cout << std::endl;
    transmission.print();
    std::cout << std::endl;
    chassis.print();

    return 0;
}