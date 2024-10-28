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
    const int sizeOptions = 7;
    //array with titles of options
    string options[sizeOptions] = 
    {
    "Ejercicio 1 - (a)", 
    "Ejercicio 1 - (b)", 
    "Ejercicio 1 - (c)", 
    "Ejercicio 1 - (e)", 
    "Ejercicio 1 - (f)", 
    "Ejercicio 1 - (g)", 
    
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
            currentOption < 7 ? currentOption++ : currentOption;
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
            if (selectedOption != 7)
            {
            switch (selectedOption)
            {
            //■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ 
            //■■■■■■■■■■■■■■■■■■ SOLUCIONES A EJERCICIOS ABAJO ■■■■■■■■■■■■■■■■■■■■■■■■■■
            //■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ 
                case 0:
                {
                    cout << " ******** Ejercicio 1 ******** " << endl << endl;

                    cout << "a. Realizar un programa que pida la fecha de nacimiento y nos de la edad." << endl << endl;

                    cout << " ******** Respuesta ******** " << endl << endl;
                    
                    //get user's input for birthday date
                    int birthYear, birthMonth, birthDay;

                    cout << "Ingrese su año de nacimiento en formato: YYYY " << endl << endl;
                    cin >> birthYear;
                    cin.sync();

                    cout << "Ingrese el mes de nacimiento en formato: MM " << endl << endl;
                    cin >> birthMonth;
                    cin.sync();

                    cout << "Ingrese el día de nacimiento en formato: DD " << endl << endl;
                    cin >> birthDay;
                    cin.sync();

                    //get current time
                    std::time_t now = std::time(nullptr);
                    //convert it to tm
                    std::tm* localTime = std::localtime(&now);

                    //create current date strings
                    int currentYear = localTime->tm_year + 1900;
                    int currentMonth = localTime->tm_mon + 1;
                    int currentDay = localTime->tm_mday;
                    
                    //calculate age
                    int ageYears = currentYear - birthYear;
                    int ageMonths = currentMonth - birthMonth;
                    int ageDays = currentDay - birthDay;


                    // Adjust age if birthdate is in the future compared to current date
                    if (ageMonths < 0 || (ageMonths == 0 && ageDays < 0)) {
                        ageYears--;
                        ageMonths += 12;
                    }
                    if (ageDays < 0) {
                        // Calculate days in previous month
                        int previousMonthDays = currentDay;
                        if (currentMonth == 1) {
                            previousMonthDays = 31;
                        } else if (currentMonth == 3) {
                            previousMonthDays = 28;
                        } else if (currentMonth == 5) {
                            previousMonthDays = 30;
                        } else if (currentMonth == 7) {
                            previousMonthDays = 30;
                        } else if (currentMonth == 8) {
                            previousMonthDays = 31;
                        } else if (currentMonth == 10) {
                            previousMonthDays = 31;
                        } else if (currentMonth == 12) {
                            previousMonthDays = 30;
                        }
                    }

                    cout << "Su edad es: " << ageYears << endl << endl;

                    break;
                }
                case 1:
                {
                    cout << " ******** Ejercicio 1 ******** " << endl << endl;

                    cout << "b. Realizar un programa que pida 3 datos y nos devuelva el promedio" << endl << endl;

                    cout << " ******** Respuesta ******** " << endl << endl;

                    int num1, num2, num3;

                    double avrg;

                    inputValidation(num1, "Por favor, ingrese el primer valor: ", "¡Por favor, solo ingrese valores numericos enteros!");

                    inputValidation(num2, "Por favor, ingrese el segundo valor: ", "¡Por favor, solo ingrese valores numericos enteros!");

                    inputValidation(num3, "Por favor, ingrese el tercer valor: ", "¡Por favor, solo ingrese valores numericos enteros!");

                    avrg = ( num1 + num2 + num3 ) / 3.0;

                    cout << "El promedio de los valores es: " << avrg;

                    cout << endl << endl;

                    break;
                }
                case 2:
                    {
                    cout << " ******** Ejercicio 1 ******** " << endl << endl;

                    cout << "c. Realizar un programa que pida 4 datos y devuelva el producto de Ambos" << endl << endl;

                    cout << " ******** Respuesta ******** " << endl << endl;

                    int num1, num2, num3, num4, product;
                    
                    inputValidation(num1, "Por favor, ingrese el primer valor: ", "¡Por favor, solo ingrese valores numericos enteros!");

                    inputValidation(num2, "Por favor, ingrese el segundo valor: ", "¡Por favor, solo ingrese valores numericos enteros!");

                    inputValidation(num3, "Por favor, ingrese el tercer valor: ", "¡Por favor, solo ingrese valores numericos enteros!");

                    inputValidation(num4, "Por favor, ingrese el cuarto valor: ", "¡Por favor, solo ingrese valores numericos enteros!");

                    product = num1 * num2 * num3 * num4;

                    cout << "El producto de los valores ingresados es: " << product << endl << endl;

                    break;
                    }
                case 3:
                    {
                    cout << " ******** Ejercicio 1 ******** " << endl << endl;

                    cout << "Escribe un programa en C++ que nos diga cual es el volumen de un cono con un radio de la base de 14,5 y una altura de 26,79." << endl << endl;

                    cout << " ******** Respuesta ******** " << endl << endl;

                    double base = 14.5;
                    double radius = base / 2;
                    double height = 26.79;
                    const double PI = 3.141592;

                    double volume = (PI * ( radius*radius ) * height) / 3;

                    cout << "El volumen del cono es: " << volume << endl << endl;
                    break;
                    }
                case 4:
                    {
                    cout << " ******** Ejercicio 1 ******** " << endl << endl;

                    cout << "f. Escribe un programa en C++ que lea del teclado un número (real) de grados Fahrenheit y lo convierta a Celsius mostrando el resultado en la pantalla. C =5 / 9 x (F ‐ 32)" << endl << endl;

                    cout << " ******** Respuesta ******** " << endl << endl;

                    int fahrenheitInput;

                    inputValidation(fahrenheitInput, "Ingrese el valor de la temperatura, a ser convertida a Celsius, en grados Fahrenheit: ", "¡Por favor, solo ingrese valores numericos enteros!");
                    double celciusValue = (5/9.0) * (fahrenheitInput - 32);

                    cout << "La temperatura en grados Celcius es: " << celciusValue << " grados." << endl << endl;

                    break;
                    }
                case 5:
                    {
                    cout << " ******** Ejercicio 1 ******** " << endl << endl;

                    cout << "g. Escribe un programa que lea del teclado un tiempo transcurrido en segundos y muestre en la pantalla las horas, los minutos y los segundos equivalentes." << endl << endl;

                    cout << " ******** Respuesta ******** " << endl << endl;

                    int secondsInput;

                    int hours, minutes, seconds;

                    inputValidation(secondsInput, "Por favor, ingrese los segundos totales a ser formateados: ", "¡Por favor, ingrese un valor numerico entero!");

                    hours =  ( secondsInput / 3600 );

                    minutes =  ( secondsInput%3600 ) / 60;

                    seconds = ( ( secondsInput%3600 ) % 60 );
                    
                    cout << "Los segundos ingresados son equivalentes a: " << hours << " horas, " << minutes << " minutos y " << seconds << " segundos." << endl << endl;
                    
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

