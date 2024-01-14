#include <iostream>

using namespace std;


const int months1[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int months2[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeapYear(const int &year) {
    // leap year is evenly divided by 4 
    if (!(year % 4))
        return true;
    // if it's divisible by 100, then it must also divisible by 400
    else if (!(year % 100) && !(year % 400))
        return true;
    
    return false;
}

int getRange(const int &d1, const int &m1, const int &y1, const int &d2, const int &m2, const int &y2) {
    int realMonth1 = m1 - 1,
        realMonth2 = m2 - 1;
    int rangeMonths = realMonth2 - realMonth1;
    int rangeYears = y2 - y1;

    // how many months
    int nMonths = rangeMonths + (rangeYears * 12);
    int days = 0;

    for (int startMonth = realMonth1; startMonth < realMonth1 + nMonths; startMonth++) {
        days += months1[startMonth % 12];
        cout << startMonth % 12;
    }
    
    cout << "days: " << days << endl;
    
    for (int startYear = y1; startYear <= y2; startYear++)
        if (isLeapYear(startYear))
            days++;
    
    return days - d1 + d2;
}

void addDay(const int &nDay) {
    int day = 10,
        month = 0,
        year = 2023;
    const int *arrMonths = months1;     // pointer to the months that's in leap Year

    // add our current day to nDay
    day += nDay;

    if (isLeapYear(year))
        arrMonths = months2;
    
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

    cout << day << " " << (month + 1) << " " << year << endl;
}

void substractDay(const int &nDay) {
    int day = 10,
        month = 0,
        year = 2023;
    
    const int *arrMonths = months1;     // pointer to the months that's in leap year

    day -= nDay;

    if (isLeapYear(year))
    arrMonths = months1;

    while (day < 0) {
        day += arrMonths[month];
        month--;

        // if the month goes to negative, then you start from 12
        // and the year is substract by one
        if (month < 0) {
            month = 12;
            year--;
        }
    }

    cout << day << " " << (month + 1) << " " << year << endl;
}

int main(void) {
    cout << getRange(3,1,2023,1,2,2023) << endl;

    return 0;
}