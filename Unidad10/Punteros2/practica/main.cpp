#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include "utils.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    //■■■■■ Menu Options ■■■■■//
    const int sizeOptions = 8;
    std::string options[sizeOptions] = 
    {
        "Ejercicio 1", 
        "Ejercicio 2", 
        "Ejercicio 3", 
        "Ejercicio 4", 
        "Ejercicio 5", 
        "Ejercicio 6", 
        "Ejercicio 7",
        "Salir"
    };

    //■■■■■ Content of each Option ■■■■■//
    const vector<function<void()>> optionsBodies =
    {
        //■■■■■ exercise 1 ■■■■■//
        [options]()
        {
            cout << options[0] << endl << endl;

            cout << "Consigna: " 
            << endl 
            << "1. Rellenar un array de 10 numeros, posteriormente utilizando punteros indicar cuales son numeros pares y su posicion en memoria."
            << endl << endl;

            int nums[10] = {1,2,3,4,5,6,7,8,9,10};

            int* pairs = new int[10];

            int* tempNum = nullptr;

            int currentPairIndex = 0;

            for (size_t i = 0; i < 10; i++)
            {
                tempNum = &nums[i];

                if(*tempNum % 2 == 0){

                    pairs[currentPairIndex] = nums[i];
                    currentPairIndex++;
                }
            }

            cout << "Los numeros pares presentes en el array inicial son:";

            if (currentPairIndex != 0)
            {
                for (size_t i = 0; i < currentPairIndex; i++)
                {
                    cout << endl 
                    << pairs[i] << " con la direccion en memoria : " << &(pairs[i]);
                }
            }
            else
            {
                cout << endl << "No se encontraron numeros pares en la lista brindada";
            }

            delete[] pairs;
        },
        //■■■■■ exercise 2 ■■■■■//
        [options]()
        {
            cout << options[1] << endl << endl;

            cout << "Consigna: " 
            << endl 
            << "2. : Rellenar un arreglo con n numeros, posteriormente utilizando punteros determinar el menor elemento del vector."
            << endl << endl;

            int nums = 0;

            utils::inputValidation(&nums, "Cuantos numeros planea comparar?", "Debe ingresar un numero entero.");

            int* numArray = new int[nums];

            int tempNum;
            int loadedNumbers = 0;

            for (size_t i = 0; i < nums; i++)
            {
                utils::inputValidation(&tempNum, "Agrege un numero a la lista: ", "Debe ingresar un numero entero.");

                numArray[loadedNumbers] = tempNum;
                loadedNumbers++;
            }

            int* minorNumber = &numArray[0];

            for (size_t i = 1; i < loadedNumbers; i++)
            {
                if (numArray[i] < *minorNumber)
                {
                    minorNumber = &numArray[i];
                }
            }

            cout << "El menor numero de los numeros ingresados es: " << *minorNumber << " ." << endl;
            
            delete[] numArray;
            minorNumber = nullptr;
        },
        //■■■■■ exercise 3 ■■■■■//
        [options]()
        {
            cout << options[2] << endl << endl;

            cout << "Consigna: " 
            << endl 
            << "3. Pedir al usuario N numeros, almacenarlos en un arreglo dinamico posteriormente ordenar los numeros en orden ascendente y mostrarlos en pantalla."
            << "NOTA: Utilizar cualquier metodo de ordenamiento."
            << endl << endl;

            int nums = 0;

            utils::inputValidation(&nums, "Cuantos numeros planea ordenar?", "Debe ingresar un numero entero.");

            int* numArray = new int[nums];

            int tempNum;
            int loadedNumbers = 0;

            for (size_t i = 0; i < nums; i++)
            {
                utils::inputValidation(&tempNum, "Agrege un numero a la lista: ", "Debe ingresar un numero entero.");

                numArray[loadedNumbers] = tempNum;
                loadedNumbers++;
            }

            //ordering
            for (int i = 0; i < nums - 1; i++) {
                for (int j = 0; j < nums - i - 1; j++) {
                    if (numArray[j] > numArray[j + 1]) {
                        //switch elements
                        int temp = numArray[j];
                        numArray[j] = numArray[j + 1];
                        numArray[j + 1] = temp;
                    }
                }
            }

            cout << "\nNúmeros ordenados en orden ascendente:" << endl;
            for (int i = 0; i < nums; i++) {
                cout << numArray[i] << " ";
            }
            cout << endl;

            // Liberar la memoria asignada
            delete[] numArray;

        },
        //■■■■■ exercise 4 ■■■■■//
        [options]()
        {
            cout << options[3] << endl << endl;

            cout << "Consigna: " 
            << endl 
            << "4. Pedir una cadena de caracteres (string) al usuario, e indicar cuantas veces aparece la vocal a,e,i,o,u; en la cadena de caracteres."
            << "NOTA: Usar punteros"
            << endl << endl;

            string* inputWord = new string("");

            utils::inputValidation(inputWord, "Ingrese la palabra a analizar: ", "Debe ingresar una palabra.");

            int* vocalsInWord = new int(0);

            for (auto &&letter : *inputWord)
            {
                if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
                {
                    (*vocalsInWord)++;
                }
            }

            cout << endl << "La palabra ingresada tiene " << *vocalsInWord << " vocales." << endl;

            delete inputWord;
            delete vocalsInWord;
        },
        //■■■■■ exercise 5 ■■■■■//
        [options]()
        {
            cout << options[4] << endl << endl;

            cout << "Consigna: " 
            << endl 
            << "5. Realice un programa que calcule la suma de dos matrices dinamicas."
            << endl << endl;

            int** matrix1 = new int*[2];  // Allocate an array of pointers (for rows)
            for (int i = 0; i < 2; ++i) {
                matrix1[i] = new int[2];  // Allocate each row
            }

            // Initialize values
            matrix1[0][0] = 1;
            matrix1[0][1] = 2;
            matrix1[1][0] = 3;
            matrix1[1][1] = 4;

            int** matrix2 = new int*[2];  // Allocate an array of pointers (for rows)
            for (int i = 0; i < 2; ++i) {
                matrix2[i] = new int[2];  // Allocate each row
            }

            // Initialize values
            matrix2[0][0] = 4;
            matrix2[0][1] = 3;
            matrix2[1][0] = 2;
            matrix2[1][1] = 1;

            int** matrix3 = new int*[2];  // Allocate an array of pointers (for rows)
            for (int i = 0; i < 2; ++i) {
                matrix3[i] = new int[2];  // Allocate each row
            }

            // Initialize values
            matrix3[0][0] = matrix1[0][0] + matrix2[0][0];
            matrix3[0][1] = matrix1[0][1] + matrix2[0][1];;
            matrix3[1][0] = matrix1[1][0] + matrix2[1][0];;
            matrix3[1][1] = matrix1[1][1] + matrix2[1][1];;

            cout << "La matriz uno es: [ ";

            for (size_t i = 0; i < 2; i++)
            {
                for (size_t j = 0; j < 2; j++)
                {
                    cout << matrix1[i][j] << " ";
                }
            }

            cout << "]" << endl << endl;

            cout << "La matriz dos es: [ ";

            for (size_t i = 0; i < 2; i++)
            {
                for (size_t j = 0; j < 2; j++)
                {
                    cout << matrix2[i][j] << " ";
                }
            }

            cout << "]" << endl << endl;

            cout << "La suma de las dos matrices da como resultado: [ ";

            for (size_t i = 0; i < 2; i++)
            {
                for (size_t j = 0; j < 2; j++)
                {
                    cout << matrix3[i][j] << " ";
                }
            }

            cout << "]" << endl;

            delete[] matrix1;
            delete[] matrix2;
            delete[] matrix3;

        },
        //■■■■■ exercise 6 ■■■■■//
        [options]()
        {
            cout << options[5] << endl << endl;

            cout << "Consigna: " 
            << endl 
            << "6. Realice un programa que lea una matriz dinamica de NxM y cree su matriz traspuesta. La matriz traspuesta es aquella en la que la columna i era la fila i de la matriz original."
            << endl << endl;

            int n = 0;
            int m = 0;

            utils::inputValidation(&n, "Ingrese el numero de filas de la matriz: ", "Debe ingresar un numero entero.");
            utils::inputValidation(&m, "Ingrese el numero de columnas de la matriz: ", "Debe ingresar un numero entero.");

            //create dinamic matrix
            int** matrix = new int*[n];

            for (size_t i = 0; i < n; i++)
            {
                matrix[i] = new int[m];
            }

            //input matrix
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    string message = "Ingrese el valor para la posicion [" + to_string(i) + "][" + to_string(j) + "]: ";
                    utils::inputValidation(&matrix[i][j], message, "Debe ingresar un numero entero.");
                }
            }

            //create traspose matrix
            int** transposedMatrix = new int*[m];
            for (int i = 0; i < m; i++) {
                transposedMatrix[i] = new int[n];
            }

            //traspose matrix
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    transposedMatrix[j][i] = matrix[i][j];
                }
            }

            //print original
            cout << "\nMatriz original:" << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }

            //print traspose
            cout << "\nMatriz traspuesta:" << endl;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    cout << transposedMatrix[i][j] << " ";
                }
                cout << endl;
            }

            for (int i = 0; i < n; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;

            for (int i = 0; i < m; i++) {
                delete[] transposedMatrix[i];
            }
            delete[] transposedMatrix;
        },
        //■■■■■ exercise 7 ■■■■■//
        [options]()
        {
            cout << options[6] << endl << endl;

            cout << "Consigna: " 
            << endl 
            << "7. Hacer una estructura llamada alumno, en la cual se tendran los siguientes" << endl
            << "Campos: Nombre, edad, promedio, pedir datos al usuario para 3 alumnos, comprobar cuál de los 3 tiene el mejor promedio y posteriormente imprimir los datos del alumno." << endl
            << "NOTA: Usar punteros a estructura."
            << endl << endl;

            //student struct
            typedef struct 
            {
                string name;
                int age;
                float avgGrade;
            } tStudent;

            //student dinamic array
            typedef tStudent* tStudentArray;
            int maxStudents = 3;
            tStudentArray studentArray = new tStudent[maxStudents];

            //temp variables
            string tempName;
            int tempAge;
            float tempAvgGrade;
            string message;

            //user input
            for (size_t i = 0; i < maxStudents; i++)
            {
                message =  "Agrege el nombre del alumno " + to_string(i + 1) + " :";
                utils::inputValidation(&tempName, message, "Debe ingresar una palabra.");
                message =  "Agrege la edad del alumno: ";
                utils::inputValidation(&tempAge, message, "Debe ingresar un numero entero.");
                message =  "Agrege el promedio del alumno: ";
                utils::inputValidation(&tempAvgGrade, message, "Debe ingresar un numero entero o decimal.");

                (studentArray[i]).name = tempName;
                (studentArray[i]).age = tempAge;
                (studentArray[i]).avgGrade = tempAvgGrade;
            }

            tStudent* bestAvgGradeStudent = new tStudent(studentArray[0]);

            for (size_t i = 1; i < maxStudents; i++)
            {
                if(bestAvgGradeStudent->avgGrade < studentArray[i].avgGrade){
                    bestAvgGradeStudent = &studentArray[i];
                }
            }

            cout << "El estudiante de mejor promedio es: " << bestAvgGradeStudent->name 
            << ", con un promedio de: " << bestAvgGradeStudent->avgGrade 
            << ", y una edad de: " << bestAvgGradeStudent->age << endl << endl;
            
            delete[] studentArray;
            bestAvgGradeStudent = nullptr;
        }
    };

    //■■■■■ call main function to handle menu display and input ■■■■■//
    utils::getSelectedOption(sizeOptions, options, optionsBodies);

    return 0;
}
