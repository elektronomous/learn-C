#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>
#include <algorithm>

// we appended 0, so we can start from 1 - 12
const int months1[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int months2[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date operator+(const Date &d, const int &nDay);
Date operator-(const Date &d, const int &nDay);
int operator-(const Date &dl, const Date &dr);
bool operator>(const Date &dl, const Date &dr);
// 14.16.txt
bool operator==(const Date &, const Date &);
bool operator!=(const Date &, const Date &);

// 7.40
class Date {
    friend std::istream &read(std::istream &, Date&);
    // 14.12.txt
    friend std::istream& operator>>(std::istream&, Date&);
    // 14.15.txt
    friend Date operator+(const Date &d, const int &nDay);
    friend Date operator-(const Date &d, const int &nDay);
    // if you want know the range between the date
    friend int operator-(const Date &dl, const Date &dr);
    // if you want know that your Date has more recent then the other Date
    friend bool operator>(const Date &dl, const Date &dr);
    // 14.16.txt
    friend bool operator==(const Date &, const Date &);
    friend bool operator!=(const Date &, const Date &);
    

    public:
        Date() = default;
        Date(int d, int m, int y):
            day(d-1), month(m), year(y) {
                if (day <= 0) day = 1;
                if (month <= 0) month = 0;
                if (year <= 0) year = 1997;
            }
        Date(std::istream &);

        // 14.15.txt
        Date& operator+=(const int &nDay);
        Date& operator-=(const int &nDay);

        /* why we define these member function: If you want to add or
           substract the the month, or the year
        */
        Date& operator+=(const Date &d);
        Date& operator-=(const Date &d);



    private:
    // Computer times (epoch) is begin 1 January 1970 
        signed int day = 1,
                   month = 0,       // we start from 0 because we use this as the index to month
                   year = 1997;
        
        
};
// find the leap-year
bool isLeapYear(const int &year) {
    // leap year is evenly divided by 4 
    if (!(year % 4))
        return true;
    // if it's divisible by 100, then it must also divisible by 400
    else if (!(year % 100) && !(year % 400))
        return true;
    
    return false;
}
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

// 14.15.txt
Date& Date::operator+=(const int &nDay) {

    // add our current day to nDay
    day += nDay;
    const int *arrMonths = months2;     // pointer if the year is in leapYear 

    if (isLeapYear(year))
        arrMonths = months1;

    while (day > arrMonths[month]) {
        day -= arrMonths[month];
        month++;
    }

    // we start counting the month from 0,
    // so we use the 11 as the end of the counting years
    while (month > 11) {
        month -= 11;
        year++;
    }

    return *this;
}


// 14.15.txt
Date& Date::operator-=(const int &nDay) {
    // substract our current day to nDay
    day -= nDay;
    const int *arrMonths = months2;     // by default we're not in the leap Year

    if (isLeapYear(year))
        arrMonths = months1;

    while (day < 0) {
        day += arrMonths[month];
        month--;

        if (month < 0) {
            month = 12;
            year--;
        }
    }

    if (year < 0) *this = Date();

    return *this;
}

Date& Date::operator+=(const Date &d) {
    // we start counting from year and the months
    year += d.year;
    month += d.month;

    // use the overloaded of overloaded operator+=
    this->operator+=(d.day);

    return *this;
}

Date& Date::operator-=(const Date &d) {
    // we start counting from year and the months
    if (d.year > year) {
        *this = Date();
        return *this;
    }

    year -= d.year;
    month -= d.month;
    this->operator-=(d.day);

    return *this;
}

Date operator+(const Date &d, const int &nDay) {
    Date sum = d;
    sum += nDay;
    return sum;
}

Date operator-(const Date &d, const int &nDay) {
    Date sum = d;
    sum -= nDay;
    return sum;
}

bool operator>(const Date &dl, const Date &dr) {
    if (dl.year > dr.year)
        return true;
    else if (dl.year == dr.year) {
        if (dl.month > dr.month)
            return true;
        else if (dl.day > dr.day)
            return true;
    }

    return false;
}

int operator-(const Date &dl, const Date &dr) {
    if (dl > dr)
        return 0;
    
    int nMonths = 0,    // how many months in that range
        days = 0;       // how many days in that months
    
    int rangeYear = dr.year - dl.year,
        rangeMonth = dr.month - dl.month;
    
    // how many months in the range that rangeYears
    int nMonths = rangeYear + (rangeYear * 12);

    // how many days in that range of months    
    for (int startMonth = dl.month; startMonth < dl.month + nMonths; startMonth++)
        days += months2[startMonth % 12];
    
    // find if the range years have leapYear
    for (int startYear = dl.year; startYear < dr.year; startYear++)
        if (isLeapYear(startYear))
            days++;                  // we add 1 because the leap year show 366 days
    
    return days - dl.day + dr.day;
}

// 14.16.txt
bool operator==(const Date &dl, const Date &dr) {
    return (dl.day == dr.day && 
        dl.month == dr.month &&
        dl.year == dr.year);
}

bool operator!=(const Date &dl, const Date &dr) {
    return !(dl == dr);
}

#endif

/* 

How your operator- works?
If you want to know how many months in range 10/04/2023 - 15/07/2027 for example:

    day1 = 10
    month1 = 04
    year1 = 2023

    day2 = 15
    month2 = 07
    year2 = 2027

to get how many months in that range, you'll count it using this formula:
    
    rangeMonth = (month2 - month1) + ((year2 - year1) * 12);

why do you substract the day1 and then add day2 in the return statement?
well you got the range of the months, now if you substract the day1 then you
get the reminder of the day in that first month.

before add day2 get you result of the range of the days, if you substract month
then you get the month before the month you want to point. for example: month 2 (feb)
substracted by month 1 (jan), you get 1, which is January. if you start from day 3, 
then the reminder of this month will be 31 - 3 = 28, now if you point to month 2 (feb)
that its day is 5, then you just need to add that 5 to your 28 so that you get the final
result of the range of the days which is 33

*/