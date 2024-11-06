#include "../include/Date.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

Date::Date() : day(0), month(0), year(0) {}

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

// Getters
int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }

// Setters
void Date::setDay(int d) { day = d; }
void Date::setMonth(int m) { month = m; }
void Date::setYear(int y) { year = y; }

// Function to get the number of days in the month
int Date::daysInMonth() const {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            // Check for leap year
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                return 29;
            } else {
                return 28;
            }
        default:
            return 0; // Invalid month
    }
}

// Check if the date is valid
bool Date::isValid() const {
    return (year > 0 && month > 0 && month <= 12 && day > 0 && day <= daysInMonth());
}

// Display date in DD/MM/YYYY format
void Date::display() const {
    std::cout << (day < 10 ? "0" : "") << day << "/"
              << (month < 10 ? "0" : "") << month << "/"
              << year << std::endl;
}

// Method to convert Date to string
std::string Date::toString() const {
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << day << "/"
        << std::setfill('0') << std::setw(2) << month << "/"
        << year;
    return oss.str();
}