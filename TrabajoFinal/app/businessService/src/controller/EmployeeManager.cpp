#include "../../include/controller/EmployeeManager.hpp"

//■■■■■■■■■ getters ■■■■■■■■■//

std::list<Employee*> EmployeeManager::getEmployees() const {
    return this->employees;
}

//■■■■■■■■■ setters ■■■■■■■■■//

void EmployeeManager::setNewEmployee(Employee* employee) {
    this->employees.push_back(employee);
}

//■■■■■■■■■ constructor ■■■■■■■■■//

EmployeeManager::EmployeeManager() {}

EmployeeManager::EmployeeManager(std::list<Employee*> employees) {
    this->employees = employees;
}

//■■■■■■■■■ destructor ■■■■■■■■■//

EmployeeManager::~EmployeeManager() {
    
    //since my Manager classes are singletons, which are suppose to live through the whole app lifetime they don't implement a default destructor
}

//■■■■■■■■■ methods ■■■■■■■■■//

void EmployeeManager::displayEmployeeList() {
    std::list<Employee*> currentEmployees = this->getEmployees();
    std::string title = "Listado de empleados: ";
    std::string lineSeparator = "---------------------------------";

    std::cout << title << std::endl;

    for (const auto& employee : currentEmployees) {
        std::cout << lineSeparator << std::endl;
        std::cout << "Id: " << employee->getId() << std::endl;
        std::cout << "Nombre: " << employee->getFirstName() << std::endl;
        std::cout << "Apellido: " << employee->getLastName() << std::endl;
        std::cout << "Posicion: " << employee->getPosition() << std::endl;
        std::cout << "Salario: " << employee->getSalary() << std::endl;
        std::cout << lineSeparator << std::endl;
    }

    std::cout << std::endl;
}

Employee EmployeeManager::getEmployeeById(int id) {
    Employee foundEmployee;
    foundEmployee.setId(0);

    const auto& currentEmployees = EmployeeManager::defaultEmployeeManager.getEmployees();
    for (const auto& employee : currentEmployees) {
        if (id == employee->getId()) {
            foundEmployee = *employee;
            break;
        }
    }

    return foundEmployee;
}

Employee* EmployeeManager::loadNewEmployee() {
    int id;
    std::string firstName, lastName, position;
    double salary;

    Employee* newEmployee = nullptr;

    std::cout << "Por favor, ingrese el nombre del nuevo empleado: " << std::endl;
    getline(std::cin, firstName);

    std::cout << "Por favor, ingrese el apellido del nuevo empleado: " << std::endl;
    getline(std::cin, lastName);

    std::cout << "Por favor, ingrese la posición del nuevo empleado: " << std::endl;
    getline(std::cin, position);

    std::cout << "Ingrese el salario del nuevo empleado: " << std::endl;
    std::cin >> salary;
    std::cin.ignore();

    try {
        // Create new ID
        std::list<Employee*> currentEmployees = this->getEmployees();
        id = currentEmployees.empty() ? 1 : (currentEmployees.back())->getId() + 1;

        // Generate new employee
        newEmployee = new Employee(id, firstName, lastName, position, salary);

        // Save it into manager class
        this->setNewEmployee(newEmployee);

        std::cout << std::endl << "Empleado agregado correctamente." << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        std::cout << "No se ha podido crear el nuevo empleado por esta razon." << std::endl;
        if (newEmployee) delete newEmployee;
    }

    return newEmployee;
}

//■■■■■■■■■ default instance ■■■■■■■■■//

EmployeeManager EmployeeManager::defaultEmployeeManager;