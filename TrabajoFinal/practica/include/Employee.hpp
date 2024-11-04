#if !defined(EMPLOYEE_HPP)
#define EMPLOYEE_HPP

#include <iostream>
#include <string>

class Employee
{
private:
    int id;
    std::string firstName; 
    std::string lastName;
    std::string position;
    double salary;

public:
    //■■■■■■■■■ getters ■■■■■■■■■//
    
    int getId() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getPosition() const;
    double getSalary() const;

    //■■■■■■■■■ setters ■■■■■■■■■//

    void setId(int id);
    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setPosition(const std::string& position);
    void setSalary(double salary);

    //■■■■■■■■■ constructor ■■■■■■■■■//

    Employee();

    Employee(            
        int id,
        const std::string& firstName,
        const std::string& lastName,
        const std::string& position,
        double salary);

    //■■■■■■■■■ destructor ■■■■■■■■■//

    ~Employee(); // Destructor
};

#endif // EMPLOYEE_HPP