#include <iostream>
#include <string>

class Driver {
public:
    Driver(std::string name, int skillLevel) : name(name), skillLevel(skillLevel) {}

    std::string getName() const {
        return name;
    }

    int getSkillLevel() const {
        return skillLevel;
    }

private:
    std::string name;
    int skillLevel;
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

    Driver& getDriver() {
        return driver;
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

            if (rand() % 2 == 0 && car1.getSpeed() > car1.getDriver().getSkillLevel()) {
                car1.brake();
            }

            if (rand() % 2 == 0 && car2.getSpeed() > car2.getDriver().getSkillLevel()) {
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
    Driver driver1("John Doe", 50);
    Driver driver2("Jane Doe", 70);

    // Create two cars with drivers
    Car car1("Toyota", "Corolla", 2015, 0, driver1);
    Car car2("Honda", "Civic", 2010, 0, driver2);

    // Pit the two cars against each other
    Race race(car1, car2);
    race.start();

    return 0;
}