#include "Date.h"
#include <iostream>

using namespace std;

int dayPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
Date::Date() {
    day = 1;
    month = 1;
    year = 2000; // 1960
}

Date::Date(int day, int month, int year)
{
    setYear(year);
    setMonth(month);
    setDay(day);
}

void Date::print() {
    cout << day << "/" << month << "/" << year;
}

void Date::setDay(int day) {
    if (day < 1) {
        Date::day = 1;
    }
    else if (day > dayPerMonth[Date::month - 1]) {
        if (Date::month == 2 && year % 4 == 0 && day < 30) {
            // We are good
        }
        else {
            Date::day = 1;
        }
    }
    else {
        Date::day = day;
    }
}

void Date::setMonth(int month) {
    if (month < 1 || month > 12) {
        Date::month = 1; // Default month
    }
    else {
        Date::month = month;
    }
}

void Date::setYear(int) {
    if (year < 2000) {
        Date::year = 2000;
    }
    else {
        Date::year = year;
    }
}

int Date::getDay() {
    return day;
}

int Date::getMonth() {
    return month;
}

int Date::getYear() {
    return year;
}

bool Date::operator<(Date& v) {
    if (year > v.year)
        return false;
    if (year < v.year)
        return true;
    if (month > v.month)
        return false;
    if (month < v.month)
        return true;
    if (day > v.day)
        return false;
    if (day < v.day)
        return true;
    return false;
}

std::ostream& operator<<(std::ostream& os, Date& d) {
    os << d.getDay() << "/" << d.getMonth() << "/" << d.getYear();
    return os;
}