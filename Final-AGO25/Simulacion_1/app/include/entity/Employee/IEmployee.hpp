#ifndef IEMPLOYEE_HPP
#define IEMPLOYEE_HPP

#include <iostream>
#include "../Branch/Branch.hpp"
#include "Area.hpp"

using namespace std;

class IEmployee
{
private:
    string code;
    string name;
    string lastname;
    double salary;
    AreaType area;
    Branch* branch;

protected:
    string type;
    
public:
    IEmployee(std::string code, std::string name, std::string lastname, double salary, AreaType area, Branch* branch);
    IEmployee();
    ~IEmployee();


//■■■■■■■■■■ Getters ■■■■■■■■■■//
    string getCode();
    string getName();
    string getLastname();
    double getSalary();
    string getAreaType();
    Branch* getBranch();

//■■■■■■■■■■ Setters ■■■■■■■■■■//
    void setCode(string code);
    void setName(string name);
    void setLastname(string lastname);
    void setSalary(double salary);
    void setAreaType(AreaType area);
    void setBranch(Branch* branch);

//■■■■■■■■■■ Methods ■■■■■■■■■■//
    virtual void work() = 0;
    void toString();
};

#endif


