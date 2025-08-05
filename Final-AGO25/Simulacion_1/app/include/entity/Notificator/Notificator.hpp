#ifndef NOTIFICATOR_HPP
#define NOTIFICATOR_HPP

#include <iostream>
#include "../../../include/entity/Notificator/Notificator.hpp"
#include "../../../include/entity/Employee/IEmployee.hpp"

using namespace std;

class Notificator
{
public:
    Notificator();
    ~Notificator();
//■■■■■■■■■■ Methods ■■■■■■■■■■//
    void notifyOne(string message, IEmployee* employee);
    void notifyMany(string message, list<IEmployee*> employees);
};

#endif