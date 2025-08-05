#ifndef REPOSITORY_HPP
#define REPOSITORY_HPP

#include <iostream>
#include <list>
#include "../../entity/Employee/IEmployee.hpp"
#include "../../entity/Branch/Branch.hpp"

using namespace std;

class Repository
{
private:
    list<Branch*> branchesList = {nullptr};
public:
    Repository();
    ~Repository();
//■■■■■■■■■■ Methods ■■■■■■■■■■//
    IEmployee* insertEmployee(IEmployee* newEmployee);
    Branch* insertBranch(Branch* newBranch);
    IEmployee* getEmployeeByCode(string employeeCode);
    Branch* getBranchByCode(string branchCode);
    list<Branch*> getAllBranches();
    list<IEmployee*> getEmployeesByBranchName(string branchName);
};

#endif