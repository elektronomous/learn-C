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
                // to keep track how many numbers we get
                std::string::size_type pos_found = 0, pos_string = 0;
                std::vector<std::string::size_type> temporaryDate {};

                // get day
                pos_found = formatDate.find_first_of(NUMBERS);
                if (pos_found != std::string::npos) {
                    day = std::stoi(formatDate.substr(pos_found));
                    // advance the position
                    pos_found = formatDate.find_first_not_of(NUMBERS, pos_found);
                }

                // get months
                if (formatDate.find_first_of(ALPHABETS) != std::string::npos) {
                    pos_string = formatDate.find_first_of(" ");
                    if (pos_string != std::string::npos) {
                        for (std::vector<std::string>::size_type n = 0; n<MONTHS.size(); n++) {
                            if (formatDate.compare(0, pos_string, MONTHS[n], 0, pos_string) == 0) {
                                month = n;
                                break;
                            }
                        }
                    }
                } else {
                    pos_found = formatDate.find_first_of(NUMBERS, pos_found);
                    if (pos_found != std::string::npos) {
                        month = std::stoi(formatDate.substr(pos_found));
                        // advance the position
                        pos_found = formatDate.find_first_not_of(NUMBERS, pos_found);
                    }
                }

                // verified the day and month
                if (day > 31)
                    day %= day;
                if (month > 12)
                    month %= month;

                // get year
                pos_found = formatDate.find_first_of(NUMBERS, pos_found);
                if (pos_found != std::string::npos) {
                    year = std::stoi(formatDate.substr(pos_found));
                    pos_found = formatDate.find_first_not_of(NUMBERS, pos_found);
                }
            }

        constexpr unsigned getDay(void) const {
            return day;
        }

        constexpr unsigned getMonth(void) const {
            return month;
        }
        
        constexpr unsigned getYear(void) const {
            return year;
        }

    private:
        /* using in-class initializer */
        unsigned day = 0,
                 month = 0,
                 year = 0;

        std::string formatDate = "",
               dayStr = "",
               monthStr = "",
               yearStr = "";
        
        static const std::string NUMBERS;
        static const std::string ALPHABETS;
};

const std::string Date::NUMBERS("0123456789");
const std::string Date::ALPHABETS("abcdefghijklmnopqrstuvwxyz");
