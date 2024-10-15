#include <iostream>
#include "AVL.h"

using namespace std;
int main() {
    AVL<int> x;
    for (int i = 1; i < 15; i++) {
        x.add(rand()%100);
    }
    x.bylevel();
    return 0;
}

int main_BST() {
    BST<int> a;
    BST<string> s;
    BST<float> f;
    int n;
    for (int i = 0; i < 20; i++) {
        int x = rand() % 50;
        cout << x << " ";
        a.add(x);
    }
    cout << endl;
    a.preorder();
    a.inorder();
    a.postorder();
    a.bylevel();
    int k = 10;
    do {
        cout << "Value to search: ";
        cin >> n;
        if (a.search(n)) {
            cout << "The value " << n << " is in the BST" << endl;
            a.erase(n);
            a.bylevel();
        }
        else {
            cout << "The value " << n << " is not in the BST" << endl;
        }
    } while (--k > 0);
    a.postorder();
    return 0;
}