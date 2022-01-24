#pragma once

#include <iostream>

template<typename T>
class Stack {
private:
	T* list;
	int size;
	int capacity;

public:
	Stack(int capacity);

	void push(int element);
	void pop();
	bool isEmpty();
	void print();
};

template<typename T>
inline Stack<T>::Stack(int capacity) {
	this->list = new T[capacity];
	this->capacity = capacity;
	this->size = 0;
}

template<typename T>
inline void Stack<T>::push(int element) {

	if (this->size >= this->capacity) {

		this->capacity += 1;
		T* newList = new T[this->capacity];

		for (int i = 0; i < this->capacity; i++) {
			newList[i] = this->list[i];
		}

		delete[] this->list;
		this->list = newList;
	}

	this->list[this->size] = element;
	this->size++;
}

template<typename T>
inline void Stack<T>::pop() {
	this->size ? this->size-- : this->size;
}

template<typename T>
inline bool Stack<T>::isEmpty() {
	return this->size;
}

template<typename T>
inline void Stack<T>::print() {
	for (int i = 0; i < this->size; i++) {
		std::cout << this->list[i] << " ";
	}
	std::cout << std::endl;
}
