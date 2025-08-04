#include <iostream>
#include "IEmployee.hpp"

using namespace std;

class EmployeeProfessional : IEmployee
{
public:

    EmployeeProfessional(std::string code, std::string name, std::string lastname, double salary, AreaType area, Branch* branch);
    EmployeeProfessional();
    ~EmployeeProfessional();

    //■■■■■■■■■■ Methods ■■■■■■■■■■//
    void work() override;

};