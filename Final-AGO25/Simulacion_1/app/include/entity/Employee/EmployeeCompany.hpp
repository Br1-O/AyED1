#include <iostream>
#include "IEmployee.hpp"

using namespace std;

class EmployeeCompany : IEmployee
{
public:

    EmployeeCompany(std::string code, std::string name, std::string lastname, double salary, AreaType area, Branch* branch);
    EmployeeCompany();
    ~EmployeeCompany();

    //■■■■■■■■■■ Methods ■■■■■■■■■■//
    void work() override;

};