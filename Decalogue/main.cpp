#include <iostream>
#include <vector>
using namespace std;

void Decalogue01();
void Decalogue02();
void Decalogue03();
void Decalogue04();
void Decalogue05();
void Decalogue06();
void Decalogue07();
void Decalogue09();
void Decalogue10();

int main() {
    int n;
    int *p;
    int *a;
    cin >> n;
    vector<int> q;
    a = new int[n];
    cout << a << endl;
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 50;
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 10; i++) {
        p = a + i;
        cout << p << ": " << *p << endl;
    }
    p = a;
    for (int i = 0; i < 10; i++) {
        cout << p << ": " << p[i] << endl;
    }
    //delete[] a;
    return 0;
}

void Decalogue01() {
    int *p;
    cout << "&p: " << &p << endl
        << "p: " << p << endl;
    p = new int;
    cout << "p = new int;" << endl;
    cout << "&p: " << &p << endl
        << "p: " << p << endl;
    *p = 5;
    cout << "*p = 5;" << endl;
    delete p;
    cout << "delete p;" << endl;
    cout << "&p: " << &p << endl
        << "p: " << p << endl;
    //delete p; // second delete : free(): double free detected in tcache 2
}

void Decalogue02() {
    int *p,*q,*r;
    cout << "&p: " << &p << endl
        << "&q: " << &q << endl
        << "&r: " << &r << endl
        << "p: " << p << endl
        << "q: " << q << endl
        << "r: " << r << endl;
    p = new int;
    cout << "p = new int;" << endl;
    q = r = p;
    cout << "q = r = p;" << endl;
    cout << "&p: " << &p << endl
        << "&q: " << &q << endl
        << "&r: " << &r << endl
        << "p: " << p << endl
        << "q: " << q << endl
        << "r: " << r << endl;
    *p = 5;
    cout << "*p = 5;" << endl;
    cout << "*q: " << *q << endl;
    p = new int[1000];
    delete r;
    cout << "p = new int;" << endl;
    cout << "delete r;" << endl;
    cout << "&p: " << &p << endl
        << "&q: " << &q << endl
        << "&r: " << &r << endl
        << "p: " << p << endl
        << "q: " << q << endl
        << "r: " << r << endl;
    delete[] p;
}

int* fun3() {
    int *p = new int;
    cout << "&p: " << &p << endl
        << "p: " << p << endl;
    *p = 42;
    return p;
}

void Decalogue03() {
    int *q;
    q = fun3();
    cout << "&q: " << &q << endl
        << "q: " << q << endl
        << "*q: " << *q << endl;
    delete q;
}

void Decalogue04() {
    int *p,*q = nullptr,*r = NULL;
    cout << "p: " << p << endl
        << "q: " << q << endl
        << "r: " << r << endl;
    delete r;
    delete q;
    //delete p; // munmap_chunk(): invalid pointer
}

void Decalogue05() {
    int *p = nullptr, *q;
    int a;
    q = &a;
    cout << "p: " << p << endl
        << "q: " << q << endl;
    //delete p; // munmap_chunk(): invalid pointer
    //delete q; // free(): invalid pointer
}

void Decalogue06() {
    int *p;
    vector<int> *v;
    // p = new int;
    //*p = 42; // Segmentation fault (core dumped)
    v->push_back(12);
}

void Decalogue07() {
    int *p = nullptr,*q = nullptr;
    p = new int[2];
    for (int i = 0; i < 10; i++) {
        q = p;
        cout << "p: " << p << endl;
        p = new int[2+i];
        cout << "p: " << p << endl
            << "q: " << q << endl;
        delete[] q;
    }
    delete[] p;
}

void Decalogue09() {
    int *p = nullptr, *q = nullptr;
    if (p != nullptr) {
        delete p;
    }
    if (p == q) {
        cout << "p is pointing to the same place as q" << endl;
    }
    else {
        cout << "p is pointing to a different place that q" << endl;
    }
}

void Decalogue10() {
    vector<int> *v;
    v = new vector<int>;
    v->push_back(12);
    cout << "v->size(): " << v->size() << endl;
    delete v;
}