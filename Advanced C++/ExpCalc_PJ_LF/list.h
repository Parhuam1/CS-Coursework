#pragma once
#include "node.h"

// Singly-linked list
template <typename T>
class List
{
private:
	int count;
	Node<T>* head;
	Node<T>* tail;

protected:
	// moved to protected for access to in queue
	Node<T>* findNodeByPosition(int position);

public:

	List();
	List(const List&);
	virtual ~List();

	List& operator=(const List &src);

	bool changeData(int position, T & newData);
	T* getData(int position);
	T* getFirst();
	T* getLast();

	void addFirst(const T &input);
	void addLast(const T &input);
	bool addAnywhere(int position, const T &input);				// returns true if successful

	T deleteFirst();											// returns value of removed node, else prints empty message
	T deleteLast();											    // returns true if successful.  returns false if was empty.
	T deleteAnywhere(int position);								// returns true if successful.  returns false if position is out of range.

	int find(const T& input);
	int getCount();
	bool isEmpty() const;
	void emptyOut();
	void display();
};

template<typename T>
Node<T>* List<T>::findNodeByPosition(int position) {
	// returns NULL if position is out of range.  Note: position 0 is the first item.
	if (position >= count || position < 0) {
		return NULL;
	}

	// Starting at head, skip "position" items and return
	Node<T>* ptr = head;
	for (int skipCount = 0; skipCount < position; skipCount++) {
		ptr = ptr->getNext();
	}

	return ptr;
}

template<typename T>
List<T>::List()
{
	head = NULL;
	tail = NULL;
	count = 0;
}

template<typename T>
List<T>::List(const List& src) :
	count(0),
	head(NULL),
	tail(NULL)
{
	// Starting off with an empty list (above), we walk through
	// each item in the source list, in order, and add it to the
	// end of our list.
	Node<T>* srcptr = src.head;
	while (srcptr != NULL) {
		T srcdata = srcptr->getData();
		this->addLast(srcdata);
	}
}


template<typename T>
List<T>::~List()
{
	emptyOut();
}


template<typename T>
List<T>& List<T>::operator=(const List &src) {
	// Assignment operator for lists.  Like the copy constructor, we need to make a deep copy.
	if (this == &src) {
		return *this;
	}

	// First, zap old contents, if any
	emptyOut();

	// Next, copy the src contents, as the copy constructor does.
	Node<T>* srcptr = src.head;
	while (srcptr != NULL) {
		T srcdata = srcptr->getData();
		this->addLast(srcdata);
	}

	return *this;
}


template<typename T>
bool List<T>::changeData(int position, T & newData) {
	// Returns true if successful.  Return false if not (i.e., position out of range).
	Node<T>* n = findNodeByPosition(position);
	if (n == NULL) {
		return false;
	}
	n->setData(newData);
	return true;
}

template<typename T>
T* List<T>::getData(int position) {
	// If position is out of range, we return null.  Otherwise, we return a pointer to the Data.
	Node<T>* n = findNodeByPosition(position);
	if (n == NULL) {
		return NULL;
	}
	T& d = n->getData();
	return &d;
}


template<typename T>
T* List<T>::getFirst()
{
	if (head == NULL) {
		// There is no first item
		return NULL;
	}

	// returns a pointer into the node (doesn't copy the T)
	return &head->getData();
}



template<typename T>
T* List<T>::getLast()
{
	if (tail == NULL) {
		return NULL;
	}

	return &tail->getData();
}


template<typename T>
void List<T>::addFirst(const T& input)
{
	Node<T> *temp = new Node<T>(input); // Create new Node
	temp->setNext(head);				// Make node point to next node
	head = temp;						// Make head point at new node
	if (isEmpty())
	{
		tail = temp;					// If this list was empty, set tail
	}
	count++;							// increment counter
}


template<typename T>
void List<T>::addLast(const T& input)
{
	if (count == 0) {
		addFirst(input);
	}
	else {
		Node<T> *temp = new Node<T>(input); // Create new Node
		tail->setNext(temp);
		tail = temp;
		count++;
	}
}

template<typename T>
bool List<T>::addAnywhere(int position, const T& input)
{
	// Insert a new node **before** the position represented by the first parameter.
	// position 0 is the same as addFirst, and position count is the same as addLast.
	// Returns true if successful.  Returns false if not (because bad position was supplied).

	if (position < 0 || position > count) {
		// invalid value of position
		return false;
	}
	else if (position == 0) {
		addFirst(input);
		return true;
	}
	else if (position == count) {
		addLast(input);
		return true;
	}

	// Adding in the middle of the linked list
	// Reminder: position 0 represents the head, and 0 through count-1, inclusive, are the valid possibilities.
	Node<T>* before = findNodeByPosition(position - 1);
	Node<T>* after = findNodeByPosition(position);

	Node<T> *temp = new Node<T>(input);

	before->setNext(temp);
	temp->setNext(after);
	count++;

	// We know that we don't have to change head - that case was handled above (addFirst).
	return true;
}

template<typename T>
T List<T>::deleteFirst()
{
	if (!isEmpty()) {
		Node<T> *del = this->head;
		T temp = del->getData();
		this->head = this->head->getNext();
		if (count == 1)
		{
			tail = head;
		}

		count--;
		delete del;

		return temp;
	}
	else
	{
		throw "Cannot delete first element because list is empty";
	}
}

template<typename T>
T List<T>::deleteLast()
{
	if (isEmpty()) {
		std::cout << "Nothing to delete.";
		// needs to throw exception
	}
	else if (count == 1) {
		return deleteFirst();
	}

	// Multiple Nodes. Traverse through list
	Node<T> *temp = head;
	Node<T> *prev = NULL;
	while (temp->getNext() != NULL)
	{
		prev = temp;
		temp = temp->getNext();
	}
	prev->setNext(NULL);
	T tempData = temp->getData();
	tail = prev;

	delete temp;
	count--;

	return tempData;
}


template<typename T>
T List<T>::deleteAnywhere(int position) // input - position
{
	if (position < 0 || position >= count) {
		// invalid position
		std::cout << "invalid position" << std::endl;
		return;
	}

	if (position == 0) {
		return deleteFirst();
	}

	if (position == count - 1) {
		return deleteLast();
	}

	// Deleting somewhere in the middle of the linked list.
	Node<T>* prev = findNodeByPosition(position - 1);
	Node<T>* temp = prev->getNext();
	prev->setNext(temp->getNext()); // now temp is not "visible" anywhere in the linked list
	T tempData = temp->getData();

	delete temp;
	count--;

	return tempData;
}


// returns position within the linked list of the first match of "input".
	// If not present, then returns the sentinel -1.
template<typename T>
int List<T>::find(const T& input) {
	int result = 0; // position within the linked list where the item is found
	Node<T>* temp = head;

	while (temp != NULL) {
		if (temp->getData() == input) {
			return result;
		}

		temp = temp->getNext();
		result++;
	}

	return -1;
}

template<typename T>
int List<T>::getCount() {
	return count;
}

template<typename T>
bool List<T>::isEmpty() const {
	return count == 0;
}

template<typename T>
void List<T>::emptyOut() {
	while (head != NULL) {
		deleteFirst();
	}
}

template<typename T>
void List<T>::display()
{
	if (isEmpty()) {
		std::cout << " The List is empty.\n";

	}

	Node<T> *temp = head;
	while (temp != NULL)
	{
		// We are assuming that code exists to cout something of type T.
		// Depending on type T, someone may need to have written that already.
		std::cout << temp->getData() << std::endl;
		temp = temp->getNext();
	}

}



