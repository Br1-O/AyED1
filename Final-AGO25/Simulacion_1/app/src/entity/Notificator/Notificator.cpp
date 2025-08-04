#include <iostream>
#include "../../../include/entity/Notificator/Notificator.hpp"
#include "../../../include/entity/Employee/IEmployee.hpp"

using namespace std;

class Notificator
{
private:
    string message;
    IEmployee* receiver;

public:
    Notificator()
    {
    }

    ~Notificator()
    {
    }
};

