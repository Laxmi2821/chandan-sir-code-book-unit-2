#include <iostream>
#include <string>
#include <utility>

class Employee {
protected:
    std::string name;
    double salary;

public:
    Employee(std::string employeeName, double employeeSalary)
        : name(std::move(employeeName)),
          salary(employeeSalary) {}

    virtual void displaySalary() const = 0;

    virtual ~Employee() = default;
};

class PermanentEmployee : public Employee {
public:
    PermanentEmployee(std::string employeeName, double employeeSalary)
        : Employee(std::move(employeeName), employeeSalary) {}

    void displaySalary() const override {
        std::cout << "Permanent Employee: " << name << '\n';
        std::cout << "Salary: " << salary << '\n';
    }
};

class ContractEmployee : public Employee {
public:
    ContractEmployee(std::string employeeName, double employeeSalary)
        : Employee(std::move(employeeName), employeeSalary) {}

    void displaySalary() const override {
        std::cout << "Contract Employee: " << name << '\n';
        std::cout << "Salary: " << salary << '\n';
    }
};

int main() {
    PermanentEmployee permanent("Rahul", 48000);
    ContractEmployee contract("Amit", 40000);

    permanent.displaySalary();
    contract.displaySalary();

    return 0;
}