#include <iostream>
#include <list>
#include "../../../include/entity/Branch/Branch.hpp"
#include "../../../include/entity/Employee/IEmployee.hpp"

using namespace std;

Branch::Branch(string code, string name):code(code), name(name), employees() {}
Branch::~Branch(){
    for (auto employee : employees) {
        delete employee;
    }
    employees.clear();
}

//■■■■■■■■■■ Getters ■■■■■■■■■■//
string Branch::getCode(){
    return this->code;
}
string Branch::getName(){
    return this->name;
} 
list<IEmployee*> Branch::getEmployees(){
    return this->employees;
}

//■■■■■■■■■■ Setters ■■■■■■■■■■//
void Branch::setCode(string code){
    this->code = code;
}
void Branch::setName(string name){
    this->name = name;
}
void Branch::setEmployees(list<IEmployee*> employees){
    this->employees = employees;
}