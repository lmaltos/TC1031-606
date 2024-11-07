#pragma once
#include "cell.h"

template <class T>
class Hash {
  private:
    cell<T> *p;
    int max_size;
    int (*hash_function)(int,T);
  public:
    Hash(int,int (*)(int,T));
    ~Hash();
    void add(T);
    void del(T);
    bool isIn(T);
};

template <class T>
Hash<T>::Hash(int n,int (*f)(int,T)) {
    max_size = n;
    hash_function = f;
    p = new cell<T>[n];
}
template <class T>
Hash<T>::~Hash() {
    delete[] p;
}

template <class T>
void Hash<T>::add(T data) {
    if (isIn(data)) {
        return; // the element data is already in the hash
    }
    int idx, idx_base = hash_function(max_size,data);
    idx = idx_base;
    while (p[idx].isOcuppied()) {
        idx = (idx + 1) % max_size;
        if (idx == idx_base) {
            return; // the Hash table is fulls
        }
    }
    p[idx].setData(data);
}

template <class T>
void Hash<T>::del(T data) {
    if (!isIn(data)) {
        return; // the element data is not in the hash
    }
    int idx, idx_base = hash_function(max_size,data);
    idx = idx_base;
    while (!p[idx].isEmpty()) {
        if (p[idx].isOcuppied() && p[idx].getData() == data) {
            p[idx].delData();
            return;
        }
        idx = (idx + 1) % max_size;
    }
}

template <class T>
bool Hash<T>::isIn(T data) {
    int idx, idx_base = hash_function(max_size,data);
    idx = idx_base;
    while (!p[idx].isEmpty()) {
        if (p[idx].isOcuppied() && p[idx].getData() == data) {
            return true;
        }
        idx = (idx + 1) % max_size;
        if (idx == idx_base) {
            break;
        }
    }
    return false;
}