#if !defined(MENU_HANDLING_HPP)
#define MENU_HANDLING_HPP

    #include <iostream>
    #include "students.hpp"
    #include "fileHandling.hpp"

    namespace menuHandling
    {
        //■■■■■■■■■■■■■■■■■■■■■■■■■■■■■( interfaces declaration )■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

        //funtion to display the menu
        void displayMenu();

        //get selected option from user
        void getSelectedOptionFromUser(int* selectedOption, students::tStudentList* studentList, fileHandling::tFilePath path);

    } // namespace menuHandling

#endif // MENU_HANDLING_HPP
