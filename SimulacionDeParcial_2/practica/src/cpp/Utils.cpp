#include <iostream>

using namespace std;

namespace utils
{
    //funtion to display the menu
    void displayMenu(){

        const string title = "--- Cosmeticos La Pestaña Aña ---";
        const string message = "- Por favor, ingrese el numero de la accion que desea realizar -";

        const int numberOfOptions = 5;
        string menu[numberOfOptions] = 
        {
            "1. Visualizar el listado de pedidos.",
            "2. Agregar un nuevo articulo.",
            "3. Agregar un nuevo cliente.",
            "4. Generar un nuevo pedido.",
            "5. Salir."
        };

        cout << title << endl;
        cout << message << endl << endl;

        for (size_t i = 0; i < numberOfOptions; i++)
        {
            cout << menu[i] << endl;
        }

        cout << endl;
    };

    //get selected option from user
    /*
    void getSelectedOptionFromUser(int* selectedOption, tStudentList* studentList, tFilePath path){

        checkInputValueForInteger(selectedOption);

        //ignore remaining break line
        cin.ignore();

        switch (*selectedOption)
        {
            //display list based on ordering params
            case 1:
                clearConsole();

                displayAllStudents(*studentList);

                pauseConsole();
            break;

            //search for a student
            case 2:
            {            
                clearConsole();

                int studentId;

                cout << "Ingrese el id del alumno que busca: " << endl;

                checkInputValueForInteger(&studentId, "Por favor, ingrese un id valido.");
                cin.ignore();

                const tStudent* studentFound = findStudentById(*studentList, studentId);

                if(studentFound)
                {
                    displayStudent(studentFound);
                }else
                {
                    cout << "No se ha podido encontrar al alumno en el listado.";
                }

                pauseConsole();
            }
            break;

            //insert a new student
            case 3:
                clearConsole();

                insertStudent(studentList) && saveIntoFile(path, *studentList) 
                ? 
                    cout << "Se ha creado el registro del alumno correctamente" << endl
                :
                    cout << "No se ha podido registrar al alumno." << endl
                ;
                
                pauseConsole();
            break;

            //delete a student
            case 4:
            {            
                clearConsole();

                int studentId;
                cout << "Ingrese el id del alumno que desea borrar: " << endl;
                            
                checkInputValueForInteger(&studentId, "Por favor, ingrese un id valido.");
                cin.ignore();

                deleteStudent(studentList, studentId) && saveIntoFile(path, *studentList) ?
                    cout << "Alumno borrado correctamente del listado."
                :
                    cout << "No se ha podido borrar al estudiante del listado."
                ;
                
                pauseConsole();
            }
            break;

            //exit the program
            case 5:
                *selectedOption = 999;
            break;
            
            //invalid input
            default:
                cout << "Por favor, ingrese una opcion valida." << endl << endl;
            break;
        }
    };
    */

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