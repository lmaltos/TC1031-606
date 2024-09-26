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
    int get(int position);
    void set(int position, T new_value);
    int getSize();
};

template <class T>
linkedlist<T>::linkedlist() {
    size = 0;
    next = nullptr;
};

template <class T>
linkedlist<T>::~linkedlist() {
    // ToDo
}

template <class T>
void linkedlist<T>::add(T data) {
    node<T> n = new node<T>(data);
    n.setNext(head);
    head = n;
}

template <class T>
void linkedlist<T>::remove(int position);

template <class T>
int linkedlist<T>::get(int position);

template <class T>
void linkedlist<T>::set(int position, T new_value);

template <class T>
int linkedlist<T>::getSize(){
    return size;
}