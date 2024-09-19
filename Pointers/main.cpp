#include <iostream>

using namespace std;
void example_of_usage_pointers();
void usage_of_swap();
void swap(int*,int*);
void swap2(int&,int&);

int main() {
    int a[100];
    int *p = a;
    for(int i = 0; i < 100; i++) {
        *(p+i) = rand() % 64;
    }
    cout << "a: " << a << endl;
    for(int i = 100; i < 110; i++) {
        cout << "p+" << i << ": " << (p+i) << endl;
    }
    for(int i = 0; i < 100; i++) {
        cout << a[i] << " ";
        if ((i + 1) %10 == 0)
            cout << endl;
    }
    return 0;
}

void usage_of_swap() {
    int a, b;
    a = 10;
    b = 42;
    cout << "(a,b): (" << a << "," << b << ")" << endl;
    cout << "&a: " << &a << endl
        << "&b: " << &b << endl;
    //swap(&a,&b);
    swap2(a,b);
    /*int tmp = b;
    b = a;
    a = tmp;*/
    cout << "After swap" << endl;
    cout << "(a,b): (" << a << "," << b << ")" << endl;
    cout << "&a: " << &a << endl
        << "&b: " << &b << endl;
}

void swap(int *a,int *b) {
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

void swap2(int &a,int &b) {
    int tmp = b;
    cout << "swap2 " << endl
        << "\ttmp: " << tmp << endl
        << "\t&tmp: " << &tmp << endl
        << "\t&a: " << &a << endl
        << "\t&b: " << &b << endl;
    b = a;
    a = tmp;
}

void example_of_usage_pointers() {
    char c = '3';
    short s = 5;
    int i = 9;

    char * pc = &c;
    short * ps = &s;
    int * pi = &i;
    void * pv;

    cout << "Variables" << endl;
    cout << "c :" << c << endl
        << "s :" << s << endl
        << "i :" << i << endl;
    cout << "sizeof(pv) :" << sizeof(pv) << endl;
    cout << "Pointers to variables" << endl;
    pv = pc; //is the same as pv = &c;
    cout << "pc :" << pc << endl
        << "pv :" << pv << endl
        << "ps :" << ps << endl
        << "pi :" << pi << endl
        << "&pc :" << &pc << endl
        << "&ps :" << &ps << endl
        << "&pi :" << &pi << endl
        << "&pv :" << &pv << endl
        ;
    cout << "Rerefence of poninters" << endl;
    cout << "*pc :" << *pc << endl
        //<< "*pv :" << *pv << endl // not work for void pointers
        << "*ps :" << *ps << endl
        << "*pi :" << *pi << endl;
    (*pi)++;
    *ps *= 3;
    *ps += 7;
    *pc += 15;
    cout << "Variables after indirect modifications" << endl;
    cout << "c :" << c << endl
        << "s :" << s << endl
        << "i :" << i << endl;
    cout << "Pointers to variables" << endl;
    cout << "pc :" << pc << endl
        << "pv :" << pv << endl
        << "ps :" << ps << endl
        << "pi :" << pi << endl
        << "&pc :" << &pc << endl
        << "&ps :" << &ps << endl
        << "&pi :" << &pi << endl
        << "&pv :" << &pv << endl
        ;
}