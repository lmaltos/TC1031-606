#include "IpAddress.h"
using namespace std;

IpAddress::IpAddress(std::string _ip) {
    ip = _ip;
}

ifstream& operator>>(ifstream& file,IpAddress &v) {
    file >> v.ip;
    return file;
}