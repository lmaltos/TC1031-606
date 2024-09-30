#include <iostream>
#include "linkedlist.h"

template <class T>
void printList(linkedlist<T>&);

using namespace std;
int main() {
    linkedlist<int> L;
    linkedlist<string> S;
    for (int i = 0; i < 10; i++) {
        L.add(rand()%100);
    }
    printList(L);

    S.add("Juan");
    S.add("Pedro");
    S.add("Pablo");
    S.add("Carlos");
    S.add("Karla");
    S.add("Homero");
    printList(S);

    linkedlist<void*> metaList;
    linkedlist<int> *p;
    for (int i = 0; i < 10; i++) {
        p = new linkedlist<int>;
        metaList.add(p);
        for (int j = 0; j < 20; j++) {
            p->add(rand() % 500);
        }
    }
    while(metaList.getSize() > 0) {
        p = (linkedlist<int>*)metaList.get(0); // cast to recover type of pointer
        metaList.remove(0);
        printList(*p);
        delete p;
    }
    metaList.add(&L);
    metaList.add(&S);
    return 0;
}

template <class T>
void printList(linkedlist<T>& L) {
    for (int i = 0; i < L.getSize(); i++) {
        cout << L.get(i) << " ";
    }
    cout << endl;
}