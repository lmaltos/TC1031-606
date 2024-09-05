#include <iostream>
#include <fstream>
#include "Record.h"
#include "Date.h" // those libraries already are included in record
#include "IpAddress.h"
#include <vector>

using namespace std;
void readData(string,vector<Record>&);

int main(int argc, char *argv[]) {
    string l;
    string filename = "bitacora.txt";
    if (argc > 1) {
        filename = string(argv[1]);
    }
    vector<Record> records;
    readData(filename,records);
    cout << "# of records : " << records.size() << endl;
}

void readData(string filename, vector<Record> &records) {
    ifstream s;
    s.open(filename); // we can check before if the file already exists
    Record r;
    while (!s.eof()) {
        s >> r; // using the overload of operator >> to make an easy reading
        records.push_back(r);
    }
    s.close();
}