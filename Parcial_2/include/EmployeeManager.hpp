#if !defined(EMPLOYEEMANAGER_HPP)
#define EMPLOYEEMANAGER_HPP

#include <iostream>
#include <list>
#include <string>
#include "./Employee.hpp"

class EmployeeManager
{
private:
    std::list<Employee*> employees; // List of employees

public:
    //■■■■■■■■■ getters ■■■■■■■■■//

    std::list<Employee*> getEmployees() const; // Get list of employees

    //■■■■■■■■■ setters ■■■■■■■■■//

    void setNewEmployee(Employee* employee); // Add a new employee

    //■■■■■■■■■ constructor ■■■■■■■■■//

    EmployeeManager(); // Default constructor
    EmployeeManager(std::list<Employee*> employees); // Parameterized constructor

    //■■■■■■■■■ destructor ■■■■■■■■■//

    ~EmployeeManager(); // Destructor

    //■■■■■■■■■ methods ■■■■■■■■■//

    void displayEmployeeList(); // Display the list of employees
    Employee getEmployeeById(int id); // Get employee by ID
    Employee* loadNewEmployee(); // Load a new employee

    //■■■■■■■■■ default instance ■■■■■■■■■//

    static EmployeeManager defaultEmployeeManager;
};

#endif // EMPLOYEEMANAGER_HPP