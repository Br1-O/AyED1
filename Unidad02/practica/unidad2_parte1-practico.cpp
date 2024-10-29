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

//main function
int main(int argc, char const *argv[])
{
    //size of options array
    const int sizeOptions = 8;
    //array with titles of options
    string options[sizeOptions] = 
    {
    "Ejercicio 1 - (a)", 
    "Ejercicio 1 - (b)", 
    "Ejercicio 1 - (c)", 
    "Ejercicio 1 - (d)", 
    "Ejercicio 2 - (a)", 
    "Ejercicio 2 - (b)", 
    "Ejercicio 2 - (c)", 
    
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
    while (exit == 'y')
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

                    cout << "a. La suma de 45 + 34. Mostrar por pantalla el resultado." << endl << endl;

                    cout << " ******** Respuesta ******** " << endl << endl;

                    int result1 = 45 + 34;

                    cout << "El resultado de la suma de 45 + 34 es: " << result1 << endl << endl;

                    break;
                    }
                case 1:
                {
                    cout << " ******** Ejercicio 1 ******** " << endl << endl;

                    cout << "b. La resta de 45 - 40. Mostrar el resultado por pantalla." << endl << endl;

                    cout << " ******** Respuesta ******** " << endl << endl;

                    int result2 = 45 - 40;

                    cout << "El resultado de la resta de 45 - 40 es: " << result2 << endl << endl;

                    break;
                    }
                case 2:
                    {
                    cout << " ******** Ejercicio 1 ******** " << endl << endl;

                    cout << "c. Mostrar el resultado de la division de 46 y 3." << endl << endl;

                    cout << " ******** Respuesta ******** " << endl << endl;
                    
                    //expreso divisor como float para evitar el truncamiento por operacion de integers
                    float result3 = 46 / 3.0f;

                    cout << "El resultado de la division de 46 y 3 es: " << result3 << endl << endl;

                    break;
                    }
                case 3:
                    {
                    cout << " ******** Ejercicio 1 ******** " << endl << endl;

                    cout << "d. Un programa que multiplique 65 * 3 con la salida en pantalla." << endl << endl;

                    cout << " ******** Respuesta ******** " << endl << endl;

                    int result4 = 65 * 3;

                    cout << "El resultado de la multiplicacion de 65 y 3 es: " << result4 << endl << endl;
                    break;
                    }
                case 4:
                    {
                    cout << " ******** Ejercicio 2 ******** " << endl << endl;

                    cout << "a. Calcula el volumen, de una habitacion que tiene 5 m de largo, 4 m de ancho y 2.5 m de alto." << endl << endl;

                    cout << " ******** Respuesta ******** " << endl << endl;

                    int x = 5, z = 4;
                    float y = 2.5;

                    float volumeRoom = x * z * y;

                    cout << "El volumen de la habitacion es de: " << volumeRoom << "m." << endl << endl;

                    break;
                    }
                case 5:
                    {
                    cout << " ******** Ejercicio 2 ******** " << endl << endl;

                    cout << "b. Escribe un programa en C++ que nos diga cual es el volumen de un cono con un radio de la base de 14,5 y una altura de 26,79. La formula que debes usar es: (Pi x (radio)2 / altura) /3, recordar Pi=3.14." << endl << endl;

                    cout << " ******** Respuesta ******** " << endl << endl;

                    float r = 14.5, h = 26.79;
                    const float PI = 3.14;

                    float volumeCone = (PI * (r*r) * h ) / 3 ;

                    cout << "El volumen del cono es de: " << volumeCone << endl << endl;
                    
                    break;
                    }
                case 6:
                    {
                    cout << " ******** Ejercicio 2 ******** " << endl << endl;

                    cout << "c. Modificar el programa anterior para que usen variables Dobles, que diferencia nota? Por que?" << endl << endl;

                    cout << " ******** Respuesta ******** " << endl << endl;

                    double r_ = 14.5, h_ = 26.79;
                    const double PI_ = 3.14;

                    double volumeCone_ = (PI_ * (r_*r_) * h_ ) / 3 ;

                    cout << "El volumen del cono es de: " << volumeCone_ << endl << "Y no note ninguna diferencia con el anterior ejercicio, dado que float y double poseen mismas funcionalidades con pocos decimales, variando solo su precision y rango maximo. En caso de haber usado integers, la diferencia que hubiera observado seria el truncamiento de las cifras decimales." << endl << endl;

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
    }
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

