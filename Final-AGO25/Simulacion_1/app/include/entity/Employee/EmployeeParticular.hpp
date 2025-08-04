#ifndef EMPLOYEE_PARTICULAR_HPP
#define EMPLOYEE_PARTICULAR_HPP

#include <iostream>
#include "IEmployee.hpp"

using namespace std;

class EmployeeParticular : IEmployee
{
public:

    EmployeeParticular(std::string code, std::string name, std::string lastname, double salary, AreaType area, Branch* branch);
    EmployeeParticular();
    ~EmployeeParticular();

    //■■■■■■■■■■ Methods ■■■■■■■■■■//
    void work() override;

};

#endif