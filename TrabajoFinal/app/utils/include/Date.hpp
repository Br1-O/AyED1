#if !defined(DATE_HPP)
#define DATE_HPP

    #include <iostream>
    #include <string>
    #include <iomanip>
    #include <sstream>

    class Date {
    private:
        int day, month, year;

    public:
        Date() {}
        Date(int d, int m, int y) : day(d), month(m), year(y) {}

        // Getters
        int getDay() const { return day; }
        int getMonth() const { return month; }
        int getYear() const { return year; }

        // Setters
        void setDay(int d) { day = d; }
        void setMonth(int m) { month = m; }
        void setYear(int y) { year = y; }

        // Function to get the number of days in the month
        int daysInMonth() const {
            switch (month) {
                case 1: case 3: case 5: case 7: case 8: case 10: case 12: // 31 days
                    return 31;
                case 4: case 6: case 9: case 11: // 30 days
                    return 30;
                case 2: // February
                    // Check for leap year
                    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                        return 29; // Leap year
                    } else {
                        return 28; // Non-leap year
                    }
                default:
                    return 0; // Invalid month
            }
        }

        // Check if the date is valid
        bool isValid() const {
            // Implement your logic here to check if the date is valid
            // For example, checking if year/month/day are not zero or invalid
            return (year > 0 && month > 0 && month <= 12 && day > 0 && day <= daysInMonth());
        }

        // Display date in DD/MM/YYYY format
        void display() const {
            std::cout << (day < 10 ? "0" : "") << day << "/"
                    << (month < 10 ? "0" : "") << month << "/"
                    << year << std::endl;
        }

        // Method to convert Date to string
        std::string toString() const {
            std::ostringstream oss;
            oss << std::setfill('0') << std::setw(2) << day << "/" 
                << std::setfill('0') << std::setw(2) << month << "/" 
                << year;
            return oss.str();
        }
    };
#endif //DATE_HPP