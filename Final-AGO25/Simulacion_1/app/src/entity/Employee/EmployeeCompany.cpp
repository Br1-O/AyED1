#include <iostream>
#include "IEmployee.hpp"

using namespace std;

class EmployeeCompany : IEmployee
{
public:

    EmployeeCompany(std::string code, std::string name, std::string lastname, double salary, AreaType area, Branch* branch)
    : IEmployee(code, name, lastname, salary, area, branch) 
    {
        this->type = "compañia";
    }

    EmployeeCompany()
    {
    }

    ~EmployeeCompany()
    {
    }

    //■■■■■■■■■■ Methods ■■■■■■■■■■//
    void work() override{
        string_view workMessage = "El empleado de compañia llamado " + this->getName() + " " + this->getLastname() + " está trabajando.";
        cout << workMessage <<endl;
    }

};