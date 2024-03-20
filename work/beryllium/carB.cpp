#include <iostream> 
#include <string>

class Engine {
public:
    Engine(std::string type, int horsepower) : type_(type), horsepower_(horsepower) {}

    void print() {
        std::cout << "Engine Type: " << type_ << std::endl;
        std::cout << "Horsepower: " << horsepower_ << std::endl;
    }

private:
    std::string type_;
    int horsepower_;
};

class Car {
public:
    Car(std::string make, std::string model, int year, Engine engine) : make_(make), model_(model), year_(year), engine_(engine) {}

    void print() {
        std::cout << "Make: " << make_ << std::endl;
        std::cout << "Model: " << model_ << std::endl;
        std::cout << "Year: " << year_ << std::endl;
        std::cout << "Engine Details:" << std::endl;
        engine_.print();
    }

private:
    std::string make_;
    std::string model_;
    int year_;
    Engine engine_;
};

int main() {
    Engine engine("V6", 200);
    Car car("Ford", "Cougar", 2001, engine);

    car.print();

    return 0;
}