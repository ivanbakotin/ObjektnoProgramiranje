#include "vector.hpp"

using namespace std;

void MyVector::vector_new (size_t sz) {

    capacity = sz * 2;

    int *newarray = new int[capacity];;

    for (int i = 0; i < sz; i++) {
        newarray[i] = array[i];
    };

    array = newarray;

    delete [] newarray;
};

void MyVector::vector_delete() {
    delete [] array;
};

void MyVector::vector_push_back(int n) {
    array[size] = n;
    size++;
    vector_new(size);
};

void MyVector::vector_pop_back() {
    delete &array[size - 1];
    size--;
};

int& MyVector::vector_front() {
    return array[0];
};

int& MyVector::vector_back() {
    return array[size - 1];
};

size_t MyVector::vector_size()  {
    return size;
};

void MyVector::print_vector() {
    for (size_t i = 0; i < size; ++i) {
        cout << array[i] << " ";
    };
    cout << endl;
};
