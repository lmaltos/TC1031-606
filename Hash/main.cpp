#include <iostream>
#include "Hash.h"

using namespace std;

int mod11(int max_size, int dato) {
    //cout << dato << endl;
    return dato % max_size;
}

int main() {
    Hash<int> h(11,mod11);

    h.add(7);
    h.add(17);
    h.add(6);
    h.add(33);
    h.add(28);
    h.add(52);

    for (int i = 0; i < 64; i++) {
        bool isIn = h.isIn(i);
        cout << i << ": " << (isIn ? 1 : 0) << endl;
    }
    return 0;
}