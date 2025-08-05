#ifndef EMPLOYEE_PARTICULAR_HPP
#define EMPLOYEE_PARTICULAR_HPP

#include <iostream>
#include "IEmployee.hpp"

class EmployeeParticular : public IEmployee
{
public:

    EmployeeParticular(std::string name, std::string lastname, double salary, Branch* branch);
    ~EmployeeParticular();

    //■■■■■■■■■■ Methods ■■■■■■■■■■//
    void work() override;
    void getNotification(std::string message) override;
};

#endif