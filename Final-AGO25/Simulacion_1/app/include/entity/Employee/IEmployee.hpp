#ifndef IEMPLOYEE_HPP
#define IEMPLOYEE_HPP

#include <iostream>
#include "../Branch/Branch.hpp"

using namespace std;

class IEmployee
{
private:
    string code = "1";
    string name = "-";
    string lastname = "-";
    double salary = 0.0;
    Branch* branch;

protected:
    string type = "-";
    
public:
    IEmployee(std::string name, std::string lastname, double salary, Branch* branch);
    IEmployee();
    ~IEmployee();

//■■■■■■■■■■ Getters ■■■■■■■■■■//
    string getCode();
    string getName();
    string getLastname();
    double getSalary();
    string getType();
    Branch* getBranch();

//■■■■■■■■■■ Setters ■■■■■■■■■■//
    void setCode(string code);
    void setName(string name);
    void setLastname(string lastname);
    void setSalary(double salary);
    void setBranch(Branch* branch);

//■■■■■■■■■■ Methods ■■■■■■■■■■//
    virtual void work() = 0;
    virtual void getNotification(string message) = 0;
    string toString();
};

#endif


