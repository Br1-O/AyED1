#include <iostream>
#include "../../include/utils.hpp"

using namespace std;

namespace utils
{
    //check input value
    void checkInputValueForInteger(int* inputVariable, string errorMessage){

        //check if input is valid
        while (!(cin >> *inputVariable)) {

            cout << errorMessage;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    };

    //pause the console
    void pauseConsole(){
        #ifdef _WIN32 // For Windows
            std::cout << "Presione una tecla para volver al menu . . . ";
            std::cin.get(); // Wait for the user to press a key
        #else // For Linux and other Unix-like systems
            std::cout << "Presione una tecla para volver al menu . . . ";
            std::cin.ignore(); // Ignore any previous input
            std::cin.get(); // Wait for the user to press Enter
        #endif
    };

    //clean the console
    void clearConsole(){
        #ifdef _WIN32 // For Windows
            system("cls"); // Clear the console using cls command
        #else // For Linux and other Unix-like systems
            system("clear"); // Clear the console using clear command
        #endif
    };
} // namespace utils