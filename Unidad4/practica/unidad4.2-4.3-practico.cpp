//■■■■■■■■■■■■■■■■■■
// Instrucciones  //
//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ 
// Compilar el programa para poder transitar la ejecución de cada ejercicio via el menu.     //
//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ 
// El codigo de las soluciones está entre los bloques comentados de forma destacada más abajo. //
//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■

//includes
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <chrono>
#include <thread>
#include <string>
#include <fstream>

// Detect OS for clear
#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

//namespace for i/o
using namespace std;

//functions declaration
void writeChar(int times, int character);
void menu(const string options[], int sizeOptions, int currentOption, bool* mistake);
void backToMenu(char* exit);
void goodbye();
void inputValidation(int &num, string message, string errorMessage);

//main function
int main(int argc, char const *argv[])
{
    //size of options array
    const int sizeOptions = 1 + (3);
    //array with titles of options
    string options[sizeOptions] = 
    {
    "Ejercicio 1", 
    "Ejercicio 2", 
    "Ejercicio 3",
    
    "Salir del programa."
    };
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
        //user's input
        char input;
        cin >> input;

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
            switch (selectedOption)
            {
            //■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ 
            //■■■■■■■■■■■■■■■■■■ SOLUCIONES A EJERCICIOS ABAJO ■■■■■■■■■■■■■■■■■■■■■■■■■■
            //■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ 
                case 0:
                {
                    cout << " ******** Ejercicio 1 ******** " << endl << endl;

                    cout << "1. Realizar un programa que rellene un array con los 100 primeros números enteros y los muestre en pantalla" 
                    << endl << endl;
                    
                    cout << " ******** Respuesta ******** " << endl << endl;

                    int maxSizeArray = 100;
                    int numArray[100];

                    for (size_t i = 0; i <= maxSizeArray; i++)
                    {
                        numArray[i] = i+1;
                    }

                    cout << "Los primeros 100 numeros naturales son:" << endl;

                    for (size_t i = 0; i < maxSizeArray; i++)
                    {
                        cout << numArray[i] << endl;
                    }

                    break;
                }
                case 1:
                {
                    cout << " ******** Ejercicio 2 ******** " << endl << endl;

                    cout << "2. Realizar un Programa Que rellene un array con los números primos comprendidos entre 1 y 100 y los muestre en pantalla" 
                    << endl << endl;

                    cout << " ******** Respuesta ******** " << endl << endl;

                    int primos[100];
                    int contador = 0;

                    for (int i = 2; i <= 100; i++) {
                        bool esPrimo = true;

                        // Verificar si 'i' es primo
                        for (int j = 2; j <= i / 2; j++) {
                            if (i % j == 0) {
                                esPrimo = false;
                                break;
                            }
                        }

                        if (esPrimo) {
                            primos[contador] = i;
                            contador++;
                        }
                    }

                    cout << "Los numeros primos entre 1 y 100 son:" << endl;
                    for (int i = 0; i < contador; i++) {
                        cout << primos[i] << " ";
                    }
                    cout << endl << endl;

                    break;
                }
                case 2:
                {
                    cout << " ******** Ejercicio 3 ******** " << endl << endl;

                    cout << "3. Realizar un Programa Que rellene un array con los numeros impares comprendidos entre 1 y 100 y los muestre en pantalla" 
                    << endl << endl;

                    cout << " ******** Respuesta ******** " << endl << endl;

                    int impares[50];
                    int contador = 0;

                    for (int i = 1; i <= 100; i++) {
                        if (i % 2 != 0) {
                            impares[contador] = i;
                            contador++;
                        }
                    }

                    cout << "Los numeros impares entre 1 y 100 son:" << endl;
                    for (int i = 0; i < contador; i++) {
                        cout << impares[i] << " ";
                    }
                    cout << endl << endl;
                
                    break;
                }
            //■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ 
            //■■■■■■■■■■■■■■■■■■■ SOLUCIONES A EJERCICIOS ARRIBA ■■■■■■■■■■■■■■■■■■■■■■■■
            //■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■    
            }
            } 
            else
            {   //clear command
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
    return 0;
}


//functions definition

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
    writeChar(1, 201);
    writeChar(31, 205);
    writeChar(1, 187);
    printf("\n");  
    cout << static_cast<char>(186) << "  Desea volver al menu? Y / N  " << static_cast<char>(186) << endl;
    writeChar(1, 200);
    writeChar(31, 205);
    writeChar(1, 188);
    printf("\n");

    char back = 'y';
    cin >> back;

    (back == 'y') || (back == 'Y') ? (*exit = back) : (*exit = 'n');
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

//validate an input via cin
void inputValidation(int &num, string message, string errorMessage)
{

    bool error = true;

   do{
        cout << message;
        cin >> num;
        cin.sync();
        cout << endl << endl;

        if (cin.fail())
        {
            cout << errorMessage << endl << endl;
            cin.clear();
            cin.sync();
        }
        else
        {
            error = false;
        }
   }
   while(error);
}