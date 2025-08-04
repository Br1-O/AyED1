#ifndef BRANCH_HPP
#define BRANCH_HPP

#include <iostream>
#include <vector>
#include "../Employee/IEmployee.hpp"

class Branch
{
private:
    string code;
    string name;
    std::vector<IEmployee*> employees;
    string address;

public:
    Branch(string code, string name, std::vector<IEmployee*> employees, string address);
    Branch();
    ~Branch();

//■■■■■■■■■■ Getters ■■■■■■■■■■//
    string getCode();
    string getName();
    std::vector<IEmployee*> getEmployees();
    string getAddress();

//■■■■■■■■■■ Setters ■■■■■■■■■■//
    void setCode(string code);
    void setName(string name);
    void setEmployees(std::vector<IEmployee*> employees);
    void setAddress(string address);

//■■■■■■■■■■ Methods ■■■■■■■■■■//
    string toString();
};

#endif