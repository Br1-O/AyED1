#ifndef EMPLOYEE_BRANCH_SERVICE_HPP
#define EMPLOYEE_BRANCH_SERVICE_HPP

#include <iostream>
#include "../repository/Repository.hpp"
#include "../entity/Notificator/Notificator.hpp"
#include "../entity/Branch/Branch.hpp"
#include "../entity/Employee/IEmployee.hpp"

class EmployeeBranchService
{
private:
    Repository* repo = nullptr;
    Notificator* notif = nullptr;
public:
    EmployeeBranchService(Repository* repo, Notificator* notif);
    ~EmployeeBranchService();
//■■■■■■■■■■ Methods ■■■■■■■■■■//
    void addEmployee();
    void showAllEmployees();
    void showAllBranches();
    void showEmployeesByBranchCode();
    void sendMessageToOne();
    void sendMessageToBranch();
    void sendMessageToAll();
};

#endif

