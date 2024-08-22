#ifndef DATE_H
#define DATE_H
#include <ostream>

class Date {
  private:
    int day;
    int month;
    int year;
  public:
    Date(); // Default constructor
    Date(int,int,int);
    void print();
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    int getDay();
    int getMonth();
    int getYear();
    bool operator<(Date&);
};

std::ostream& operator<<(std::ostream&, Date&);

#endif