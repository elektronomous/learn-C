#include <string>
#include <vector>
#include <stdexcept>

std::vector<std::string> MONTHS {
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
                try {
                    // if the string date using word of month like "january", "february" etc.
                    if (dateString.find_first_of("abcdefghijklmnopqrstuvwxyz") != std::string::npos) {
                        std::string::size_type pos = 0;

                        // get months
                        for (std::vector<std::string>::size_type n = 0; n < MONTHS.size(); n++)
                            if (dateString.find_first_of(MONTHS[n]) != std::string::npos) {
                                month = n;
                                break;
                            }
                        
                        if (!month)
                            throw std::runtime_error("Invalid date format.");                         
                        
                        // get day
                        pos = dateString.find_first_of("0123456789");
                        if (pos == std::string::npos)
                            throw std::runtime_error("Invalid date format.");
                        else {
                            day = std::stoi(dateString.substr(pos));
                            pos++;
                        }
                        // get year

                    

                    }
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
