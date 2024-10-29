#if !defined(FILE_HANDLING_HPP)
#define FILE_HANDLING_HPP

    #include <iostream>
    #include <fstream>
    #include "students.hpp"

    namespace fileHandling
    {
        //■■■■■■■■■■■■■■■■■■■■■■■■■■■■■( structures and types )■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

        //type for reading/writing file
        typedef std::ifstream tReadFile;
        typedef std::ofstream tWriteFile;
        typedef std::string tFilePath;

        //■■■■■■■■■■■■■■■■■■■■■■■■■■■■■( interfaces declaration )■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

        //reading and loading a file
        bool loadFile(tFilePath path, students::tStudentList* studentList);

        //writing into a file
        bool saveIntoFile(tFilePath path, const students::tStudentList studentList);

    } // namespace fileHandling

#endif // FILE_HANDLING_HPP
