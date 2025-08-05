#include <iostream>
#include "../../../include/entity/Employee/EmployeeCompany.hpp"
#include "../../../include/entity/Employee/IEmployee.hpp"

using namespace std;

EmployeeCompany::EmployeeCompany(std::string name, std::string lastname, double salary, Branch* branch)
: IEmployee(name, lastname, salary, branch) 
{
    this->type = "compañia";
}

EmployeeCompany::EmployeeCompany(){}

EmployeeCompany::~EmployeeCompany(){}

//■■■■■■■■■■ Methods ■■■■■■■■■■//
void EmployeeCompany::work(){
    string_view workMessage = "El empleado de compañia llamado " + this->getName() + " " + this->getLastname() + " está trabajando.";
    cout << workMessage <<endl;
}
void EmployeeCompany::getNotification(string message){
    string generalData = "Recibió un mensaje por parte de la empresa, señor " + this->getName() + " " + this->getLastname() + ": \n";
    cout << generalData << message << "\n Por favor, comuniquese al sector de vendedores de compañia de la empresa para saber más." << endl;
}