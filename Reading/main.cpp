#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream s;
    string l;
    string filename = "bitacora.txt";
    if (argc > 1) {
        filename = string(argv[1]);
    }
    string month;
    int day;
    string hour;
    string ip;
    string message;
    int records = 0;

    s.open(filename);
    while (!s.eof()) {
        s >> month >> day >> hour >> ip;
        getline(s,message);
        records++;
    }
    cout << "# of records : " << records << endl;
    cout << "Last record: ";
    cout << month << " " << day << " " << hour << " " << ip << " " << message << endl;
    s.close();
}