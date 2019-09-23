#pragma once
#include "Tree.h"

template <class T>
class SearchTree : public Tree<T> {
public:
	void add(T value);
	bool search(T value) { return search(Tree<T>::root, value); }
	void remove(T value) { return remove(Tree<T>::root, value); }
	int level(T value) { return level(Tree<T>::root, value); }

private:
	void add(typename Tree<T>::Node *current, T val);
	bool search(typename Tree<T>::Node *current, T val);
	void remove(typename Tree<T>::Node *current, T val);
	void removeRootMatch();
	void removeMatch(typename Tree<T>::Node *current, typename Tree<T>::Node *match, bool left);
	T findSmallest(typename Tree<T>::Node *current);
	int level(typename Tree<T>::Node *current, T val);
};

template <class T>
void SearchTree<T>::add(T val) {
	if (!Tree<T>::root) {
		Tree<T>::root = new typename Tree<T>::Node(val);
		return;
	}

	add(Tree<T>::root, val);
}

template <class T>
bool SearchTree<T>::search(typename Tree<T>::Node *current, T val) {
	if (!current) {
		return false;
	}

	if (current->value == val) {
		return true;
	}

	if (current->value < val) {
		return search(current->right, val);
	}

	else {
		return search(current->left, val);
	}
}

template <class T>
void SearchTree<T>::add(typename Tree<T>::Node *current, T val) {
	if (current->value <= val) {
		if (!current->right) {
			current->right = new typename Tree<T>::Node(val);
			return;
		}

		else add(current->right, val);
	}

	else {
		if (!current->left) {
			current->left = new typename Tree<T>::Node(val);
			return;
		}

		else add(current->left, val);
	}
}

template <class T>
void SearchTree<T>::remove(typename Tree<T>::Node *current, T val) {
	if (current != nullptr) {
		if (current->value == val) {
			removeRootMatch();
		}

		else {
			if (val < current->value && current->left != nullptr) {
				current->left->value == val ?
					removeMatch(current, current->left, true) :
					remove(current->left, val);
			}

			else if (val > current->value && current->right != nullptr) {
				current->right->value == val ?
					removeMatch(current, current->right, false) :
					remove(current->right, val);
			}
		}
	}
}

template <class T>
void SearchTree<T>::removeRootMatch() {
	if (Tree<T>::root != nullptr) {
		typename Tree<T>::Node *temp = Tree<T>::root;

		//if the current node has no children
		if (Tree<T>::root->left == nullptr && Tree<T>::root->right == nullptr) {
			Tree<T>::root = nullptr;
			delete temp;
		}

		//if the current node only has a right child
		else if (Tree<T>::root->left == nullptr && Tree<T>::root->right != nullptr) {
			Tree<T>::root = Tree<T>::root->right;
			temp->right = nullptr;
			delete temp;
		}

		//if the current node only has a left son
		else if (Tree<T>::root->left != nullptr && Tree<T>::root->right == nullptr) {
			Tree<T>::root = Tree<T>::root->left;
			temp->left = nullptr;
			delete temp;
		}

		//if the current node has both children
		else {
			T smallestInRight = findSmallest(Tree<T>::root->right);
			remove(Tree<T>::root, smallestInRight);
			Tree<T>::root->value = smallestInRight;
		}
	}
}

template <class T>
void SearchTree<T>::removeMatch(typename Tree<T>::Node *current, typename Tree<T>::Node *match, bool left) {
	if (current != nullptr) {
		typename Tree<T>::Node *temp;

		//if the current node has no children
		if (match->left == nullptr && match->right == nullptr) {
			temp = match;
			left == true ? current->left = nullptr : current->right = nullptr;
			delete temp;
		}

		//if the current node only has a right child
		else if (match->left == nullptr && match->right != nullptr) {
			left == true ? current->left = match->right : current->right = match->right;
			match->right = nullptr;
			temp = match;
			delete temp;
		}

		//if the current node only has a left son
		else if (match->left != nullptr && match->right == nullptr) {
			left == true ? current->left = match->left : current->right = match->left;
			match->left = nullptr;
			temp = match;
			delete temp;
		}

		//if the current node has both children
		else {
			T smallestInRight = findSmallest(match->right);
			remove(match, smallestInRight);
			match->value = smallestInRight;
		}
	}
}

template <class T>
T SearchTree<T>::findSmallest(typename Tree<T>::Node *current) {
	if (current != nullptr) {
		if (current->left != nullptr) {
			return findSmallest(current->left);
		}

		else {
			return current->value;
		}
	}
}

template <class T>
int SearchTree<T>::level(typename Tree<T>::Node *current, T val) {
	if (search(current, val) == false) {
		return -1;
	}

	else {
		if (current == nullptr) {
			return 0;
		}

		else if (current->value > val) {
			return (level(current->left, val) + 1);
		}

		else if (current->value < val) {
			return (level(current->right, val) + 1);
		}

		else if (current->value == val) {
			return 0;
		}
	}
}