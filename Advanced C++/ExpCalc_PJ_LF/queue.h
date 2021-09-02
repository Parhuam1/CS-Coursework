#pragma once

#include "list.h"

template <typename T>
class Queue : protected List<T>
{
public:
	Queue();                                   // default constructor
	~Queue();                                  // destructor
	Queue(const Queue&);                       // copy constructor

	void enqueue(const T& item);  // Puts item at end of queue
	T dequeue();  // Takes first item out of queue

	T* queueFront();  // return Front 
	T* queueRear();   // return Rear

	void emptyQueue(); // delete all items
	int queueCount();  // number of items in Queue
	bool isEmpty() const;
	bool isFull() const;
	void displayQueue();
};


// default constructor
template<typename T>
Queue<T>::Queue()
{

}

// destructor
template<typename T>
Queue<T>::~Queue()
{

}

// copy constructor
template<typename T>
Queue<T>::Queue(const Queue& src) :
	List(src)
{

}


// Puts item at end of queue
template<typename T>
void Queue<T>::enqueue(const T& item)
{
	List<T>::addLast(item);
}


// Takes first item out of queue
template<typename T>
T Queue<T>::dequeue()
{
	if (isEmpty())
	{
		throw "Cannot dequeue from an empty queue";
	}

	return List<T>::deleteFirst();
}

// Returns Front Node
template<typename T>
T* Queue<T>::queueFront() {

	T* result = List<T>::getFirst();
	if (result == NULL) {
		// there was no queue front
		throw "Cannot return the front of an empty queue";
	}

	return result;
}

// Returns Rear Node
template<typename T>
T* Queue<T>::queueRear()
{
	T* result = List<T>::getLast();
	if (result == NULL) {
		// there was no queue rear
		throw "Cannot return the rear of an empty queue";
	}

	return result;
}

template<typename T>
void Queue<T>::emptyQueue()
{
	List<T>::emptyOut();
}

template<typename T>
int Queue<T>::queueCount()
{
	return List<T>::getCount();
}

// check if queue is empty
template<typename T>
bool Queue<T>::isEmpty() const
{
	return List<T>::isEmpty();
}

// check if queue is full
template<typename T>
bool Queue<T>::isFull() const
{
	return List<T>::isFull();
}

template<typename T>
void Queue<T>::displayQueue()
{
	if (isEmpty()) {
		throw(" The queue is empty.\n");
	}

	// basically same code as list.display() printed on a single line space seperated
	Node<T> *temp = List<T>::findNodeByPosition(0);
	while (temp != NULL)
	{
		// We are assuming that code exists to cout something of type T.
		// Depending on type T, someone may need to have written that already.
		std::cout << temp->getData() << (temp->getNext() != NULL ? " " : "\n");
		temp = temp->getNext();
	}
}
