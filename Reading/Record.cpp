#include "Record.h"

Record::Record()
 : d("Jan",1,"00:00:01"), ip("256.256.256.256:0001") {

}

Record::Record(std::string month,int day,std::string hour,std::string ip,std::string msg) 
: d(month,day,hour), ip(ip)
{
    message = msg;
}

ifstream& operator>>(ifstream& file,Record &r) {
    //string month;
    //int day;
    //string hour;
    //string ip;
    //file >> month >> day >> hour >> ip;
    //r.d = Date(month,day,hour);
    //r.ip = IpAddress(ip);
    file >> r.d >> r.ip;
    getline(file,r.message);
    return file;
}