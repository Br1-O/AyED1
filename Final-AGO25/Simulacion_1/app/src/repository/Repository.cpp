#include <iostream>
#include <list>
#include <string>
#include "../../../include/repository/Repository.hpp"
#include "../../../include/entity/Employee/IEmployee.hpp"
#include "../../../include/entity/branch/Branch.hpp"

using namespace std;

Repository::Repository(){}
Repository::~Repository(){}

//■■■■■■■■■■ Methods ■■■■■■■■■■//

IEmployee* Repository::insertEmployee(IEmployee* newEmployee){
    IEmployee* employeeInserted = nullptr;
    string lastEmployeeCode = "";
    
    for (auto &&branch : branchesList)
    {
        if(lastEmployeeCode == "" || stoi(branch->getEmployees().back()->getCode()) > stoi(lastEmployeeCode)){
            lastEmployeeCode = branch->getEmployees().back()->getCode();
        }

        newEmployee->setCode(lastEmployeeCode);
    }

    for (auto &&branch : branchesList)
    {
        if (branch->getCode() == newEmployee->getBranch()->getCode())
        {
            list<IEmployee*> employees = branch->getEmployees();
            employees.push_back(newEmployee);
            branch->setEmployees(employees);
            employeeInserted = branch->getEmployees().back();
        }
    }

    return employeeInserted;
};

Branch* Repository::insertBranch(Branch* newBranch){
    branchesList.push_back(newBranch);
    return branchesList.back();
};

Branch* Repository::getBranchByCode(string branchCode){
    Branch* foundBranch = nullptr;
    for (auto &&branch : branchesList)
    {
        if (branch->getCode() == branchCode)
        {
            foundBranch = branch;
        }
    }
    return foundBranch;
};

IEmployee* Repository::getEmployeeByCode(string employeeCode){
    IEmployee* foundEmployee = nullptr;
    list<IEmployee*> employees = {nullptr};

    for (auto &&branch : branchesList)
    {
        employees = branch->getEmployees();

        for (auto &&employee : employees)
        {
            if (employee->getCode() == employeeCode)
            {
                foundEmployee = employee;
            }
        }
    }
    return foundEmployee;
};

list<Branch*> Repository::getAllBranches(){
    return branchesList;
};

list<IEmployee*> Repository::getEmployeesByBranchName(string branchName){
    list<IEmployee*> employees = {nullptr};

    for (auto &&branch : branchesList)
    {
        if(branch->getName() == branchName){
            employees = branch->getEmployees();
        }
    }
    
    return employees;
};
