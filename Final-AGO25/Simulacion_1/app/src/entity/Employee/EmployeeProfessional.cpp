#include <iostream>
#include "../../../include/entity/Employee/EmployeeProfessional.hpp"
#include "../../../include/entity/Employee/IEmployee.hpp"

using namespace std;

EmployeeProfessional::EmployeeProfessional(std::string name, std::string lastname, double salary, Branch* branch)
: IEmployee(name, lastname, salary, branch) 
{
    this->type = "profesional";
}

EmployeeProfessional::EmployeeProfessional(){}

EmployeeProfessional::~EmployeeProfessional(){}

//■■■■■■■■■■ Methods ■■■■■■■■■■//
void EmployeeProfessional::work(){
    string_view workMessage = "El empleado particular llamado " + this->getName() + " " + this->getLastname() + " está trabajando.";
    cout << workMessage <<endl;
}
void EmployeeProfessional::getNotification(string message){
    string generalData = "Recibió un mensaje por parte de la empresa, señor " + this->getName() + " " + this->getLastname() + ": \n";
    cout << generalData << message << "\n Por favor, comuniquese al sector de vendedores profesionales de la empresa para saber más." << endl;
}