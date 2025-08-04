#include <iostream>
#include <string>
#include "../../../include/entity/Branch/Branch.hpp"
#include "../../../include/entity/Employee/Area.hpp"

using namespace std;

class IEmployee
{
private:
    string code = "E-000";
    string name = "-";
    string lastname = "-";
    double salary = 0.0;
    AreaType area = AreaType::VENTAS;
    Branch* branch;

protected:
    string type = "-";
    
public:
    IEmployee(std::string code, std::string name, std::string lastname, double salary, AreaType area, Branch* branch)
    : code(code), name(name), lastname(lastname), salary(salary), area(area), branch(branch) {}

    IEmployee()
    {
    }

    ~IEmployee()
    {
    }
//■■■■■■■■■■ Getters ■■■■■■■■■■//
    string getCode(){
        return this->code;
    }
    string getName(){
        return this->name;
    }
    string getLastname(){
        return this->lastname;
    }
    double getSalary(){
        return this->salary;
    }
    string getAreaType(){
        return areaName(this->area);
    }
    string getType(){
        return this->type;
    }
    Branch* getBranch(){
        return this->branch;
    }

//■■■■■■■■■■ Setters ■■■■■■■■■■//
    void setCode(string code){
        this->code = code;
    }
    void setName(string name){
        this->name = name;
    }
    void setLastname(string lastname){
        this->lastname = lastname;
    }
    void setSalary(double salary){
        this->salary = salary;
    }
    void setAreaType(AreaType area){
        this->area = area;
    }
    void setBranch(Branch* branch){
        this->branch = branch;
    }

//■■■■■■■■■■ Methods ■■■■■■■■■■//
    virtual void work() = 0;
    string toString(){
        string fullData = 
        "Nombre: " + this->getName() + "\n" +
        "Apellido: " + this->getLastname() + "\n" +
        "Salario: " + to_string(this->getSalary()) + "\n" +
        "Area: " + this->getAreaType() + "\n" +
        "Tipo: " + this->getType() + "\n" +
        "Sucursal: " + this->getBranch()->getName() + " | code: " + this->getBranch()->getCode() + "\n";

        return fullData;
    };
};




