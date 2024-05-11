#include <iostream>
#include <string>

class Driver {
public:
    Driver(std::string name, int aggressiveness) : name(name), aggressiveness(aggressiveness) {}

    std::string getName() const {
        return name;
    }

    int getAggressiveness() const {
        return aggressiveness;
    }

private:
    std::string name;
    int aggressiveness;
};

class Car {
public:
    Car(std::string make, std::string model, int year, int speed, Driver& driver) : make(make), model(model), year(year), speed(speed), driver(driver) {}

    std::string getMake() const {
        return make;
    }

    std::string getModel() const {
        return model;
    }

    int getYear() const {
        return year;
    }

    int getSpeed() const {
        return speed;
    }

    void accelerate() {
        speed += 10;
    }

    void brake() {
        if (speed < 10) {
            speed = 0;
        } else {
            speed -= 10;
        }
    }

    void honk() {
        std::cout << "Honk! Honk!" << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Car& car) {
        os << car.make << " " << car.model << " (" << car.year << ") driven by " << car.driver.getName();
        return os;
    }

private:
    std::string make;
    std::string model;
    int year;
    int speed;
    Driver& driver;
};

class Race {
public:
    Race(Car& car1, Car& car2) : car1(car1), car2(car2) {}

    void start() {
        while (car1.getSpeed() < 100 && car2.getSpeed() < 100) {
            std::cout << "Car 1: " << car1 << ", speed: " << car1.getSpeed() << std::endl;
            std::cout << "Car 2: " << car2 << ", speed: " << car2.getSpeed() << std::endl;

            car1.accelerate();
            car2.accelerate();

            if (rand() % 2 == 0 && car1.driver.getAggressiveness() > 5) {
                car1.brake();
            }

            if (rand() % 2 == 0 && car2.driver.getAggressiveness() > 5) {
                car2.brake();
            }

            std::cout << std::endl;
        }

        if (car1.getSpeed() >= 100) {
            std::cout << "Car 1 wins!" << std::endl;
        } else {
            std::cout << "Car 2 wins!" << std::endl;
        }
    }

private:
    Car& car1;
    Car& car2;
};

int main() {
    // Create two drivers
    Driver driver1("John", 7);
    Driver driver2("Emily", 3);

    // Create two cars with the drivers
    Car car1("Toyota", "Corolla", 2015, 0, driver1);
    Car car2("Honda", "Civic", 2010, 0, driver2);

    // Pit the two cars against each other
    Race race(car1, car2);
    race.start();

    return 0;
}