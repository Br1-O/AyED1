#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "../../include/fileHandling.hpp"
#include "../../include/students.hpp"
#include "../../include/enums.hpp"

using namespace std;
using namespace students;
using namespace enums;

namespace fileHandling
{
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

} // namespace fileHandling
