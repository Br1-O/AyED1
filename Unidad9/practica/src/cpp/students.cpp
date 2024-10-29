#include <iostream>
#include <string>

#include "../../include/students.hpp"
#include "../../include/utils.hpp"
#include "../../include/enums.hpp"

using namespace std;
using namespace enums;
using namespace utils;

namespace students
{
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
} // namespace students