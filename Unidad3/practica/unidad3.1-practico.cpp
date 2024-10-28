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
    const int sizeOptions = 1 + (3);
    //array with titles of options
    string options[sizeOptions] = 
    {
    "Ejercicio 1 - (a)", 
    "Ejercicio 1 - (b)", 
    "Ejercicio 1 - (c)", 
    
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

                    cout << "a. Una aplicación para un restaurante que tiene: primer plato, plato principal y postre," 
                    << "toma pedidos de los mozos. Estos envían la comida codificada por numero para cada plato."
                    <<  "El cocinero recibe el pedido en formato de texto con el nro de mesa, nombre mozo, fecha, hora," 
                    <<  "primer plato, plato principal y postre. Se pide desarrollar una APP que pida la comida y muestre por pantalla la info solicitada."
                    << endl << endl;

                    cout << " ******** Respuesta ******** " << endl << endl;

                    typedef enum 
                    { ensalada, sopa, canapes, empanaditas } 
                    tStarter;

                    typedef enum 
                    { tallarines, lasagna, ravioles } 
                    tMainDish;

                    typedef enum 
                    { helado, flan, budinDePan } 
                    tDessert;

                    typedef enum 
                    { Juan, Tomas, Camila } 
                    tWaiter;

                    typedef struct{
                        string starter;
                        string mainDish;
                        string dessert;

                        string waiter;

                        int table;

                        string date = "aca pondria el valor de la fecha actual con la funcion de la libreria chrono";
                    } tOrder;

                    auto replaceStarterName = [](tStarter starter){

                        string starterName;

                        int starterValue = static_cast<int>(starter) - 1;

                        switch (starterValue)
                        {
                            case ensalada:
                                starterName = "ensalada";
                            break;

                            case sopa:
                                starterName = "sopa";
                            break;

                            case canapes:
                                starterName = "canapes";
                            break;

                            case empanaditas:
                                starterName = "empanaditas";
                            break;
                        }

                        return starterName;
                    };

                    auto replaceMainDishName = [](tMainDish mainDish){

                        string mainDishName;

                        int mainDishValue = static_cast<int>(mainDish) - 1;

                        switch (mainDishValue)
                        {
                            case tallarines:
                                mainDishName = "tallarines";
                            break;

                            case lasagna:
                                mainDishName = "lasagna";
                            break;

                            case ravioles:
                                mainDishName = "ravioles";
                            break;
                        }

                        return mainDishName;
                    };

                    auto replaceDessertName = [](tDessert dessert){

                        string dessertName;

                        int dessertValue = static_cast<int>(dessert) - 1;

                        switch (dessertValue)
                        {
                            case helado:
                                dessertName = "helado";
                            break;

                            case flan:
                                dessertName = "flan";
                            break;

                            case budinDePan:
                                dessertName = "budinDePan";
                            break;
                        }

                        return dessertName;
                    };

                    auto replaceWaiterName = [](tWaiter waiter){

                        string waiterName;

                        int waiterValue = static_cast<int>(waiter) - 1;

                        switch (waiterValue)
                        {
                            case Juan:
                                waiterName = "Juan Ordonez";
                            break;

                            case Tomas:
                                waiterName = "Tomas Andinopolus";
                            break;

                            case Camila:
                                waiterName = "Camila Hernandez";
                            break;
                        }
                        
                        return waiterName;
                    };

                    tOrder order;
                    int selectedOption;

                    cout << "Por favor, seleccione la opcion de entrada que desea: 1, 2, 3, 4" << endl;
                    cin >> selectedOption;
                    cin.sync();

                    order.starter = replaceStarterName(static_cast<tStarter>(selectedOption));

                    cout << "Por favor, seleccione la opcion de plato principal que desea: 1, 2, 3" << endl;
                    cin >> selectedOption;
                    cin.sync();

                    order.mainDish = replaceMainDishName(static_cast<tMainDish>(selectedOption));

                    cout << "Por favor, seleccione la opcion de postre que desea: 1, 2, 3" << endl;
                    cin >> selectedOption;
                    cin.sync();

                    order.dessert = replaceDessertName(static_cast<tDessert>(selectedOption));

                    order.waiter = replaceWaiterName(static_cast<tWaiter>(1));

                    order.table = 1;

                    cout << "La orden es: "
                    << order.starter << endl 
                    << order.mainDish << endl 
                    << order.dessert << endl 
                    << order.waiter << endl 
                    << order.table << endl 
                    << order.date << endl 
                    << endl << endl;

                    break;
                }
                case 1:
                {
                    cout << " ******** Ejercicio 1 ******** " << endl << endl;

                    cout << "b. Una empresa de viajes nos pide que realicemos un programa para tomar"
                    <<     "reservas en avión, las mismas pueden ser clase Primera, Bussiness y"
                    <<     "económica, además del dni, apellido y nombre, aeropuerto origen y destino:"
                    <<     "Código Aeropuerto"
                    <<     "1. Bahía Blanca-BHI"
                    <<     "2. Buenos Aires Aeroparque-AEP"
                    <<     "3. Buenos Aires El Palomar-EPA"
                    <<     "4. Buenos Aires Ezeiza-EZE"
                    <<     "5. San Carlos de Bariloche-BRC"
                    <<     "6. San Fernando del Valle de Catamarca-CTC"
                    <<     "7. Comodoro Rivadavia-CRD"
                    <<     "El usuario introduce los datos personales, la clase y el origen – destino,"
                    <<     "mostrando el resultado x pantalla." 
                    << endl << endl;

                    cout << " ******** Respuesta ******** " << endl << endl;

                    typedef enum 
                    { first, bussiness, economic }
                    tClass;

                    typedef enum 
                    { BHI, AEP, EPA, EZE, BRC, CTC, CRD }
                    tAirport;

                    typedef struct
                    {   
                        string name;
                        int dni;
                        string classOfTicket;
                        string airportOrigin;
                        string airportDestiny;

                    } tTicket;

                    auto replaceAirportName = [](tAirport airport){
                        
                        string airportName;

                        int airportValue = static_cast<int>(airport) - 1;

                        switch (airportValue)
                        {
                            case BHI:
                                airportName = "Bahia Blanca-BHI";
                            break;

                            case AEP:
                                airportName = "Buenos Aires Aeroparque-AEP";
                            break;

                            case EPA:
                                airportName = "Buenos Aires El Palomar-EPA";
                            break;

                            case EZE:
                                airportName = "Buenos Aires Ezeiza-EZE";
                            break;

                            case BRC:
                                airportName = "San Carlos de Bariloche-BRC";
                            break;
                            
                            case CTC:
                                airportName = "San Fernando del Valle de Catamarca-CTC";
                            break;

                            case CRD:
                                airportName = "Comodoro Rivadavia-CRD";
                            break;

                        }

                        return airportName;
                    };

                    auto replaceTicketClassName = [](tClass ticketClass){
                        
                        string ticketClassName;

                        int ticketClassValue = static_cast<int>(ticketClass) - 1;

                        switch (ticketClassValue)
                        {
                            case first:
                                ticketClassName = "Primera Clase";
                            break;

                            case bussiness:
                                ticketClassName = "Bussiness";
                            break;

                            case economic:
                                ticketClassName = "Economica";
                            break;

                        }

                        return ticketClassName;
                    };

                    tTicket ticket;
                    int selectedOption;

                    cout << "Por favor, ingrese su nombre completo: " << endl;
                    cin.ignore();
                    getline(cin, ticket.name);
                    cin.sync();

                    cout << "Por favor, ingrese su dni: " << endl;
                    cin >> ticket.dni;
                    cin.sync();

                    cout << "Por favor, seleccione la clase del ticket que desea comprar: (1) Primera Clase, (2) Bussiness, (3) Economica" << endl;
                    cin >> selectedOption;
                    cin.sync();

                    ticket.classOfTicket = replaceTicketClassName(static_cast<tClass>(selectedOption));
                    
                    cout << "Por favor, seleccione el aeropuerto de origen: 1, 2, 3, 4, 5, 6, 7" << endl;
                    cin >> selectedOption;
                    cin.sync();

                    ticket.airportOrigin = replaceAirportName(static_cast<tAirport>(selectedOption));

                    cout << "Por favor, seleccione el aeropuerto de destino: 1, 2, 3, 4, 5, 6, 7" << endl;
                    cin >> selectedOption;
                    cin.sync();

                    ticket.airportDestiny = replaceAirportName(static_cast<tAirport>(selectedOption));

                    cout << "Por favor, revise los datos de la orden: "
                    << "Titular: " << ticket.name << endl 
                    << "DNI: " << ticket.dni << endl 
                    << "Clase: " << ticket.classOfTicket << endl 
                    << "Origen: " << ticket.airportOrigin << endl 
                    << "Destino: " << ticket.airportDestiny << endl 
                    << endl << endl;

                    break;
                }
                case 2:
                    {
                    cout << " ******** Ejercicio 1 ******** " << endl << endl;

                    cout << "Una Verduleria nos pide que armemos el pedido para el mayorista para lo cual"
                    << "deberemos pedir al usuario el codigo proveedor, razon social, fecha de solicitud y fecha de entrega."
                    << "Las frutas estarán enumeradas (tomar solo 6 a modo de ejemplo), mostrando los datos x pantalla."
                    << endl << endl;

                    cout << " ******** Respuesta ******** " << endl << endl;


                    cout << "El producto de los valores ingresados es: " << endl << endl;

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

