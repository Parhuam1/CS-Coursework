// Parhuam Jalalian
// Luke Fields
// Lab 5
// Partner's Contriubution 0 - Both did same work
// node.h

#pragma once

#include <string>
#include <iostream>
#include "Node.h"

template <typename T>
class BSTNode : public Node<T> {
private:
	BSTNode* left;
	BSTNode* right;
	BSTNode<T>* root;

	// Ban outside calls to copy constructor and copy assignment operator
	// by simply making them private
	BSTNode(const BSTNode<T> &src);
	void operator=(const BSTNode<T> &src);

public:
	BSTNode(T &dat, BSTNode<T>* parent) :
		Node<T>(dat),
		left(nullptr),
		right(nullptr),
		root(parent) 
	{}
	
	~BSTNode() {
		left = nullptr; // denotes the pointer literal
		right = nullptr;
	}
		
	void setData(T & newData) {
		Node<T>::setData();
	}

	T& getData() {
		return Node<T>::getData();
	};

	BSTNode* getLeft() {
		return left;
	};

	BSTNode* getRight() {
		return right;
	};

	void insert(T newData) {
		T data = getData();
		if (newData < data) {
			// The new node has to go somewhere within our left subtree
			if (left == nullptr) {
				left = new BSTNode<T>(newData, this);
			}
			else {
				left->insert(newData);
			}
		}
		else {
			// The new node has to go somewhere within our right subtree
			if (right == nullptr) {
				right = new BSTNode<T>(newData, this);
			}
			else {
				right->insert(newData);
			}
		}
	}

	// Returns 2 values:
	// 1) a boolean (true if the item was found & deleted), false otherwise
	// 2) the new subtree's root (so the caller can update its root pointer, if desired)
	//    Note that if we don't end up deleting the subtree's root node, then newSubtreeRoot
	//    will simply be 'this'.
	bool deleteNode(T oldData, BSTNode<T>* &newSubtreeRoot) {
		T data = getData();
		if (oldData == data) {
			newSubtreeRoot = deleteHere();
			return true;
		}
		else if (oldData < data) {
			// delete from our left subtree (if there is one)
			if (left == nullptr) {
				// tried to delete an item that isn't in the tree
				return false;
			}
			else {
				BSTNode<T> * ignoreNewSubtreeRoot;
				bool result = left->deleteNode(oldData, ignoreNewSubtreeRoot);
				newSubtreeRoot = this; // the subtree root didn't change
				return result;
			}
		}
		else {
			// delete from our right subtree (if there is anything there)

			if (right == nullptr) {
				return false;
			}
			else {
				BSTNode<T> * ignoreNewSubtreeRoot;
				bool result = right->deleteNode(oldData, ignoreNewSubtreeRoot);
				newSubtreeRoot = this; // the subtree root didn't change
				return result;
			}
		}
	}

	bool search(T srcData) const {
		T data = getData();
		if (srcData == data) {
			return true;
		}
		else if (srcData < data)
		{
			if (left == nullptr)
				return false;
			else
				return left->search(srcData);
		}
		else {
			if (right == nullptr)
				return false;
			else
				return right->search(srcData);
		}
	}

	void preOrderWriteToFile(std::ofstream& outfile) {
		T data = getData();
		outfile << data << std::endl;
		if (left != nullptr) {
			left->preOrderWriteToFile(outfile);
		}
		if (right != nullptr) {
			right->preOrderWriteToFile(outfile);
		}
	}

	void inOrderWriteToFile(std::ofstream& outfile) {
		T data = getData();
		if (left != nullptr) {
			left->preOrderWriteToFile(outfile);
		}
		outfile << data << std::endl;
		if (right != nullptr) {
			right->preOrderWriteToFile(outfile);
		}
	}
	
	void postOrderWriteToFile(std::ofstream& outfile) {
		T data = getData();
		if (left != nullptr) {
			left->preOrderWriteToFile(outfile);
		}
		if (right != nullptr) {
			right->preOrderWriteToFile(outfile);
		}
		outfile << data << std::endl;
	}

private:
	void replaceMyselfInTree(BSTNode<T> * replacement) {
		// Replace 'this' with 'replacement' within the binary tree, updating links as
		// appropriate.  When done, 'this' is no longer reachable in the tree and is in fact deleted entirely
		// (the individual node is deleted, not its subtree(s)).
		//
		// Side cases, and explanation of return value:
		//    - replacement might be nullptr.
		//    - 'this' might be the root, in which case the caller needs to know of
		//      the new root.  That's where the return value comes in: if we have
		//      no parent (meaning we are the root of the entire tree)
		//      then we return 'replacement', which is the new root of the entire tree.
		//      Otherwise we return nullptr, indicating that the tree's root didn't change.
		
		if (root == nullptr) {
			// replacement is going to become the root of the entire tree
			if (replacement != nullptr) {
				replacement->root = nullptr;
			}

			delete this;
			return;
		}

		// I'm not the root of the entire tree, so I have a parent node.
		// Make my parent point to replacement instead of myself.
		if (root->left == this) {
			root->left = replacement;
		}
		else {
			root->right = replacement;
		}

		if (replacement != nullptr) {
			replacement->root = root;
		}

		delete this;
	}

	// Returns the new root of the (sub)tree (the former root of the subtree is 'this').
	// In some cases, 'this' is in fact deleted.  But in one case 'this' perserveres, and
	// a different item is deleted.
	BSTNode<T> * deleteHere() {
		T data = getData();
		if (left != nullptr && right == nullptr) {
			// I only have a left subtree.  It replaces myself in the tree.
			BSTNode<T> * temporary = this->left;
			replaceMyselfInTree(left); // better not use 'this' after this line, because it may have been deleted!!
			return temporary;
		}
		else if (left == nullptr && right != nullptr) {
			// I have only a right subtree.  It replaces myself in the tree.
			BSTNode<T> * temporary = this->right;
			replaceMyselfInTree(right);
			return temporary;
		}
		else if (left == nullptr && right == nullptr) {
			// I am a leaf node
			replaceMyselfInTree(nullptr);
			return nullptr;
		}

		// Now the hard case: I have both a left and right subtree.
		// Find the largest item in the tree that is smaller than myself,
		// copy its contents onto myself (temporarily making a duplicate),
		// and then delete that item (to fix the duplicate) using recursion.
		BSTNode<T> * justSmallerThanMe = findJustSmallerThanMe(); // won't be nullptr since we have a left child
		data = justSmallerThanMe->data; // duplicate contents, for now
		justSmallerThanMe->deleteHere(); // ignore the return type
		
		return this; // the root of this subtree hasn't changed (its data contents were changed, but the 'this' pointer is unchanged)
	}

	BSTNode<T> * findJustSmallerThanMe() {
		// In a sorted tree, this is simply: left once, then right infinite until just before nullptr
		if (left == nullptr) {
			// Sorry, there is nothing smaller than me
			return nullptr;
		}

		BSTNode<T> * result = left;

		while (result->right != nullptr) {
			result = result->right;
		}

		// Now we know that result->right is null.  That's what we want to return
		return result;
	}

};




