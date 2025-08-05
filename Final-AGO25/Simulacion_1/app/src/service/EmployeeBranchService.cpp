#include <iostream>
#include <string>
#include "../../include/service/EmployeeBranchService.hpp"
#include "../../include/repository/Repository.hpp"
#include "../../include/entity/Notificator/Notificator.hpp"
#include "../../include/entity/Employee/IEmployee.hpp"
#include "../../include/entity/Employee/EmployeeParticular.hpp"
#include "../../include/entity/Employee/EmployeeProfessional.hpp"
#include "../../include/entity/Employee/EmployeeCompany.hpp"


EmployeeBranchService::EmployeeBranchService(Repository* repo, Notificator* notif):repo(repo), notif(notif){}
EmployeeBranchService::~EmployeeBranchService(){}
//■■■■■■■■■■ Methods ■■■■■■■■■■//
bool EmployeeBranchService::addEmployee(){

    string name, lastname, salary, type, branchCode = "";
    Branch* branch = nullptr;
    IEmployee* newEmployee = nullptr;

    cout << "Por favor, ingrese el nombre del empleado: " <<endl;
    std::getline(cin, name);
    cout << "Por favor, ingrese el apellido del empleado: " <<endl;
    std::getline(cin, lastname);
    cout << "Por favor, ingrese el salario del empleado: " <<endl;
    std::getline(cin, salary);
    cout << "Por favor, ingrese el tipo del empleado (0 = particular - 1 = Profesional - 2 = Compañia): " <<endl;
    std::getline(cin, type);
    cout << "Por favor, ingrese el código de la sucursal del empleado (Pinamar 1 - Miramar 2 - Mar del Plata 3): " <<endl;
    std::getline(cin, branchCode);

    branch = repo->getBranchByCode(branchCode);
    double dSalary = stod(salary);
    int iType = stoi(type);

    switch (iType)
    {
    case 0:
        newEmployee = new EmployeeParticular(name, lastname, dSalary, branch);
        break;
    case 1:
        newEmployee = new EmployeeProfessional(name, lastname, dSalary, branch);
        break;
    case 2:
        newEmployee = new EmployeeCompany(name, lastname, dSalary, branch);
        break;
    default:
        newEmployee = new EmployeeParticular(name, lastname, dSalary, branch);
        break;
    }

    repo->insertEmployee(newEmployee);
};

void EmployeeBranchService::showAllEmployees(){
    list<Branch*> branches = repo->getAllBranches();

    for (auto &&branch : branches)
    {
        cout << "\n════════════════════════════════════════════" << endl;
        cout << " Sucursal: | " << branch->getName() << " | Código: " << branch->getCode() << " |" << endl;
        cout << "════════════════════════════════════════════" << endl;
        cout << "Empleados: " << endl;

        list<IEmployee*> employees = branch->getEmployees();
        for (auto &&employee : employees)
        {
            employee->toString();
            cout << "\n y el estado de su tarea actual es:" << endl; 
            employee->work();
            cout << "════════════════════════════════════════════" << endl;
        }
    }
    
};

void EmployeeBranchService::showAllBranches(){
    list<Branch*> branches = repo->getAllBranches();

    cout << "\n═══════════════════ Sucursales ═════════════════════════" << endl;

    for (auto &&branch : branches)
    {
        cout << "| " << branch->getName() << " | Código: " << branch->getCode() << " |" << endl;
        cout << "════════════════════════════════════════════" << endl;
    }
};

void EmployeeBranchService::showEmployeesByBranchCode(){
    string branchCode;
    Branch* branch = nullptr;

    cout << "Por favor, ingrese el código de la sucursal (Pinamar 1 - Miramar 2 - Mar del Plata 3): " <<endl;
    cin >> branchCode;

    branch = repo->getBranchByCode(branchCode);

    cout << "\n════════════════════════════════════════════" << endl;
    cout << " Sucursal: | " << branch->getName() << " | Código: " << branch->getCode() << " |" << endl;
    cout << "════════════════════════════════════════════" << endl;
    cout << "Empleados: " << endl;

    list<IEmployee*> employees = branch->getEmployees();
    for (auto &&employee : employees)
    {
        employee->toString();
        cout << "\n y el estado de su tarea actual es:" << endl; 
        employee->work();
        cout << "════════════════════════════════════════════" << endl;
    }
};

void EmployeeBranchService::sendMessageToOne(){

    string employeeCode, message = "";

    cout << "Por favor, ingrese el código del empleado que recibirá el mensaje: " <<endl;
    cin >> employeeCode ;

    cout << "Por favor, ingrese el mensaje a enviar: " <<endl;
    getline(cin, message);

    IEmployee* employee = repo->getEmployeeByCode(employeeCode);

    if(employee){
        notif->notifyOne(message, employee);
    }
};

void EmployeeBranchService::sendMessageToBranch(){

    string branchCode, message = "";

    cout << "Por favor, ingrese el código de la sucursal que recibirá el mensaje: " <<endl;
    cin >> branchCode ;

    cout << "Por favor, ingrese el mensaje a enviar: " <<endl;
    getline(cin, message);

    Branch* branch = repo->getBranchByCode(branchCode);

    if(branch){
        list<IEmployee*> employees = branch->getEmployees();
        notif->notifyMany(message, employees);
    }
};

void EmployeeBranchService::sendMessageToAll(){

    string message = "";

    cout << "Por favor, ingrese el mensaje a enviar: " <<endl;
    getline(cin, message);

    list<Branch*> branches = repo->getAllBranches();

    for (auto &&branch : branches)
    {
        list<IEmployee*> employees = branch->getEmployees();
        notif->notifyMany(message, employees);
    }
};