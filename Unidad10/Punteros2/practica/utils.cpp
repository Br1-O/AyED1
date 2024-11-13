//includes
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <chrono>
#include <thread>
#include <string>
#include <vector>
#include <functional>
#include <limits>
#include "utils.hpp"

#ifdef __linux__
int _getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
#endif

//namespace for i/o
using namespace std;

namespace utils
{
    //functions definition

    void getSelectedOption(const int sizeOptions, const string options[], const vector<function<void()>> optionsBodies){

        //EXAMPLE of array with titles of options
        // string options[sizeOptions] = 
        // {
        // "Ejercicio 1 - (a)", 
        // "Ejercicio 1 - (b)", 
        // "Ejercicio 1 - (c)", 
        // "Ejercicio 1 - (d)", 
        // "Ejercicio 1 - (e)", 
        // "Ejercicio 1 - (f)", 
        // "Ejercicio 1 - (g)", 
        // "Ejercicio 1 - (h)",
        
        // "Salir del programa."
        // };

        // EXAMPLE of vector of std::function for each menu action
        // const vector<function<void()>> optionsBodies =
        // {
        //     //exercise 1
        //     []()
        //     {
                
        //     },
        //     //exercise 2
        //     []()
        //     {
                
        //     },
        //     //exercise 3
        //     []()
        //     {
                
        //     },
        //     //exercise 4
        //     []()
        //     {
                
        //     },
        //     //exercise 5
        //     []()
        //     {
                
        //     },
        //     //exercise 6
        //     []()
        //     {
                
        //     },
        //     //exercise 7
        //     []()
        //     {
                
        //     }
        // };
        // };

        //current selection
        int currentOption = 0;
        //selected option
        int selectedOption = 0;
        //go to menu or exit program
        char exit = 'y';
        //check if user's input was invalid
        bool mistake = false;

        //main loop for menu
        do 
        {
            //call to menu
            menu(options, sizeOptions, currentOption, &mistake);
            // Use _getch() for immediate character input without Enter
            char input = _getch();

            //move through menu via input
            switch (input)
            {
            case 's':
            case 'S':
                currentOption < (sizeOptions - 1) ? currentOption++ : currentOption;
                break;
            case 'w':
            case 'W':
                currentOption > 0 ? currentOption-- : currentOption;
                break;
            //enter to select currentOption
            case 'e':
            case 'E':
                selectedOption = currentOption;

                //control display of options based on user input
                if (selectedOption != (sizeOptions - 1))
                {
                    if (selectedOption >= 0 && selectedOption < sizeOptions) {
                        
                        //clear command
                        system(CLEAR_COMMAND);
                        
                        // Call the chosen action
                        optionsBodies[selectedOption]();  

                    } else {
                        cout << "Invalid option" << endl << endl;
                    }
                } 
                else
                {   
                    //clear command
                    system(CLEAR_COMMAND);
                    
                    //display goodbye message
                    goodbye();

                    //exit loop
                    exit = 'n';
                }

                if (exit == 'y')
                {             
                    //check if user wants to go to menu or end program
                    backToMenu(&exit);
                    break;
                }


            //input error message will appear in any other input
            default:
                //display error message
                mistake = true;
                break;
            }

            if (exit == 'n' || exit == 'N')
            {
                //clear command
                system(CLEAR_COMMAND);
                //display goodbye message
                goodbye();
            }
        } while (exit == 'y');
    }

    //Write multiple characters all at once
    void writeChar(int times, int character){
        for (size_t i = 0; i < times; i++)
        {
            printf("%c", character);
        }
    }

    //dinamic menu option(string array (w/ options text), int (number of options), int (id of current selected option))
    void menu(const string options[], int sizeOptions, int currentOption, bool* mistake)
    {
        //clear command
        system(CLEAR_COMMAND);

        //text of menu
        writeChar(1, 201);
        writeChar(38, 205);
        writeChar(1, 187);
        printf("\n");
        cout << static_cast<char>(186) << setw(22) << "Controles:" << setw(17) << static_cast<char>(186) << endl;
        cout << static_cast<char>(186) << setw(39) << static_cast<char>(186) << endl;
        cout << static_cast<char>(186) << setw(25) << "W - cursor arriba" << setw(14) << static_cast<char>(186) << endl;
        cout << static_cast<char>(186) << setw(24) << "S - cursor abajo" << setw(15) << static_cast<char>(186) << endl; 
        cout << static_cast<char>(186) << setw(32) << "E - ingresar a la opcion"<< setw(7)  << static_cast<char>(186) << endl;

        writeChar(1, 204);
        writeChar(38, 205);
        writeChar(1, 185);
        printf("\n");
        cout << static_cast<char>(186) << " Seleccione el ejercicio a visualizar:" << static_cast<char>(186) << endl;
        writeChar(1, 200);
        writeChar(38, 205);
        writeChar(1, 188);
        printf("\n\n");

        //control text cursor display
        for (size_t i = 0; i < sizeOptions; i++)
        {
            if (i == currentOption)
            {
                printf("%c ", 175);
            }
            else
            {
                cout << "  ";
            }
            
            //option's text display
            cout << options[i] << endl;

            //add last break of line
            if (i == sizeOptions-1)
            {
                cout<< endl;
            }
        }
        
        //display input error message
        if (*mistake)
        {
            writeChar(1, 201);
            writeChar(87, 205);
            writeChar(1, 187);
            printf("\n");  
            cout << static_cast<char>(186) <<  " Por favor ingrese W/S para seleccionar una opcion, o ingrese E para ver el ejercicio. " << static_cast<char>(186) <<  endl;
            writeChar(1, 200);
            writeChar(87, 205);
            writeChar(1, 188);
            printf("\n\n");

            *mistake = false;
        }
    }

    //check if user wants to go to menu or end program
    void backToMenu(char* exit) 
    {
        char back = 'y';
        bool correctInput = false;

            printf("\n");
            writeChar(1, 201);
            writeChar(31, 205);
            writeChar(1, 187);
            printf("\n");  
            cout << static_cast<char>(186) << "  Desea volver al menu? Y / N  " << static_cast<char>(186) << endl;
            writeChar(1, 200);
            writeChar(31, 205);
            writeChar(1, 188);
            printf("\n");

        do
        {
            back = _getch();

            if ((back == 'y') || (back == 'Y'))
            {
                *exit = back;
                correctInput = true;
            }
            else if((back == 'n') || (back == 'N'))
            {
                *exit = 'n';
                correctInput = true;
            }
        } while (!correctInput);
    }

    //display goodbye message
    void goodbye(){
        writeChar(1, 201);
        writeChar(38, 205);
        writeChar(1, 187);
        printf("\n");  
        cout << static_cast<char>(186) << " ** Gracias! Nos vemos la proxima! ** " << static_cast<char>(186) << endl;
        writeChar(1, 200);
        writeChar(38, 205);
        writeChar(1, 188);
        printf("\n\n");

        //program will shut down after 1 second
        this_thread::sleep_for(chrono::seconds(1));
    }

} // namespace utils