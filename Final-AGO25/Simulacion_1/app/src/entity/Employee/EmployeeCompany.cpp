#include <iostream>
#include "../../../include/entity/Employee/EmployeeCompany.hpp"
#include "../../../include/entity/Employee/IEmployee.hpp"

using namespace std;

EmployeeCompany::EmployeeCompany(string name, string lastname, double salary, Branch* branch)
: IEmployee(name, lastname, salary, branch) 
{
    this->type = "empresa";
}

EmployeeCompany::~EmployeeCompany(){}

//■■■■■■■■■■ Methods ■■■■■■■■■■//
void EmployeeCompany::work(){
    string workMessage = "El empleado de empresa llamado " + this->getName() + " " + this->getLastname() + " esta trabajando.";
    cout << workMessage <<endl;
}
void EmployeeCompany::getNotification(string message){
    string generalData = "Recibiste un mensaje por parte de la empresa, " + this->getName() + " " + this->getLastname() + ": \n";
    cout << "\n------------------------------------------" << endl;
    cout << generalData << "\n" + message + "\n" << "\n Por favor, comuniquese al sector de vendedores de empresas para saber mas." << endl;
    cout << "------------------------------------------" << endl;
}