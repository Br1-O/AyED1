#include <iostream>
#include "IEmployee.hpp"

using namespace std;

class EmployeeProfessional : IEmployee
{
public:

    EmployeeProfessional(std::string code, std::string name, std::string lastname, double salary, AreaType area, Branch* branch)
    : IEmployee(code, name, lastname, salary, area, branch) 
    {
        this->type = "profesional";
    }

    EmployeeProfessional()
    {
    }

    ~EmployeeProfessional()
    {
    }

    //■■■■■■■■■■ Methods ■■■■■■■■■■//
    void work() override{
        string_view workMessage = "El empleado particular llamado " + this->getName() + " " + this->getLastname() + " está trabajando.";
        cout << workMessage <<endl;
    }

};