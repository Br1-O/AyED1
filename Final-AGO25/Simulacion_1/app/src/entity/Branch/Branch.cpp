#ifndef BRANCH_HPP
#define BRANCH_HPP

#include <iostream>
#include <vector>
#include "../Employee/IEmployee.hpp"

class Branch
{
private:
    string code = "S-000";
    string name = "Pinamar";
    std::vector<IEmployee*> employees = {};
    string address = "";

public:
    Branch(string code, string name, std::vector<IEmployee*> employees, string address):
    code(code), name(name), employees(employees), address(address){}
    Branch(){}
    ~Branch(){}

//■■■■■■■■■■ Getters ■■■■■■■■■■//
    string getCode(){
        return this->code;
    }
    string getName(){
        return this->name;
    } 
    std::vector<IEmployee*> getEmployees(){
        return this->employees;
    }
    string getAddress(){
        return this->address;
    }

//■■■■■■■■■■ Setters ■■■■■■■■■■//
    void setCode(string code){
        this->code = code;
    }
    void setName(string name){
        this->name = name;
    }
    void setEmployees(std::vector<IEmployee*> employees){
        this->employees = employees;
    }
    void setAddress(string address){
        this->address = address;
    }

//■■■■■■■■■■ Methods ■■■■■■■■■■//
    string toString(){
        string fullData = 
        "Código: " + this->getCode() + "\n " +
        "Nombre: " + this->getName() + "\n" +
        "Dirección: " + this->getAddress() + "\n" +
        "Empleados: " + "\n";

        return fullData;
    }
};

#endif