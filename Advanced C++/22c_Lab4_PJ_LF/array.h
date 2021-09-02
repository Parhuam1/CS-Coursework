// Parhuam Jalalian
// Luke Fields
// Lab 4
// Partner's Contriubution 0 - Both did same work

#pragma once

#include <iostream>
#include <string>

template<typename T>
class Array {
private:
	T * data;
	int size;
public:
	Array(int s);
	Array(Array<T> &source);
	~Array();
	void display();
	int getSize() const;
	T& operator[] (const int index);
	void operator=(const Array<T> &right);
};

template<typename T>	// constructor
Array<T>::Array(int s) : size(s), data(new T[s])  {}

template<typename T>	// copy constructor
Array<T>::Array(Array<T> &source) : size(source.size), data(new T[source.size]) {
	for (int i = 0; i < size; i++) {
		data[i] = source.data[i];
	}
}

template<typename T>	// destructor
Array<T>::~Array() {
	delete[] data;
	data = 0;
}

template<typename T>	// Get size of array
int Array<T>::getSize() const {
	return size;
}



template<typename T>	// getter
void Array<T>::display() {
	for (int i = 0; i < size; i++) {
		std::cout << data[i] << ((i < size - 1) ? " " : "\n");
	}
}

template<typename T>	// data access
T& Array<T>::operator[] (const int index) {
	return data[index];
}

template<typename T>	// assignment op
void Array<T>::operator=(const Array<T> &right) {
	if (this == &right) {
		// make x=x harmless
		return;
	}

	// destroy everything in 'this' and replace it with a copy of right
	delete[] data;

	size = right.size;
	data = new T[size];
	for (int i = 0; i < size; i++) {
		data[i] = right.data[i];
	}
}