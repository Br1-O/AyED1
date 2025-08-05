#include <iostream>
#include <list>
#include <string>
#include "../../include/repository/Repository.hpp"
#include "../../include/entity/Employee/IEmployee.hpp"
#include "../../include/entity/branch/Branch.hpp"

using namespace std;

Repository::Repository():branchesList(){}
Repository::~Repository(){}

//■■■■■■■■■■ Methods ■■■■■■■■■■//

IEmployee* Repository::insertEmployee(IEmployee* newEmployee){
    IEmployee* employeeInserted = nullptr;
    int maxCode = 0;

    try
    {
        //code auto generation 
        for (auto &&branch : branchesList) {
            if (branch != nullptr && !branch->getEmployees().empty()) {
                int code = stoi(branch->getEmployees().back()->getCode());
                if (code > maxCode) {
                    maxCode = code;
                }
            }
        }

        string newCode = to_string(maxCode + 1);
        newEmployee->setCode(newCode);

        //insert into proper branch list of employees
        for (auto &&branch : branchesList) {
            if (
                branch != nullptr && 
                newEmployee != nullptr &&
                newEmployee->getBranch() != nullptr &&
                branch->getCode() == newEmployee->getBranch()->getCode()
            ) {
                list<IEmployee*> employees = branch->getEmployees();
                employees.push_back(newEmployee);
                branch->setEmployees(employees);
                employeeInserted = newEmployee;
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return employeeInserted;
};

Branch* Repository::insertBranch(Branch* newBranch){
    Branch * branchAdded = nullptr;
    try
    {
        branchesList.push_back(newBranch);
        branchAdded = branchesList.back();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return branchAdded;
};

Branch* Repository::getBranchByCode(string branchCode){
    Branch* foundBranch = nullptr;
    for (auto &&branch : branchesList)
    {
        if (branch != nullptr && branch->getCode() == branchCode)
        {
            foundBranch = branch;
        }
    }
    return foundBranch;
};

IEmployee* Repository::getEmployeeByCode(string employeeCode){
    IEmployee* foundEmployee = nullptr;
    list<IEmployee*> employees;

    for (auto &&branch : branchesList)
    {
        employees = branch->getEmployees();

        for (auto &&employee : employees)
        {
            if (employee != nullptr && employee->getCode() == employeeCode)
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
    list<IEmployee*> employees;

    for (auto &&branch : branchesList)
    {
        if(branch != nullptr && branch->getName() == branchName){
            employees = branch->getEmployees();
        }
    }
    
    return employees;
};
