#ifndef EMPLOYEE_PROFESSIONAL_HPP
#define EMPLOYEE_PROFESSIONAL_HPP

#include <iostream>
#include "IEmployee.hpp"

class EmployeeProfessional : public IEmployee
{
public:

    EmployeeProfessional(std::string name, std::string lastname, double salary);
    ~EmployeeProfessional();

    //■■■■■■■■■■ Methods ■■■■■■■■■■//
    void work() override;
    void getNotification(std::string message) override;
};

#endif