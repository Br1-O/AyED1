#if !defined(UTILS_HPP)
#define UTILS_HPP

    #include <iostream>
    
    namespace utils
    {
        //■■■■■■■■■■■■■■■■■■■■■■■■■■■■■( interfaces declaration )■■■■■■■■■■■■■■■■■■■■■■■■■■■■//
    
        //check input value
        void checkInputValueForInteger(int* inputVariable, std::string errorMessage = "Entrada invalida. Por favor, ingrese una opcion valida: ");

        //pause the console
        void pauseConsole();

        //clean the console
        void clearConsole();
    } // namespace utils
    
#endif // UTILS_HPP
