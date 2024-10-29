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

#include "../include/students.hpp"
#include "../include/fileHandling.hpp"
#include "../include/menuHandling.hpp"
#include "../include/utils.hpp"

using namespace std;
using namespace students;
using namespace fileHandling;
using namespace menuHandling;
using namespace utils;

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ MAIN ■■■■■■■■■■■■■■■■■■■■■■■■■■■■//
int main(int argc, char const *argv[])
{
    tStudentList studentList;
    tFilePath path = "./resources/data/students.txt";

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
