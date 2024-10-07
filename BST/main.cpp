#include <iostream>
#include "BST.h"

using namespace std;
int main() {
    BST<int> a;
    int n;
    for (int i = 0; i < 20; i++) {
        int x = rand() % 50;
        cout << x << " ";
        a.add(x);
    }
    cout << endl;
    int k = 10;
    do {
        cout << "Value to search: ";
        cin >> n;
        if (a.search(n)) {
            cout << "The value " << n << " is in the BST" << endl;
            a.erase(n);
        }
        else {
            cout << "The value " << n << " is not in the BST" << endl;
        }
    } while (--k > 0);
    return 0;
}