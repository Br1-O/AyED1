#ifndef BEEF_HPP
#define BEEF_HPP

#include "Meat.hpp"
#include <string>
#include "../../../utils/include/Date.hpp" // Importing Date class

class Beef : public Meat {
private:
    int grade;

public:
    // Default constructor
    Beef();

    // Constructor for full detail
    Beef(int id, double buyPrice, const std::string& cut, int temp, char unit, double stock, 
         const Date& buyDate, const Date& expireDate, const int supp, const int currentStorageShelf, 
         int grade);

    // Getter for grade
    int getGrade() const;

    // Setter for grade
    void setGrade(int g);

    // Override abstract methods
    void displayInfo() const override;
    int calculateShelfLife() const override; // in days
};

#endif // BEEF_HPP
