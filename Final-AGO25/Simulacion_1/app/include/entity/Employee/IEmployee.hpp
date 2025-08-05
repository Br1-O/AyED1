#ifndef IEMPLOYEE_HPP
#define IEMPLOYEE_HPP

#include <iostream>

class Branch;

class IEmployee
{
private:
    std::string code = "1";
    std::string name = "-";
    std::string lastname = "-";
    double salary = 0.0;
    Branch* branch;

protected:
    std::string type = "-";
    
public:
    IEmployee(std::string name, std::string lastname, double salary, Branch* branch);
    ~IEmployee();

//■■■■■■■■■■ Getters ■■■■■■■■■■//
    std::string getCode();
    std::string getName();
    std::string getLastname();
    double getSalary();
    std::string getType();
    Branch* getBranch();

//■■■■■■■■■■ Setters ■■■■■■■■■■//
    void setCode(std::string code);
    void setName(std::string name);
    void setLastname(std::string lastname);
    void setSalary(double salary);
    void setBranch(Branch* branch);

//■■■■■■■■■■ Methods ■■■■■■■■■■//
    virtual void work() = 0;
    virtual void getNotification(std::string message) = 0;
    std::string toString();
};

#endif


