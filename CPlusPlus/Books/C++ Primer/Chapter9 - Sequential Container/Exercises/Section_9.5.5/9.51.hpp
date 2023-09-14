#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

std::vector<std::string> MONTHS {
    "",
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "Agustus",
    "September",
    "October",
    "November",
    "Desember"
};


class Date {
    public:
        explicit Date(const std::string &dateString) :
            formatDate(dateString) {
                std::string::size_type pos = 0;
                
                try {
                    // if the format date using word of month like "january", "february" etc.
                    if (formatDate.find_first_of("abcdefghijklmnopqrstuvwxyz") != std::string::npos) {


                        // get months
                        for (std::vector<std::string>::size_type n = 1; n < MONTHS.size(); n++)
                            if (formatDate.find_first_of(MONTHS[n]) != std::string::npos) {
                                month = n;
                                break;
                            }
                        
                        if (!month)
                            throw std::runtime_error("month isn't found in the date format.");                         
                        
                        // get day
                        pos = formatDate.find_first_of("0123456789");
                        if (pos == std::string::npos)
                            throw std::runtime_error("day isn't found in date format.");
                        else {
                            day = std::stoi(formatDate.substr(pos));
                            if (day < 1 && day > 31)
                                throw std::runtime_error("Invalid day for the date format");

                            pos++;
                        }

                        // get year
                        pos = formatDate.substr(pos).find_first_of("0123456789");
                        if (pos == std::string::npos)
                            throw std::runtime_error("Invalid year in the date format.");
                        else
                            year = std::stoi(formatDate.substr(pos));

                    } else {
                        std::vector<std::string::size_type> temporaryDate {};

                        while ((pos = formatDate.find_first_of("0123456789", pos)) != std::string::npos) {
                            temporaryDate.push_back(std::stoi(formatDate.substr(pos))); 
                            pos++;
                        }

                        if (temporaryDate.size() != 3)
                            throw std::runtime_error("Invalid date format.");
                        
                        // get day
                        day = temporaryDate[0];
                        // get month
                        month = temporaryDate[1];
                        // get year
                        year = temporaryDate[2];

                        if (day < 0 and day > 31)
                            throw std::runtime_error("Invalid day in the date format.");
                        if (month < 0 and month > 12)
                            throw std::runtime_error("Invalid month in the date format.");   
                    }
                } catch(std::runtime_error &err) {
                    std::cerr << "Error: " << err.what() << std::endl;
                }
            }

        Date(const std::string &d, const std::string &m, const std::string &y) :
            dayStr(d), monthStr(m), yearStr(y) {
                day = getNumbers(dayStr);
                month = getNumbers(monthStr);
                year = getNumbers(yearStr); 
            }

        unsigned getDay(void) const;
        unsigned getMonth(void) const;
        unsigned getYear(void) const;

    private:
        /* using in-class initializer */
        unsigned day = 0,
                 month = 0,
                 year = 0;

        std::string formatDate = "",
               dayStr = "",
               monthStr = "",
               yearStr = "";
        
        /* get numbers from std::string */
        std::string::size_type getNumbers(const std::string &str) const;
};

std::string::size_type Date::getNumbers(const std::string &str) const {
    return stoi(str.substr(str.find_first_of("+-.0123456789")));
}

unsigned Date::getDay(void) const {
    return day;
}

unsigned Date::getMonth(void) const {
    return month;
}

unsigned Date::getYear(void) const {
    return year;
}
