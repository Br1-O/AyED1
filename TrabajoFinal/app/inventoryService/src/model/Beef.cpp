#include "../../include/model/Beef.hpp"
#include "../../../utils/include/Date.hpp" // Importing Date class

#include <iostream>
#include <string>

// Default constructor
Beef::Beef() : grade(0) {}

// Constructor for full detail charge (with grade)
Beef::Beef(int id, double buyPrice, const std::string& cut, int temp, char unit, double stock, 
           const Date& buyDate, const Date& expireDate, const int supp, const int currentStorageShelf, 
           int grade)
    : Meat(id, buyPrice, cut, temp, unit, stock, buyDate, expireDate, supp, currentStorageShelf), grade(grade) {}

// Getter for grade
int Beef::getGrade() const {
    return grade;
}

// Setter for grade
void Beef::setGrade(int g) {
    grade = g;
}

// Override displayInfo
void Beef::displayInfo() const {

    Meat::displayInfo();

    std::cout << "Carne de grado : " << grade << std::endl;
}

// Override calculateShelfLife
int Beef::calculateShelfLife() const {
    if (grade == 1) {
        return 15;
    }
    return 10;
}
