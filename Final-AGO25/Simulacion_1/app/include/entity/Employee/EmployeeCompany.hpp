#ifndef EMPLOYEE_COMPANY_HPP
#define EMPLOYEE_COMPANY_HPP

#include <iostream>
#include "IEmployee.hpp"

using namespace std;

class EmployeeCompany : public IEmployee
{
public:

    EmployeeCompany(std::string name, std::string lastname, double salary, Branch* branch);
    EmployeeCompany();
    ~EmployeeCompany();

    //■■■■■■■■■■ Methods ■■■■■■■■■■//
    void work() override;
    void getNotification(string message) override;
};

#endif