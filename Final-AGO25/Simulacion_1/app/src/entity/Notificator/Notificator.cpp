#include <iostream>
#include "../../../include/entity/Notificator/Notificator.hpp"
#include "../../../include/entity/Employee/IEmployee.hpp"

using namespace std;

Notificator::Notificator(){}
Notificator::~Notificator(){}
//■■■■■■■■■■ Methods ■■■■■■■■■■//
void Notificator::notifyOne(string message, IEmployee* employee){
    employee->getNotification(message);
}
void Notificator::notifyMany(string message, list<IEmployee*> employees){
    for (auto &&employee : employees)
    {
        employee->getNotification(message);
    }
}


