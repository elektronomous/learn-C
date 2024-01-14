#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>

// 7.40
class Date {
    friend std::istream &read(std::istream &, Date&);
    // 14.12.txt
    friend std::istream& operator>>(std::istream&, Date&);

    public:
        Date() = default;
        Date(int d, int m, int y):
            day(d), month(m), year(y) { }
        Date(std::istream &);

    private:
    // Computer times (epoch) is begin 1 January 1970 
        int day = 1,
            month = 1,
            year = 1997;
};

std::istream &read(std::istream &is, Date &d) {
    is >> d.day >> d.month >> d.year;
}

Date::Date(std::istream &is) {
    read(is, *this);
}

// 14.12.txt
std::istream& operator>>(std::istream &in, Date &d) {
    in >> d.day >> d.month >> d.year;
    if (!in)
        d = Date();
    
    return in;
}
#endif