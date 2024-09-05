#pragma once
#include <string>
#include <fstream>

class IpAddress {
    std::string ip;
  public:
    IpAddress(std::string);
    friend std::ifstream& operator>>(std::ifstream&,IpAddress &);
};