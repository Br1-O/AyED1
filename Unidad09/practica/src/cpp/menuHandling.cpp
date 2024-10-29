#include <iostream>

#include "../../include/students.hpp"
#include "../../include/fileHandling.hpp"
#include "../../include/utils.hpp"

using namespace std;
using namespace students;
using namespace fileHandling;
using namespace utils;

namespace menuHandling
{
    //funtion to display the menu
    void displayMenu(){

        const string title = "Por favor, ingrese el numero de la accion que desea realizar: ";
        const int numberOfOptions = 5;
        string menu[numberOfOptions] = 
        {
            "1. Visualizar el listado de alumnos.",
            "2. Buscar un alumno.",
            "3. Insertar un nuevo alumno.",
            "4. Borrar un alumno.",
            "5. Salir."
        };

        cout << title << endl << endl;

        for (size_t i = 0; i < numberOfOptions; i++)
        {
            cout << menu[i] << endl;
        }

        cout << endl;
    };

    //get selected option from user
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
} // namespace menuHandling

