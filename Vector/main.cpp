#include <iostream>
#include "vector.h"

using namespace std;
int main() {
    vector v;
    for(int i = 0; i < 10; i++) {
        v.add(i+1);
    }
    v.remove2(4);
    for(int i = 0; i < v.getSize(); i++) {
        cout << v.get(i) << " ";
    }
    cout << endl;
    return 0;
}