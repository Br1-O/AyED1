#ifndef BRANCH_HPP
#define BRANCH_HPP

#include <iostream>
#include <list>
#include "../../../include/entity/Employee/IEmployee.hpp"

class Branch
{
private:
    string code = "0";
    string name = "Pinamar";
    std::list<IEmployee*> employees = {nullptr};

public:
    Branch(string code, string name):
    code(code), name(name){}
    Branch(){}
    ~Branch(){}

//■■■■■■■■■■ Getters ■■■■■■■■■■//
    string getCode(){
        return this->code;
    }
    string getName(){
        return this->name;
    } 
    std::list<IEmployee*> getEmployees(){
        return this->employees;
    }

//■■■■■■■■■■ Setters ■■■■■■■■■■//
    void setCode(string code){
        this->code = code;
    }
    void setName(string name){
        this->name = name;
    }
    void setEmployees(std::list<IEmployee*> employees){
        this->employees = employees;
    }

//■■■■■■■■■■ Methods ■■■■■■■■■■//
    string toString(){
        string fullData = 
        "Código: " + this->getCode() + "\n " +
        "Nombre: " + this->getName() + "\n" +
        "Empleados: " + "\n";

        return fullData;
    }
};

#endif