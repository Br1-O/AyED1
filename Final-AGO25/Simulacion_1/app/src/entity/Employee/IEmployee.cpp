#include <iostream>
#include <string>
#include "../../../include/entity/Employee/IEmployee.hpp"
#include "../../../include/entity/Branch/Branch.hpp"

using namespace std;

IEmployee::IEmployee(std::string name, std::string lastname, double salary)
: name(name), lastname(lastname), salary(salary) {}
IEmployee::~IEmployee(){}

//■■■■■■■■■■ Getters ■■■■■■■■■■//

string IEmployee::getCode(){
    return this->code;
}
string IEmployee::getName(){
    return this->name;
}
string IEmployee::getLastname(){
    return this->lastname;
}
double IEmployee::getSalary(){
    return this->salary;
}
string IEmployee::getType(){
    return this->type;
}

//■■■■■■■■■■ Setters ■■■■■■■■■■//

void IEmployee::setCode(string code){
    this->code = code;
}
void IEmployee::setName(string name){
    this->name = name;
}
void IEmployee::setLastname(string lastname){
    this->lastname = lastname;
}
void IEmployee::setSalary(double salary){
    this->salary = salary;
}

//■■■■■■■■■■ Methods ■■■■■■■■■■//

string IEmployee::toString(){
    
    string fullData = 
    "Codigo: " + this->getCode() + "\n" +
    "Nombre: " + this->getName() + "\n" +
    "Apellido: " + this->getLastname() + "\n" +
    "Salario: " + to_string(this->getSalary()) + "\n" +
    "Tipo: " + this->getType() + "\n";

    return fullData;
}



