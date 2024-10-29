#if !defined(STUDENTS_HPP)
#define STUDENTS_HPP    

    #include <iostream>
    #include "enums.hpp"

    namespace students
    {
        //■■■■■■■■■■■■■■■■■■■■■■■■■■■■■( structures and types )■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

        //student
        typedef struct 
        {
            unsigned int id;
            std::string name;
            std::string lastName;
            enums::Career career;
            enums::CareerYear careerYear;
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
        
        //■■■■■■■■■■■■■■■■■■■■■■■■■■■■■( interfaces declaration )■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

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

    } // namespace students

#endif // STUDENTS_HPP