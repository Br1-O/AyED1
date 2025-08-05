#ifndef BRANCH_HPP
#define BRANCH_HPP

#include <iostream>
#include <list>

class IEmployee;

class Branch
{
private:
    std::string code = "1";
    std::string name = "Pinamar";
    std::list<IEmployee*> employees;

public:
    Branch(std::string code, std::string name);
    ~Branch();

//■■■■■■■■■■ Getters ■■■■■■■■■■//
    std::string getCode();
    std::string getName();
    std::list<IEmployee*> getEmployees();

//■■■■■■■■■■ Setters ■■■■■■■■■■//
    void setCode(std::string code);
    void setName(std::string name);
    void setEmployees(std::list<IEmployee*> employees);
};

#endif