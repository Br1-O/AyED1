#ifndef EMPLOYEE_PARTICULAR_HPP
#define EMPLOYEE_PARTICULAR_HPP

#include <iostream>
#include "IEmployee.hpp"

using namespace std;

class EmployeeParticular : public IEmployee
{
public:

    EmployeeParticular(std::string name, std::string lastname, double salary, Branch* branch);
    EmployeeParticular();
    ~EmployeeParticular();

    //■■■■■■■■■■ Methods ■■■■■■■■■■//
    void work() override;
    void getNotification(string message) override;
};

#endif