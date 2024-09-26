#ifndef VECTOR_H
#define VECTOR_H

class vector {
  private:
    int size;
    int *data;
  public:
    vector(); // default constructor
    vector(int size); // aditional constructor 
    ~vector(); // destructor
    void add(int);
    void remove(int position);
    void remove2(int position);
    int get(int position);
    void set(int position, int new_value);
    int getSize();
};

#endif