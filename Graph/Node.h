#pragma once
#include "Adjacency.h"

template <class T>
class Node {
  private:
    T tag;
    Node<T>* next;
    Adjacency<T> *first;
  public:
    Node(T);
    ~Node();
    Node<T>* getNext();
    void setNext(Node<T>*);
    void setAdyacency(Node<T>*);
    void delAdyacency(Node<T>*);
};

template <class T>
Node<T>::Node(T);
template <class T>
Node<T>::~Node();
template <class T>
Node<T>* Node<T>::getNext();
template <class T>
void Node<T>::setNext(Node<T>*);
template <class T>
void Node<T>::setAdyacency(Node<T>*);
template <class T>
void Node<T>::delAdyacency(Node<T>*);