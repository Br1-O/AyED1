#ifndef EMPLOYEE_PROFESSIONAL_HPP
#define EMPLOYEE_PROFESSIONAL_HPP

#include <iostream>
#include "IEmployee.hpp"

using namespace std;

class EmployeeProfessional : public IEmployee
{
public:

    EmployeeProfessional(std::string name, std::string lastname, double salary, Branch* branch);
    EmployeeProfessional();
    ~EmployeeProfessional();

    //■■■■■■■■■■ Methods ■■■■■■■■■■//
    void work() override;
    void getNotification(string message) override;
};

#endif