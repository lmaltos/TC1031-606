#pragma once
#include "Node.h"

template <class T>
class Graph {
  private:
    Node<T> *first;
    bool directed;
  public:
    Graph(bool);
    ~Graph();
    bool isDirected();
    void addNode(T);
    void addAdyacency(T,T);
    void delNode(T);
    void delAdyacency(T,T);
    Node<T>* findNode(T);
    bool isAdyacency(T,T);
    // ToDo recorrer graph
};

template <class T>
Graph<T>::Graph(bool d){
    directed = d;
    first = nullptr;
}

template <class T>
Graph<T>::~Graph() {
    // ToDo
}

template <class T>
bool Graph<T>::isDirected() {
    return directed;
}

template <class T>
void Graph<T>::addNode(T tag) {
    Node<T> *p = findNode(tag);
    if (p == nullptr) {
        p = new Node<T>(tag);
        Node<T> *q = first;
        if (q == nullptr) {
            first = p;
        }
        else {
            while (q->getNext() != nullptr) {
                q = q->getNext();
            }
            q->setNext(p);
        }
    }
}

template <class T>
void Graph<T>::addAdyacency(T tag1,T tag2){
    Node<T> *a = findNode(tag1);
    Node<T> *b = findNode(tag2);
    if (a != nullptr && b != nullptr) {
        a->setAdyacency(b);
        if (!directed) {
            b->setAdyacency(a);
        }
    }
}

template <class T>
void Graph<T>::delNode(T tag){
    Node<T> *a = first, *b = nullptr;
    while (a != nullptr) {
        if (a->getTag() == tag)
            break;
        b = a;
        a = a->getNext();
    }
    if (a != nullptr) {
        if (b != nullptr) {
            b->setNext(a->getNext());
        }
        else {
            first = a->getNext();
        }
        // ToDo delete adyacencies in other nodes
        delete a;
    }
}

template <class T>
void Graph<T>::delAdyacency(T tag1,T tag2) {
    Node<T> *a = findNode(tag1);
    Node<T> *b = findNode(tag2);
    if (a != nullptr && b != nullptr) {
        if (a->isAdyacency(b)) {
            a->delAdyacency(b);
            if (!directed) {
                b->delAdyacency(a);
            }
        }
    }
}

template <class T>
Node<T> *Graph<T>::findNode(T tag) {
    Node<T> *a = first;
    while (a != nullptr) {
        if (a->getTag() == tag)
            return a;
        a = a->getNext();
    }
    return nullptr;
}

template <class T>
bool Graph<T>::isAdyacency(T tag1,T tag2) {
    Node<T> *a = findNode(tag1);
    Node<T> *b = findNode(tag2);
    if (a != nullptr && b != nullptr) {
        return a->isAdyacency(b);
    }
    return false;
}