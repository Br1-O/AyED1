#include "../../include/Employee.hpp"

//■■■■■■■■■ getters ■■■■■■■■■//

int Employee::getId() const {
    return id;
}

std::string Employee::getFirstName() const {
    return firstName;
}

std::string Employee::getLastName() const {
    return lastName;
}

std::string Employee::getPosition() const {
    return position;
}

double Employee::getSalary() const {
    return salary;
}

//■■■■■■■■■ setters ■■■■■■■■■//

void Employee::setId(int id) {
    this->id = id;
}

void Employee::setFirstName(const std::string& firstName) {
    this->firstName = firstName;
}

void Employee::setLastName(const std::string& lastName) {
    this->lastName = lastName;
}

void Employee::setPosition(const std::string& position) {
    this->position = position;
}

void Employee::setSalary(double salary) {
    this->salary = salary;
}

//■■■■■■■■■ constructors ■■■■■■■■■//

Employee::Employee() {}

Employee::Employee(int id, const std::string& firstName, const std::string& lastName, const std::string& position, double salary) {
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
    this->position = position;
    this->salary = salary;
}

//■■■■■■■■■ destructor ■■■■■■■■■//

Employee::~Employee() {}