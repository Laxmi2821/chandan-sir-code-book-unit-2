#include <iostream>
#include <string>
#include <utility>

class Person {
protected:
    std::string name;

public:
    explicit Person(std::string personName)
        : name(std::move(personName)) {}

    void showName() const {
        std::cout << "Name: " << name << '\n';
    }
};

class Student : virtual public Person {
public:
    explicit Student(std::string studentName)
        : Person(std::move(studentName)) {}
};

class Employee : virtual public Person {
public:
    explicit Employee(std::string employeeName)
        : Person(std::move(employeeName)) {}
};

class TeachingAssistant : public Student, public Employee {
public:
    explicit TeachingAssistant(std::string assistantName)
        : Person(std::move(assistantName)),
          Student(assistantName),
          Employee(assistantName) {}
};

int main() {
    TeachingAssistant assistant("Riya");
    assistant.showName();

    return 0;
}