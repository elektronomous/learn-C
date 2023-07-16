#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>

// 7.40
class Date {
    friend std::istream &read(std::istream &, Date&);

    public:
        // 7.40
        // Date() = default;
        // 7.42
        Date(): Date(1, 1, 1970) { }
        Date(int d, int m, int y):
            day(d), month(m), year(y) { }
        Date(std::istream &);

    private:
    // Computer times (epoch) is begin 1 January 1970 
        int day,
            month,
            year;
};

std::istream &read(std::istream &is, Date &d) {
    is >> d.day >> d.month >> d.year;
}

// 7.40
// Date::Date(std::istream &is) {
//     read(is, *this);
// }
// 7.42
Date::Date(std::istream &is): Date(1, 1, 1970) {
    read(is, *this);
}

#endif