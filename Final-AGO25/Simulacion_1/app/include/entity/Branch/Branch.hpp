#ifndef BRANCH_HPP
#define BRANCH_HPP

#include <iostream>
#include <list>
#include "../Employee/IEmployee.hpp"

class Branch
{
private:
    string code;
    string name;
    std::list<IEmployee*> employees = {nullptr};

public:
    Branch(string code, string name);
    Branch();
    ~Branch();

//■■■■■■■■■■ Getters ■■■■■■■■■■//
    string getCode();
    string getName();
    std::list<IEmployee*> getEmployees();

//■■■■■■■■■■ Setters ■■■■■■■■■■//
    void setCode(string code);
    void setName(string name);
    void setEmployees(std::list<IEmployee*> employees);

//■■■■■■■■■■ Methods ■■■■■■■■■■//
    string toString();
};

#endif