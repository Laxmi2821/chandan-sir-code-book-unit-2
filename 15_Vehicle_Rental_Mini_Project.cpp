#include <iostream>
#include <string>
#include <utility>

class Vehicle {
protected:
    std::string registrationNumber;
    double ratePerDay;

public:
    Vehicle(std::string registration, double rate)
        : registrationNumber(std::move(registration)),
          ratePerDay(rate) {}

    virtual void display() const {
        std::cout << "Registration Number: "
                  << registrationNumber << '\n';
        std::cout << "Rate Per Day: "
                  << ratePerDay << '\n';
    }

    virtual double calculateRent(int days) const {
        return ratePerDay * days;
    }

    virtual ~Vehicle() = default;
};

class Car : public Vehicle {
private:
    int doors;

public:
    Car(std::string registration, double rate, int numberOfDoors)
        : Vehicle(std::move(registration), rate),
          doors(numberOfDoors) {}

    void display() const override {
        Vehicle::display();
        std::cout << "Number of Doors: " << doors << '\n';
    }
};

class Bike : public Vehicle {
private:
    int engineCapacity;

public:
    Bike(std::string registration, double rate, int capacity)
        : Vehicle(std::move(registration), rate),
          engineCapacity(capacity) {}

    void display() const override {
        Vehicle::display();
        std::cout << "Engine Capacity: "
                  << engineCapacity << " CC\n";
    }

    double calculateRent(int days) const override {
        return Vehicle::calculateRent(days) * 0.90;
    }
};

int main() {
    Car car("MH12AB1234", 1500, 4);
    Bike bike("MH12CD5678", 800, 150);

    car.display();
    std::cout << "Car Rent for 3 Days: "
              << car.calculateRent(3) << '\n';

    bike.display();
    std::cout << "Bike Rent for 3 Days: "
              << bike.calculateRent(3) << '\n';

    return 0;
}