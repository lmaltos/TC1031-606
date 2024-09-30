#pragma once
#include "node.h"

template <class T>
class stack {
  private:
    node<T> *top;
  public:
    stack();
    ~stack();
    void push(T);
    void pop();
    T Top();
    bool isFull();
    bool isEmpty();
};

template <class T>
stack<T>::stack() {
    top = nullptr;
}

template <class T>
stack<T>::~stack() {
    node<T> *p = top, *q;
    while (p != nullptr) {
        q = p->getNext();
        delete p;
        p = q;
    }
}

template <class T>
void stack<T>::push(T dato) {
    node<T> *p = new node<T>(dato,top);
    //p->setNext(top);
    top = p;
}

template <class T>
void stack<T>::pop() {
    if (isEmpty())
        return;
    node<T> *p = top->getNext();
    delete top;
    top = p;
}

template <class T>
T stack<T>::Top() {
    return top->getData();
}

template <class T>
bool stack<T>::isFull() {
    return false;
}

template <class T>
bool stack<T>::isEmpty() {
    /*if (t == nullptr)
        return true;
    else
        return false;*/
    return (top == nullptr);
}