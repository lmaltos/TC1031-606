#include "vector.h"
#include <iostream>
using namespace std;

vector::vector() {
    size = 0;
    data = nullptr;
}

vector::vector(int _size) {
    if (_size > 0) {
        size = _size;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
    }
    else {
        vector();
    }
}
vector::~vector() {
    cout << "~vector():" << data << endl;
    delete[] data;
}

void vector::add(int a) {
    int *p = new int[size + 1];
    cout << "add(): new int " << p << endl;
    for(int i = 0; i < size; i++) {
        p[i] = data[i];
    }
    p[size] = a; // store the new element in the last position
    cout << "add(): delete old " << data << endl;
    delete[] data;
    data = p;
    size++; // increase the size of the vector
}

void vector::remove(int position) {
    if (position < 0 || position >= size)
        return; // index out of range
    int *p = new int[size - 1];
    cout << "remove(): new int " << p << endl;
    for(int i = 0; i < position; i++) {
        p[i] = data[i];
    }
    for(int i = position; i < size; i++) {
        p[i] = data[i+1];
    }
    cout << "remove(): delete old " << data << endl;
    delete[] data;
    data = p; // update the reference of the array
    size--; // decrease the size of the vector
}

void vector::remove2(int position) {
    if (position < 0 || position >= size)
        return; // index out of range
    for(int i = position; i < size - 1; i++) {
        data[i] = data[i+1];
    }
    delete &data[size - 1];
    size--; // decrease the size of the vector
}

int vector::get(int position) {
    if (position < 0 || position >= size)
        return -1; // index out of range
    return data[position];
}

void vector::set(int position, int new_value) {
    if (position < 0 || position >= size)
        return; // index out of range
    data[position] = new_value;
}

int vector::getSize() {
    return size;
}