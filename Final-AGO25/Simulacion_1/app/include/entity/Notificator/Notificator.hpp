#ifndef NOTIFICATOR_HPP
#define NOTIFICATOR_HPP

#include <iostream>
#include <list>
#include "../Employee/IEmployee.hpp"

class Notificator
{
public:
    Notificator();
    ~Notificator();
//■■■■■■■■■■ Methods ■■■■■■■■■■//
    void notifyOne(std::string message, IEmployee* employee);
    void notifyMany(std::string message, std::list<IEmployee*> employees);
};

#endif