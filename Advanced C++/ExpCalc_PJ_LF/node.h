#pragma once

#include <iostream>
template <typename T>
class Node
{
private:
	T data;
	Node* next;
public:
	Node(const T &dat);
	~Node();

	void setNext(Node * n);
	Node<T>* getNext();
	void setData(const T & newData);
	T& getData();
};

template <typename T>
Node<T>::Node(const T &dat) :
	data(dat)
{
	next = NULL;
}

template <typename T>
Node<T>::~Node()
{
	next = NULL;
}

template <typename T>
void Node<T>::setNext(Node* n) {
	next = n;
}

template <typename T>
Node<T>* Node<T>::getNext() {
	return next;
}

template <typename T>
void Node<T>::setData(const T& newData) {
	data = newData;
}

template <typename T>
T& Node<T>::getData() {
	return data;
}