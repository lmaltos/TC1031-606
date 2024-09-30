#pragma once

template <class T>
class node {
  private:
    T data;
    node<T> *next;
  public:
    node(T);
    node(T,node<T>*);
    T getData();
    node<T>* getNext();
    void setData(T);
    void setNext(node<T>*);
};

template <class T>
node<T>::node(T _data) {
    data = _data;
    next = nullptr;
}

template <class T>
node<T>::node(T _data,node<T>* _next) {
    data = _data;
    next = _next;
}

template <class T>
T node<T>::getData() {
    return data;
}

template <class T>
node<T>* node<T>::getNext() {
    return next;
}

template <class T>
void node<T>::setData(T new_data) {
    data = new_data;
}

template <class T>
void node<T>::setNext(node<T>* new_next) {
    next = new_next;
}