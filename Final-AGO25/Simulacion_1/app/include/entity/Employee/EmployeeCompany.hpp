#ifndef EMPLOYEE_COMPANY_HPP
#define EMPLOYEE_COMPANY_HPP

#include <iostream>
#include "IEmployee.hpp"

class EmployeeCompany : public IEmployee
{
public:
    EmployeeCompany(std::string name, std::string lastname, double salary, Branch* branch);
    ~EmployeeCompany();

    //■■■■■■■■■■ Methods ■■■■■■■■■■//
    void work() override;
    void getNotification(std::string message) override;
};

#endif