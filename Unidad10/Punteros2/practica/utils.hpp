#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <limits>

// Detect OS for conditional definitions and includes
#ifdef _WIN32
#include <conio.h>  // For _getch() on Windows
#define CLEAR_COMMAND "cls"
#else
#include <termios.h>
#include <unistd.h>
#define CLEAR_COMMAND "clear"

// Linux function to replace _getch()
int _getch();
#endif

namespace utils {
    void writeChar(int times, int character);
    void menu(const std::string options[], int sizeOptions, int currentOption, bool* mistake);
    void backToMenu(char* exit);
    void goodbye();
    void getSelectedOption(const int sizeOptions, const std::string options[], const std::vector<std::function<void()>> optionsBodies);

    template <typename T>
    void inputValidation(T *input, const std::string& message, const std::string& errorMessage)
    {
        bool error = true;

        do
        {
            std::cout << message;
            std::cin >> *input;

            if (std::cin.fail())
            {
                // Clear the error state and ignore invalid input
                std::cout << errorMessage << std::endl << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
            {
                error = false;
            }
        } while (error);
    };
}

#endif // UTILS_H