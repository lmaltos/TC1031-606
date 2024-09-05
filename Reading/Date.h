#pragma once
#include <string>
#include <fstream>
using namespace std;

class Date {
    std::string month;
    int m;
    int day;
    std::string time;
  public:
    Date(std::string,int,std::string);
    friend std::ifstream& operator>>(std::ifstream&,Date &);
};