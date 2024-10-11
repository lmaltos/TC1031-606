#pragma once
#include "BST.h"

template <class T>
class AVL : BST<T> {
  private:
    bool isBalanced(T);
    bool isBalanced(nodeT<T> *p);
    int height(nodeT<T>*);
  public:
    AVL();
    ~AVL();
    void add(T);
};

template <class T>
AVL<T>::AVL() {

}

template <class T>
AVL<T>::~AVL() {
    
}


template <class T>
bool AVL<T>::isBalanced(T data) {
    nodeT<T> *p = root;
    while (p->getData() != data) {
        if (!isBalanced(p)) {
            return false;
        }
        p = p->getData() > data ? p->getLeft() : p->getRight();
    }
    return true;
}

template <class T>
bool AVL<T>::isBalanced(nodeT<T> *p) {
    int hl, hr;
    hl = height(p->getLeft());
    hr = height(p->getRight());
    return !(hl > hr + 1 || hr > hl + 1);
}

template <class T>
void AVL<T>::add(T data) {
    BST::add(data);
    if (isBalnaced(data)) {
        return;
    }
    // look for the pivot
    nodeT<T> *p = root, *pivot;
    while (p->getData() != data) {
        if (!isBalanced(p)) {
            pivot = p;
        }
        p = p->getData() > data ? p->getLeft() : p->getRight();
    }
    if (pivot->getData() > data) {

    }
    else {
        nodeT<T> *A = pivot->getRight();
        if (A->getData() > data) {

        }
        else {
            // RSI
        }
    }
}

template <class T>
int AVL<T>::height(nodeT<T>* p) {
    if (p == nullptr)
        return 0;
    int hl, hr;
    hl = height(p->getLeft());
    hr = height(p->getRight());
    return hl > hr ? hl + 1 : hr + 1;
}