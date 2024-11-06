#if !defined(DATE_HPP)
#define DATE_HPP

#include <iostream>
#include <string>

class Date {
private:
    int day, month, year;

public:
    Date();
    Date(int d, int m, int y);

    // Getters
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // Setters
    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

    // Function to get the number of days in the month
    int daysInMonth() const;

    // Check if the date is valid
    bool isValid() const;

    // Display date in DD/MM/YYYY format
    void display() const;

    // Method to convert Date to string
    std::string toString() const;
};

#endif // DATE_HPP
