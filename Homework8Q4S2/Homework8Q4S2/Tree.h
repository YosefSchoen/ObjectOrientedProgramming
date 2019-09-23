#pragma once
#include <iostream>
//#define nullptr NULL
using namespace std;

template <class T> class Tree {
protected:
	class Node {
	public:
		Node *left;
		Node *right;

		T value;
		Node(T val) : value(val), left(nullptr), right(nullptr) {}
		Node(T val, Node *l, Node *r) : value(val), left(l), right(r) {}
	};

	Node *root;

public:
	Tree() { root = nullptr; }
	Tree(Node node) {}
	~Tree();

	bool isEmpty() const;
	void clear() { clear(root); root = nullptr; }
	void preOrder() { preOrder(root); }
	void inOrder() { inOrder(root); }
	void postOrder() { postOrder(root); }

	virtual void process(T val) { cout << val << " "; }
	virtual void add(T val) = 0;
	virtual bool search(T val) = 0;
	virtual void remove(T val) = 0;

	int leaves() { return leaves(root); }
	int height() { return height(root); }
	void reflect() { reflect(root); }
	int onlyLeftSon() { return onlyLeftSon(root); }

private:
	void clear(Node *current);
	void preOrder(Node *current);
	void inOrder(Node *current);
	void postOrder(Node *current);
	int leaves(Node *current);
	int height(Node *current);
	void reflect(Node *current);
	int onlyLeftSon(Node *current);

};

template <class T>
Tree<T>::~Tree() {
	if (root != nullptr) {
		clear(root);
	}
}

template <class T>
void Tree<T>::clear(Node *current) {
	if (current) {
		if (current->left) {
			clear(current->left);
		}

		if (current->right) {
			clear(current->right);
		}

		delete current;
	}
}

template <class T>
bool Tree<T>::isEmpty() const {
	return root == nullptr;
}

template <class T>
void Tree<T>::preOrder(Node *current) {
	if (current) {
		process(current->value);
		preOrder(current->left);
		preOrder(current->right);
	}

}

template <class T>
void Tree<T>::inOrder(Node *current) {
	if (current) {
		inOrder(current->left);
		process(current->value);
		inOrder(current->right);
	}
}

template <class T>
void Tree<T>::postOrder(Node *current) {
	if (current) {
		postOrder(current->left);
		postOrder(current->right);
		process(current->value);
	}
}

template <class T>
int Tree<T>::leaves(Node *current) {

	if (current == nullptr) {
		return 0;
	}

	if (current->left == nullptr && current->right == nullptr) {
		return 1;
	}

	else {
		return(leaves(current->left) + leaves(current->right));
	}
}

template <class T>
int Tree<T>::height(Node *current) {
	if (current == nullptr) {
		return 0;
	}

	else {
		int leftHeight = height(current->left);
		int rightHeight = height(current->right);

		if (leftHeight > rightHeight) {
			return(leftHeight + 1);
		}

		else {
			return (rightHeight + 1);
		}
	}
}

template <class T>
void Tree<T>::reflect(Node *current) {
	if (current == nullptr) {
		return;
	}

	else {
		Node *temp;

		reflect(current->left);
		reflect(current->right);

		temp = current->left;
		current->left = current->right;
		current->right = temp;
	}
}

template <class T>
int Tree<T>::onlyLeftSon(Node *current) {
	if (current == nullptr) {
		return 0;
	}

	else if (current->left != nullptr && current->right == nullptr) {
		int leftSons = (onlyLeftSon(current->left) + onlyLeftSon(current->right));
		return leftSons + 1;
	}

	else {
		int leftSons = (onlyLeftSon(current->left) + onlyLeftSon(current->right));
		return leftSons;
	}
}