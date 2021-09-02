// Parhuam Jalalian
// Luke Fields
// Lab 5
// Partner's Contriubution 0 - Both did same work
// BST.h

#pragma once

#include "BSTNode.h"
#include "Queue.h"
#include <string>
#include <fstream>
#include <iostream>


template <typename T>
class BST 
{
private:
	BSTNode<T>* root;
	int size;

public:
	BST() 
	{
		root = nullptr;
		size = 0;
	}

	BSTNode<T>* getRoot()
	{ 
		return root; 
	};
	
	bool isEmpty() {
		return !size;
	}

	void insert(T data) 
	{
		if (root == nullptr) {
			root = new BSTNode<T>(data, nullptr);
			size = 1;
			return;
		}
		else {
			root->insert(data);
			size++;
		}
	}

	// returns true if the item was deleted (i.e. was in the tree)
	bool deleteNode(T data) {
		if (root == nullptr) {
			return false;
		}

		BSTNode<T> * newRootNode = nullptr;
		if (root->deleteNode(data, newRootNode)) {
			size--;
			root = newRootNode; // the root of the entire tree may have changed (if not, this line won't alter anything)
			return true;
		}
		
		return false;
	}

	// returns true if the modification took place (i.e. the oldData was found)
	bool modify(T oldData, T newData) {
		bool wasDeleted = deleteNode(oldData);
		if (!wasDeleted) {
			return false;
		}

		insert(newData);
		return true;
	}

	bool search(T data) const
	{
		if (root == nullptr)
			return false;
		else
			return root->search(data);
	}

	
	void writeToFile(int mode, std::ofstream& outfile);
	void preOrderWriteToFile(std::ofstream& outfile);
	void postOrderWriteToFile(std::ofstream& outfile);
	void inOrderWriteToFile(std::ofstream& outfile);
	void breadthFirstWriteToFile(std::ofstream& outfile);
	
};

// Write out the listings of everyone by Name
// Write out the listings of everyone by Birthday
// Option 1 is pre-order
// Option 2 is post-order
// Option 3 is in-order
// Option 4 is breadth-first

template <typename T>
void BST<T>::writeToFile(int option, std::ofstream& outfile)
{
	if (option == 1)
	{
		preOrderWriteToFile(outfile);
	}
	else if (option == 2)
	{
		postOrderWriteToFile(outfile);
	}
	else if (option == 3)
	{
		inOrderWriteToFile(outfile);
	}
	else if (option == 4)
	{
		breadthFirstWriteToFile(outfile);
	}
}





template <typename T>
void BST<T>::preOrderWriteToFile(std::ofstream& outfile)
{
	root->preOrderWriteToFile(outfile);
}


template <typename T>
void BST<T>::postOrderWriteToFile(std::ofstream& outfile)
{
	root->postOrderWriteToFile(outfile);
}


template <typename T>
void BST<T>::inOrderWriteToFile(std::ofstream& outfile)
{
	root->inOrderWriteToFile(outfile);
}

template <typename T>
void BST<T>::breadthFirstWriteToFile(std::ofstream& outfile) {
	if (size == 0) {
		return;
	}

	Queue<BSTNode<T>*> bfsQueue;

	bfsQueue.enqueue(root);

	while (!bfsQueue.isEmpty()) {
		BSTNode<T>* item = bfsQueue.dequeue();

		outfile << item->getData() << std::endl;

		BSTNode<T>* left = item->getLeft();
		BSTNode<T>* right = item->getRight();

		if (left != nullptr) {
			bfsQueue.enqueue(left);
		}

		if (right != nullptr) {
			bfsQueue.enqueue(right);
		}
	}
}

