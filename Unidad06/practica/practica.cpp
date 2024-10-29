/* 1. La Directora nos Encarga llevar un registro de los Alumnos por carrera y año .
Para ello deberemos armar un Programa que guarde los datos de los Alumnos en
Alumnos.txt.
Adicionalmente deberá realizar las siguientes Tareas:
a. Mostrar Listado de los Alumnos x pantalla
b. Mostrar un Alumno Determinado (buscar y mostrar x plantalla)
c. Insertar un Alumno
d. Eliminar un Alumno
e. Buscar un alumno
f. Que permita Ordenar de Forma Ascendente y Descendente los Alumnos y
Mostrarlos x pantalla
g. Opcional - Que permita elegir el campo de Ordenamiento. */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■( structures and types )■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

//ENUM for careers and careersYears
enum Career {
    AcompanamientoTerapeutico,
    AnalisisDeSistemas,
    GestionAmbiental,
    Turismo
};

enum CareerYear {
    primero,
    segundo,
    tercero
};

//student
typedef struct 
{
    unsigned int id;
    string name;
    string lastName;
    Career career;
    CareerYear careerYear;
} tStudent;

//array of students
const int maxListedStudents = 50;
typedef tStudent tStudentArray[maxListedStudents];

//List constaining array of students and elements counter
typedef struct
{
    tStudentArray studentArray;
    int currentListedStudents;
} tStudentList;

//type for reading/writing file
typedef ifstream tReadFile;
typedef ofstream tWriteFile;
typedef string tFilePath;

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■( interfaces declaration )■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

//funtion to display the menu
void displayMenu();

//check input value
void checkInputValueForInteger(int* inputVariable, string errorMessage);

//convert string to Career enum
Career intToCareer(const int careerInt);

//convert string to CareerYear enum
CareerYear intToCareerYear(const int careerYearInt);

//convert Career enum to integer
int careerToInt(const Career career);

//convert CareerYear enum to integer
int careerYearToInt(const CareerYear careerYear);

//convert career to string value
string careerToString(Career career);

//convert careerYear to string value
string careerYearToString(CareerYear year);

//get selected option from user
void getSelectedOptionFromUser(int* selectedOption, tStudentList* studentList, tFilePath path);

//reading and loading a file
bool loadFile(tFilePath path, tStudentList* studentList);

//insert a new Student into the list
bool insertStudent(tStudentList* studentList); 

//delete a student from tStudentList
bool deleteStudent(tStudentList* studentList, int studentId);

//show full list of students
void displayAllStudents(tStudentList studentList);

//show a student
void displayStudent(const tStudent* student);

//finding a student in the studentList by Id
const tStudent* findStudentById(const tStudentList studentList, int studentId);

//writing into a file
bool saveIntoFile(tFilePath path, const tStudentList studentList);

//pause the console
void pauseConsole();

//clean the console
void clearConsole();

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ MAIN ■■■■■■■■■■■■■■■■■■■■■■■■■■■■//
int main(int argc, char const *argv[])
{
    tStudentList studentList;
    tFilePath path = "students.txt";

    loadFile(path, &studentList);

    int selectedOption;

    do
    {
        displayMenu();
        getSelectedOptionFromUser(&selectedOption, &studentList, path);
        clearConsole();

    } while (selectedOption != 999);

    return 0;
}

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■( implementations )■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

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

//check input value
void checkInputValueForInteger(int* inputVariable, string errorMessage = "Entrada invalida. Por favor, ingrese una opcion valida: " ){

    //check if input is valid
    while (!(cin >> *inputVariable)) {

        cout << errorMessage;
        cin.clear();
        cin.ignore(1000, '\n');
    }
};

//convert int to Career enum
Career intToCareer(const int careerInt) {

    Career career = AcompanamientoTerapeutico;

    if (careerInt == 1) return AcompanamientoTerapeutico;
    if (careerInt == 2) return AnalisisDeSistemas;
    if (careerInt == 3) return GestionAmbiental;
    if (careerInt == 4) return Turismo;

    return career;
}

//convert int to CareerYear enum
CareerYear intToCareerYear(const int careerYearInt) {
    CareerYear careerYear = primero;

    if (careerYearInt == 1) careerYear=primero;
    if (careerYearInt == 2) careerYear=segundo;
    if (careerYearInt == 3) careerYear=tercero;

    return careerYear;
}

