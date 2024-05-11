#include <iostream> 
#include <string>

class Engine {
public:
    Engine(std::string type, int horsepower, int size, std::string fuelType) : type_(type), horsepower_(horsepower), size_(size), fuelType_(fuelType) {}

    void print() {
        std::cout << "Engine Type: " << type_ << std::endl;
        std::cout << "Horsepower: " << horsepower_ << std::endl;
        std::cout << "Engine Size: " << size_ << " liters" << std::endl;
        std::cout << "Fuel Type: " << fuelType_ << std::endl;
    }

    void refuel(int amount) {
        std::cout << "Refueling " << amount << " liters of " << fuelType_ << std::endl;
    }

private:
    std::string type_;
    int horsepower_;
    int size_;
    std::string fuelType_;
};

class Transmission {
public:
    Transmission(int speed, std::string type, double gearRatio) : speed_(speed), type_(type), gearRatio_(gearRatio) {}

    void print() {
        std::cout << "Transmission Speed: " << speed_ << " speed" << std::endl;
        std::cout << "Transmission Type: " << type_ << std::endl;
        std::cout << "Gear Ratio: " << gearRatio_ << std::endl;
    }

    void shiftGear(int gear) {
        std::cout << "Shifting to gear " << gear << std::endl;
    }

private:
    int speed_;
    std::string type_;
    double gearRatio_;
};

class Vehicle {
public:
    Vehicle(std::string make, std::string model, int year, int mileage) : make_(make), model_(model), year_(year), mileage_(mileage) {}

    void print() {
        std::cout << "Make: " << make_ << std::endl;
        std::cout << "Model: " << model_ << std::endl;
        std::cout << "Year: " << year_ << std::endl;
        std::cout << "Mileage: " << mileage_ << " miles" << std::endl;
    }

    void drive(int miles) {
        std::cout << "Driving " << miles << " miles" << std::endl;
        mileage_ += miles;
    }

private:
    std::string make_;
    std::string model_;
    int year_;
    int mileage_;
};

class Car : public Vehicle {
public:
    Car(std::string make, std::string model, int year, int mileage, Engine engine, Transmission transmission, std::string owner) : Vehicle(make, model, year, mileage), engine_(engine), transmission_(transmission), owner_(owner) {}

    void print() {
        Vehicle::print();
        std::cout << "Engine Details:" << std::endl;
        engine_.print();
        std::cout << "Transmission Details:" << std::endl;
        transmission_.print();
        std::cout << "Owner: " << owner_ << std::endl;
    }

    void sell(std::string newOwner) {
        std::cout << "Selling the car to " << newOwner << std::endl;
        owner_ = newOwner;
    }

private:
    Engine engine_;
    Transmission transmission_;
    std::string owner_;
};

int main() {
    Engine engine("V6", 200, 3.0, "Petrol");
    Transmission transmission(5, "Manual", 4.2);
    Car car("Ford", "Cougar", 2001, 50000, engine, transmission, "John Doe");

    car.print();
    car.drive(100);
    car.sell("Jane Doe");
    car.print();

    return 0;
}