#pragma once
#include "Date.h"
#include "IpAddress.h"
#include <string>
#include <fstream>

class Record {
    Date d;
    IpAddress ip;
    std::string message;
  public:
    Record();
    Record(std::string,int,std::string,std::string,std::string);
    friend std::ifstream& operator>>(std::ifstream&,Record &);
};