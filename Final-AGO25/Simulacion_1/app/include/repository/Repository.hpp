#ifndef REPOSITORY_HPP
#define REPOSITORY_HPP

#include <iostream>
#include <list>
#include "../entity/Employee/IEmployee.hpp"
#include "../entity/Branch/Branch.hpp"

class Repository
{
private:
    std::list<Branch*> branchesList;
public:
    Repository();
    ~Repository();
//■■■■■■■■■■ Methods ■■■■■■■■■■//
    IEmployee* insertEmployee(IEmployee* newEmployee);
    Branch* insertBranch(Branch* newBranch);
    IEmployee* getEmployeeByCode(std::string employeeCode);
    Branch* getBranchByCode(std::string branchCode);
    std::list<Branch*> getAllBranches();
    std::list<IEmployee*> getEmployeesByBranchName(std::string branchName);
};

#endif