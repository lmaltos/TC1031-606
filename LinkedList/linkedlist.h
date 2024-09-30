#pragma once
#include "node.h"

template <class T>
class linkedlist {
  private:
    node<T> *head;
    int size;
  public:
    linkedlist();
    ~linkedlist();
    void add(T);
    void remove(int position);
    T get(int position);
    void set(int position, T new_value);
    int getSize();
};

template <class T>
linkedlist<T>::linkedlist() {
    size = 0;
    head = nullptr;
};

#include <iostream>
using namespace std;
template <class T>
linkedlist<T>::~linkedlist() {
    node<T> *p,*q;
    p = head;
    while (p != nullptr) {
        q = p->getNext();
        cout << "~linkedlist(): delete " << p << " " << p->getData() << endl;
        delete p;
        p = q;
    }
}

template <class T>
void linkedlist<T>::add(T data) {
    node<T> *n = new node<T>(data);
    n->setNext(head);
    cout << "add(): " << n << " " << n->getData() << endl;
    head = n;
    size++;
}

template <class T>
void linkedlist<T>::remove(int position) {
    if (position < 0 || position >= size)
        return;
    node<T> *prev = nullptr, *p;
    p = head;
    for (int i = 0; i < position; i++) {
        prev = p;
        p = p->getNext();
    }
    if (prev != nullptr) {
        prev->setNext(p->getNext());
    }
    else { // the first element is removed
        head = p->getNext();
    }
    cout << "remove(): " << p << " " << p->getData() << endl;
    delete p;
    size--;
}

template <class T>
T linkedlist<T>::get(int position){
    if (position < 0 || position >= size)
        throw "index out of range";
    node<T> *p;
    p = head;
    for (int i = 0; i < position; i++) {
        p = p->getNext();
    }
    return p->getData();
}

template <class T>
void linkedlist<T>::set(int position, T new_value) {
    if (position < 0 || position >= size)
        return;
    node<T> *p;
    p = head;
    for (int i = 0; i < position; i++) {
        p = p->getNext();
    }
    p->setData(new_value);
}

template <class T>
int linkedlist<T>::getSize(){
    return size;
}