//convert Career enum to integer
int careerToInt(const Career career) {
    switch (career) {
        case AcompanamientoTerapeutico: return 1;
        case AnalisisDeSistemas: return 2;
        case GestionAmbiental: return 3;
        case Turismo: return 4;
        default: return 0;
    }
}

//convert CareerYear enum to integer
int careerYearToInt(const CareerYear careerYear) {
    switch (careerYear) {
        case primero: return 1;
        case segundo: return 2;
        case tercero: return 3;
        default: return 0;
    }
}

//convert career to string value
string careerToString(Career career) {
    switch (career) {
        case AcompanamientoTerapeutico: return "Acompanamiento Terapeutico";
        case AnalisisDeSistemas: return "Analisis de Sistemas";
        case GestionAmbiental: return "Gestion Ambiental";
        case Turismo: return "Turismo";
        default: return "Desconocido";
    }
}

//convert careerYear to string value
string careerYearToString(CareerYear year) {
    switch (year) {
        case primero: return "Primero";
        case segundo: return "Segundo";
        case tercero: return "Tercero";
        default: return "Desconocido";
    }
}

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

//load file into list
bool loadFile(tFilePath path, tStudentList* studentList) {
    tReadFile file(path);
    bool completed = false;

    if (file.is_open()) {
        std::string tempLine;
        studentList->currentListedStudents = 0;
        int index = 0;

        while (getline(file, tempLine)) {
            //skip empty lines
            if (tempLine.empty()) {
                continue;
            }

            //stop loading if sentinel is "999"
            if (tempLine == "999") {
                break;
            }

            tStudent student;
            size_t pos = 0;
            size_t commaPos;

            //get id
            commaPos = tempLine.find(',', pos);
            if (commaPos != std::string::npos) {
                student.id = std::stoi(tempLine.substr(pos, commaPos - pos));
                pos = commaPos + 1;
            }

            //get Name
            commaPos = tempLine.find(',', pos);
            if (commaPos != string::npos) {
                student.name = tempLine.substr(pos + 1, commaPos - pos - 2); //remove quotes
                pos = commaPos + 1;
            }

            //get LastName
            commaPos = tempLine.find(',', pos);
            if (commaPos != string::npos) {
                student.lastName = tempLine.substr(pos + 1, commaPos - pos - 2); //remove quotes
                pos = commaPos + 1;
            }

            //get Career (stoi with substr for conversion)
            commaPos = tempLine.find(',', pos);
            if (commaPos != string::npos) {
                try {
                    student.career = intToCareer(std::stoi(tempLine.substr(pos, commaPos - pos)));
                    pos = commaPos + 1;
                } catch (...) {
                    cerr << "Error parsing career for student ID " << student.id << endl;
                    continue;
                }
            }

            //get Career Year (stoi with substr)
            if (pos < tempLine.length()) {
                try {
                    student.careerYear = intToCareerYear(stoi(tempLine.substr(pos)));
                } catch (...) {
                    cerr << "Error parsing career year for student ID " << student.id << endl;
                    continue;
                }
            }

            // Insert student into studentList
            studentList->studentArray[index] = student;
            studentList->currentListedStudents++;
            index++;
        }

        completed = true;
        file.close();
    } else {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
    }

    return completed;
}

//writing into a file
bool saveIntoFile(tFilePath path, const tStudentList studentList){

    tWriteFile fileW(path);

    int careerInt;
    int careerYearInt;

    bool completed = false;

    if (fileW.is_open())
    {
        for (size_t i = 0; i < (studentList.currentListedStudents); i++)
        {
            //convert enum into int for saving into file
            careerInt = careerToInt((studentList.studentArray[i]).career);
            careerYearInt = careerYearToInt((studentList.studentArray[i]).careerYear);

            fileW << (studentList.studentArray[i]).id << "," 
                  << "\"" << studentList.studentArray[i].name << "\","
                  << "\"" << studentList.studentArray[i].lastName << "\","
                  << careerInt << "," 
                  << careerYearInt << endl;
        }

        fileW << 999;

        fileW.close();
        completed = true;
    }else{
        cout << "No se pudo salvar la lista de estudiantes al archivo." <<endl;
    }
    
    return completed;
};

