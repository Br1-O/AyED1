#include <iostream>
#include "../../../include/entity/Employee/EmployeeParticular.hpp"
#include "../../../include/entity/Employee/IEmployee.hpp"

using namespace std;

EmployeeParticular::EmployeeParticular(string name, string lastname, double salary, Branch* branch)
: IEmployee(name, lastname, salary, branch) 
{
    this->type = "particular";
}
EmployeeParticular::~EmployeeParticular(){}

//■■■■■■■■■■ Methods ■■■■■■■■■■//
void EmployeeParticular::work(){
    string workMessage = "El empleado particular llamado " + this->getName() + " " + this->getLastname() + " esta trabajando.";
    cout << workMessage <<endl;
}
void EmployeeParticular::getNotification(string message){
    string generalData = "Recibiste un mensaje por parte de la empresa, " + this->getName() + ": \n";
    cout << "\n------------------------------------------" << endl;
    cout << generalData << "\n" + message + "\n" << "\n Por favor, comunicate con el sector de vendedores particulares para saber mas." << endl;
    cout << "------------------------------------------" << endl;
}