#include <iostream>
#include "../../../include/entity/Employee/EmployeeParticular.hpp"
#include "../../../include/entity/Employee/IEmployee.hpp"

using namespace std;

EmployeeParticular::EmployeeParticular(std::string name, std::string lastname, double salary, Branch* branch)
: IEmployee(name, lastname, salary, branch) 
{
    this->type = "particular";
}
EmployeeParticular::EmployeeParticular(){}
EmployeeParticular::~EmployeeParticular(){}

//■■■■■■■■■■ Methods ■■■■■■■■■■//
void EmployeeParticular::work(){
    string_view workMessage = "El empleado particular llamado " + this->getName() + " " + this->getLastname() + " está trabajando.";
    cout << workMessage <<endl;
}
void EmployeeParticular::getNotification(string message){
    string generalData = "Recibiste un mensaje por parte de la empresa, " + this->getName() + ": \n";
    cout << generalData << message << "\n Por favor, comunicate con el sector de vendedores particulares de la empresa para saber más." << endl;
}