//insert a new Student into the list
bool insertStudent(tStudentList* studentList){

    int career, careerYear;
    tStudent student;
    bool completed = false;
   
    if (studentList->currentListedStudents < maxListedStudents)
    {
        (studentList->currentListedStudents > 0) ?
        //check the last student's id and add 1 for the new student's id
        student.id = ( ( studentList->studentArray[studentList->currentListedStudents - 1].id ) + 1 )
        :
            //if the list is empty set new student's id as 1
            student.id = 1;
        ;

        cout << "Por favor, ingrese el nombre del alumno: " << endl;
        getline(cin, student.name);

        cout << "Por favor, ingrese el apellido del alumno: " << endl;
        getline(cin, student.lastName);

        cout << "Seleccione la carrera:\n1. Acompanamiento Terapeutico\n2. Analisis de Sistemas\n3. Gestion Ambiental\n4. Turismo\n";
        checkInputValueForInteger(&career, "Ingrese una opcion valida (1-4): ");
        student.career = intToCareer(career);

        cout << "Seleccione el año:\n1. Primero\n2. Segundo\n3. Tercero\n";
        checkInputValueForInteger(&careerYear, "Ingrese una opcion valida (1-3): ");
        student.careerYear = intToCareerYear(careerYear);

        studentList->studentArray[studentList->currentListedStudents] = student;
        studentList->currentListedStudents++;

        completed = true;
    }
    else
    {
        cout << "El listado interno esta lleno, no se ha podido insertar al alumno." << endl << endl;
    }

    return completed;
};

//show full list of students
void displayAllStudents(tStudentList studentList){

    if (studentList.currentListedStudents > 0)
    {
    
        cout << "Alumnos actualmente registrados: " << endl << endl;

        for (size_t i = 0; i < studentList.currentListedStudents; i++)
        {
            cout << "Alumno: " << (studentList.studentArray[i]).id << endl;
            cout << "Nombre: " << (studentList.studentArray[i]).name << endl;
            cout << "Apellido: " << (studentList.studentArray[i]).lastName << endl;
            cout << "Carrera: " << careerToString((studentList.studentArray[i]).career)<< endl;
            cout << "Año: " << careerYearToString((studentList.studentArray[i]).careerYear) << endl << endl;
        }

    }
    else
    {
        cout << "No hay alumnos actualmente registrados. " << endl << endl;
    }

};

//show a student
void displayStudent(const tStudent* student){

    student ?
        cout << "Nombre :" << student->name << endl
        << "Apellido :" << student->lastName << endl
        << "Carrera :" << careerToString(student->career) << endl
        << "Año :" <<  careerYearToString(student->careerYear) << endl << endl
    :
        cout << "No hay datos que mostrar" << endl << endl;
    ;
}

//find a student by id
const tStudent* findStudentById (const tStudentList studentList, int studentId){

    const tStudent* student = nullptr;

    //binary search
    int start = 0, end = (studentList.currentListedStudents - 1), indexOfHalfElement;
    bool found = false;

    while (!found && (start <= end))
    {
        indexOfHalfElement = (start + end)/2;
        const tStudent* studentInHafPosition = &(studentList.studentArray[indexOfHalfElement]);

        if (studentId == studentInHafPosition->id)
        {
            student = studentInHafPosition;
            found = true;
        }
        else if (studentId < studentInHafPosition->id)
        {
            end = indexOfHalfElement - 1;
        }
        else
        {
            start = indexOfHalfElement + 1;
        }
        
    }

    return student;
}

//delete a student from tStudentList
bool deleteStudent(tStudentList* studentList, int studentId){

    bool completed = false;

    for (size_t i = 0; i < studentList->currentListedStudents; i++)
    {
        if ((studentList->studentArray[i]).id == studentId)
        {

            for (size_t j = i; j < (studentList->currentListedStudents - 1); j++)
            {
                studentList->studentArray[j] = studentList->studentArray[j+1];
            }

            studentList->currentListedStudents--;
            
            completed = true;
            break;
        }
    }

    return completed;
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