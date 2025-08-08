#include <iostream>
#include <string>
#include "../../include/service/EmployeeBranchService.hpp"
#include "../../include/repository/Repository.hpp"
#include "../../include/entity/Notificator/Notificator.hpp"
#include "../../include/entity/Employee/IEmployee.hpp"
#include "../../include/entity/Employee/EmployeeParticular.hpp"
#include "../../include/entity/Employee/EmployeeProfessional.hpp"
#include "../../include/entity/Employee/EmployeeCompany.hpp"

using namespace std;

EmployeeBranchService::EmployeeBranchService(Repository* repo, Notificator* notif):repo(repo), notif(notif){}
EmployeeBranchService::~EmployeeBranchService(){}
//■■■■■■■■■■ Methods ■■■■■■■■■■//
void EmployeeBranchService::addEmployee(){

    string name, lastname, salary, type, branchCode = "";
    Branch* branch = nullptr;
    IEmployee* newEmployee = nullptr;

    try
    {
        cout << "Por favor, ingrese el nombre del empleado: " <<endl;
        std::getline(cin, name);
        cout << "Por favor, ingrese el apellido del empleado: " <<endl;
        std::getline(cin, lastname);
        cout << "Por favor, ingrese el salario del empleado: " <<endl;
        cin >> salary;
        cin.ignore();
        cout << "Por favor, ingrese el tipo del empleado (0 = particular | 1 = Profesional | 2 = Empresa): " <<endl;
        cin >> type;
        cin.ignore();
        cout << "Por favor, ingrese el codigo de la sucursal del empleado (Pinamar 1 | Miramar 2 | Mar del Plata 3): " <<endl;
        cin >> branchCode;
        cin.ignore();

        branch = repo->getBranchByCode(branchCode);

        if (branch == nullptr) {
            cout << "Error: No existe una sucursal con codigo " << branchCode << endl;
            return;
        }

        double dSalary = stod(salary);
        int iType = stoi(type);

        switch (iType)
        {
        case 0:
            newEmployee = new EmployeeParticular(name, lastname, dSalary);
            break;
        case 1:
            newEmployee = new EmployeeProfessional(name, lastname, dSalary);
            break;
        case 2:
            newEmployee = new EmployeeCompany(name, lastname, dSalary);
            break;
        default:
            newEmployee = new EmployeeParticular(name, lastname, dSalary);
            break;
        }

        repo->insertEmployee(newEmployee, branchCode);
        cout << "\n Empleado agregado correctamente! \n" << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        cout << "\n No se pudo agregar al empleado! \n" << endl;
    }

};

void EmployeeBranchService::showAllEmployees(){
    list<Branch*> branches = repo->getAllBranches();

    for (auto &&branch : branches)
    {
        cout << "\n******************************************" << endl;
        cout << " Sucursal: | " << branch->getName() << " | Codigo: " << branch->getCode() << " |" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Empleados:" << endl;
        cout << "------------------------------------------" << endl;

        list<IEmployee*> employees = branch->getEmployees();
        if (!employees.empty())
        {
            for (auto &&employee : employees)
            {
                cout << employee->toString();
                cout << "\nY el estado de su tarea actual es:" << endl; 
                employee->work();
                cout << "------------------------------------------" << endl;
            }
        }else{
            cout << "No se registran empleados para la sucursal." << endl;
        }

    }
    
};

void EmployeeBranchService::showAllBranches(){
    list<Branch*> branches = repo->getAllBranches();

    cout << "\n---------- Sucursales ----------" << endl;

    for (auto &&branch : branches)
    {
        cout << "| " << branch->getName() << " | Codigo: " << branch->getCode() << " |" << endl;
        cout << "------------------------------------------" << endl;
    }
};

void EmployeeBranchService::showEmployeesByBranchCode(){
    string branchCode;
    Branch* branch = nullptr;

    cout << "\nPor favor, ingrese el codigo de la sucursal (Pinamar 1 | Miramar 2 | Mar del Plata 3): " <<endl;
    cin >> branchCode;
    cin.ignore();

    branch = repo->getBranchByCode(branchCode);

    cout << "\n******************************************" << endl;
    cout << " Sucursal: | " << branch->getName() << " | Codigo: " << branch->getCode() << " |" << endl;
    cout << "------------------------------------------" << endl;
    cout << "Empleados: " << endl;
    cout << "------------------------------------------" << endl;
    

    list<IEmployee*> employees = branch->getEmployees();

    if (!employees.empty())
    {
        for (auto &&employee : employees)
        {
            cout << employee->toString();
            cout << "\nY el estado de su tarea actual es:" << endl; 
            employee->work();
            cout << "------------------------------------------" << endl;
        }
    }else{
        cout << "No se registran empleados para la sucursal." << endl;
    }
};

void EmployeeBranchService::sendMessageToOne(){

    string employeeCode, message = "";

    cout << "\nPor favor, ingrese el codigo del empleado que recibira el mensaje: " <<endl;
    cin >> employeeCode ;
    cin.ignore();

    cout << "\nPor favor, ingrese el mensaje a enviar: " <<endl;
    getline(cin, message);

    IEmployee* employee = repo->getEmployeeByCode(employeeCode);

    if(employee){
        notif->notifyOne(message, employee);
    }else{
        cout << "\nEse usuario no esta registrado." << endl;
    }
};

void EmployeeBranchService::sendMessageToBranch(){

    string branchCode, message = "";

    cout << "\nPor favor, ingrese el codigo de la sucursal que recibira el mensaje: " <<endl;
    cin >> branchCode ;
    cin.ignore();

    cout << "\nPor favor, ingrese el mensaje a enviar: " <<endl;
    getline(cin, message);

    Branch* branch = repo->getBranchByCode(branchCode);

    if(branch){
        list<IEmployee*> employees = branch->getEmployees();
        notif->notifyMany(message, employees);
    }else{
        cout << "\nEsa sucursal no esta registrada." << endl;
    }
};

void EmployeeBranchService::sendMessageToAll(){

    string message = "";

    cout << "\nPor favor, ingrese el mensaje a enviar: " <<endl;
    getline(cin, message);

    list<Branch*> branches = repo->getAllBranches();

    for (auto &&branch : branches)
    {
        list<IEmployee*> employees = branch->getEmployees();
        notif->notifyMany(message, employees);
    }
};