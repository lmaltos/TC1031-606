#include <iostream>
#include "Hash.h"
#include "Hash2.h"

using namespace std;

int mod11(int max_size, int dato) {
    //cout << dato << endl;
    return dato % max_size;
}

int f_hash(int max_size, int key) {
    key = key * key * 100;
    return key;
}

int main() {
    Hash_Collisions<int,string> H(1000,f_hash); 

    // ToDo add elements
    // ..
    
    for (int i = 0; i < 64; i++) {
        bool isIn = H.isIn(i);
        cout << i << ": " << (isIn ? 1 : 0) << endl;
    }
    return 0;
}