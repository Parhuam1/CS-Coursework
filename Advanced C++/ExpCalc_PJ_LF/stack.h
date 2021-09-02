#pragma once
#include "list.h"

// We use protected inheritance so that publically-visible functions from LinkedList
// are protected to Stack.  That means outside code who makes use of Stack will not
// have access to any of those public LinkedList functions...only functions that
// we expressly make public here will be visible/callable to outside code.
template <typename T>
class Stack : protected List<T>
{
public:
	Stack();
	virtual ~Stack();

	void push(const T& item);
	T top();
	T pop();
	bool isEmpty();
	bool isFull();
	int getCount();
	void popAll();
};

template<typename T>
Stack<T>::Stack() {
	List<T>::List();
}

template<typename T>
Stack<T>::~Stack() {
}

template<typename T>
void Stack<T>::push(const T& item) {
	List<T>::addFirst(item);
}

// If nonempty: Fill in "value" with a copy of the top item in the stack and return true
// Otherwise: leave value unchanged, and return false
template<typename T>
T Stack<T>::top() {

	T* item = List<T>::getData(0);
	T value = *item; // call operator=() on type T
	return value;
}

template<typename T>
T Stack<T>::pop() {
	return List<T>::deleteFirst();
}

template<typename T>
bool Stack<T>::isEmpty() {
	return List<T>::isEmpty();
}

template<typename T>
bool Stack<T>::isFull() {
	// Array-based implementations of a stack have the potential to fill up, but not
	// linked list based implementations.  We can just always return false
	return false;
}

template<typename T>
int Stack<T>::getCount() {
	return List<T>::getCount();
}

template<typename T>
void Stack<T>::popAll() {
	return List<T>::emptyOut();
}






