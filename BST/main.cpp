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
    do {
        cout << "Value to search: ";
        cin >> n;
        if (a.search(n)) {
            cout << "The value " << n << " is in the BST" << endl;
            break;
        }
        else {
            cout << "The value " << n << " is not in the BST" << endl;
        }
    } while (true);
    return 0;
}