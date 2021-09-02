// Parhuam Jalalian
// Luke Fields
// Lab 2
// Partner's Contriubution 0 - Both did same work
// main.cpp

#include <iostream>
#include <string>
#include <sstream>
#include "currency.h"
#include "queue.h"
#include "stdlib.h"
#include "time.h"

using namespace std;

int main()
{
	srand(time(NULL)); // seed random numbers
	//Finally, implement a Queue ADT based on your singly linked list which 
	//will implement the most common Queue operations like 
	//	enqueue
	//	dequeue
	//	front
	//	rear
	//	empty
	//	etc.

	// int
	Queue<int> iQ;

	cout << "filling queue with ints:\n";
	for (int i = 0; i < 20; i++) {
		int v = rand() % 100 + 1;
		iQ.enqueue(v);
		cout << v << (i != 19 ? " " : "\n");
	}
	cout << "removing 5 ints:\n";
	for (int i = 0; i < 5; i++) {
		cout << iQ.dequeue() << (i != 4 ? " " : "\n");
	}
	// currently queueFront(), queueRear() return pointers, dereferenced here.
	cout << "Front of the queue: " << *(iQ.queueFront()) << endl;
	cout << "Back of the queue: " << *(iQ.queueRear()) << endl;
	cout << "removing 5 ints:\n";
	for (int i = 0; i < 5; i++) {
		cout << iQ.dequeue() << (i != 4 ? " " : "\n");
	}
	cout << "Display all elements in queue:\n";
	iQ.displayQueue();
	cout << "There are " << iQ.queueCount() << " in the queue.\n";
	cout << "Removing all elements from the queue. . . " << endl;
	iQ.emptyQueue();
	cout << "Current Status: " << (iQ.isEmpty() ? "Empty" : "Not Empty") << endl;
	
	system("pause");
	cout << endl << endl;



	// string
	Queue<string> sQ;


	cout << "filling queue with strings:\n";
	for (int i = 0; i < 20; i++) {
		int v = rand() % 100;
		string s = "S";
		s += to_string(v);
		sQ.enqueue(s);
		cout << s << (i != 19 ? " " : "\n");
	}
	cout << "removing 5 strings:\n";
	for (int i = 0; i < 5; i++) {
		cout << sQ.dequeue() << (i != 4 ? " " : "\n");
	}
	// currently queueFront(), queueRear() return pointers, dereferenced here.
	cout << "Front of the queue: " << *(sQ.queueFront()) << endl;
	cout << "Back of the queue: " << *(sQ.queueRear()) << endl;
	cout << "removing 5 strings:\n";
	for (int i = 0; i < 5; i++) {
		cout << sQ.dequeue() << (i != 4 ? " " : "\n");
	}
	cout << "Display all elements in queue:\n";
	sQ.displayQueue();
	cout << "There are " << sQ.queueCount() << " in the queue.\n";
	cout << "Removing all elements from the queue. . . " << endl;
	sQ.emptyQueue();
	cout << "Current Status: " << (sQ.isEmpty() ? "Empty" : "Not Empty") << endl;

	system("pause");
	cout << endl << endl;
	// dollar
	Queue<Dollar> dQ;


	cout << "filling queue with dollars:\n";
	for (int i = 0; i < 5; i++) {

		Dollar tDol;
		stringstream is; // create string stream to input data without user input
		float v = static_cast<float>(rand() / 100.0);
		
		is << v;			// store random float in stringstream
		is >> tDol;			// get float from stringstream put in dollar

		dQ.enqueue(tDol);	// enqueue dollar
		cout << tDol << endl;
	}
	cout << "removing 2 dollar amounts:\n";
	for (int i = 0; i < 2; i++) {
		cout << dQ.dequeue() << (i != 1 ? " " : "\n");
	}
	// currently queueFront(), queueRear() return pointers, dereferenced here.
	cout << "Front of the queue: " << *(dQ.queueFront()) << endl;
	cout << "Back of the queue: " << *(dQ.queueRear()) << endl;
	cout << "removing 1 dollar amount:\n";
	cout << dQ.dequeue() << endl;

	cout << "Display all elements in queue:\n";
	dQ.displayQueue();

	cout << "There are " << dQ.queueCount() << " in the queue.\n";
	cout << "Removing all elements from the queue. . . " << endl;
	dQ.emptyQueue();

	cout << "Current Status: " << (dQ.isEmpty() ? "Empty" : "Not Empty") << endl;

	system("pause");

	return 0;
}