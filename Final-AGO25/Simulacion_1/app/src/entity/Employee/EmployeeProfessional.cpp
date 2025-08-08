#include <iostream>
#include "../../../include/entity/Employee/EmployeeProfessional.hpp"
#include "../../../include/entity/Employee/IEmployee.hpp"

using namespace std;

EmployeeProfessional::EmployeeProfessional(string name, string lastname, double salary)
: IEmployee(name, lastname, salary) 
{
    this->type = "profesional";
}

EmployeeProfessional::~EmployeeProfessional(){}

//■■■■■■■■■■ Methods ■■■■■■■■■■//
void EmployeeProfessional::work(){
    string workMessage = "El empleado profesional llamado " + this->getName() + " " + this->getLastname() + " esta trabajando.";
    cout << workMessage <<endl;
}
void EmployeeProfessional::getNotification(string message){
    string generalData = "Recibiste un mensaje por parte de la empresa, " + this->getName() + " " + this->getLastname() + ": \n";
    cout << "\n------------------------------------------" << endl;
    cout << generalData << "\n" + message + "\n" << "\n Por favor, comuniquese al sector de vendedores profesionales para saber mas." << endl;
    cout << "------------------------------------------" << endl;
}