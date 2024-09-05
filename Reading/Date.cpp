#include "Date.h"

int monthtoint(string month) {
    string months[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    for (int i = 0; i < 12; i++) {
        if (month == months[i])
            return i + 1;
    }
    return -1;
}

Date::Date(std::string _m,int d,std::string hms) {
    month = _m;
    day = d;
    time = hms;
    m = monthtoint(_m);
}

ifstream& operator>>(ifstream& file,Date &d) {
    file >> d.month >> d.day >> d.time;
    d.m = monthtoint(d.month);
    return file;
}