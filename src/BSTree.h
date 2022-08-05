#pragma once
#include<iostream>
using namespace std;

template<class DT>
class Node {
public:
	DT data;
	Node* left;
	Node* right;

	Node() :left(NULL), right(NULL) {
	}
};

template<class DT>
class BSTree {
	Node<DT>* root;

	Node<DT>* traverseForInserting(Node<DT>* temp, const DT& newDataItem) {
		if (temp == NULL) {
			temp = new Node<DT>;
			temp->data = newDataItem;
			return temp;
		}

		else if (newDataItem < temp->data) {
			temp->left = traverseForInserting(temp->left, newDataItem);
		}

		else if (newDataItem > temp->data) {
			temp->right = traverseForInserting(temp->right, newDataItem);
		}

		else {
			cout << "Duplicates are present" << endl;
		}
		return temp;
	}

	bool traverseForSearching(Node<DT>* temp, const DT& searchDataItem) {
		if (temp == NULL) {
			return false;
		}

		else if (searchDataItem == temp->data) {
			return true;
		}

		else if (searchDataItem < temp->data) {
			return traverseForSearching(temp->left, searchDataItem);
		}

		else if (searchDataItem > temp->data) {
			return traverseForSearching(temp->right, searchDataItem);
		}
	}

	int getMax(const int& num1, const int& num2) {
		if (num1 == num2) {
			return num1;
		}

		else if (num1 > num2) {
			return num1;
		}

		return num2;
	}

	int calculateHeight(Node<DT>* temp) {
		if (temp == NULL) {
			return -1;
		}
		int leftHeight = calculateHeight(temp->left);
		int rightHeight = calculateHeight(temp->right);

		return getMax(leftHeight, rightHeight) + 1;
	}

	void deleteNode(Node<DT>*& nodePtr) {
		Node<DT>* temp;

		if (nodePtr->right == NULL) {
			temp = nodePtr;
			nodePtr = nodePtr->left;
			delete temp;
		}

		else if (nodePtr->left == NULL) {
			temp = nodePtr;
			nodePtr = nodePtr->right;
			delete temp;
		}

		else {
			temp = nodePtr->right;

			while (temp->left != NULL) {
				temp = temp->left;
			}

			nodePtr->data = temp->data;

			Node<DT>* prev = nodePtr->right;

			if (prev->left != NULL) {

				while (prev->left != temp) {
					prev = prev->left;
				}

				if (temp->right == NULL) {
					delete temp;
					prev->left = NULL;
				}

				else {
					prev->left = temp->right;
					delete temp;
				}
			}

			else {
				delete temp;
				nodePtr->right = NULL;
			}
		}
	}

	bool traverseForRemove(Node<DT>*& temp, const DT& deleteDataItem) {
		if (temp == NULL) {
			return false;
		}

		else if (temp->data == deleteDataItem) {
			deleteNode(temp);
		}

		else if (deleteDataItem < temp->data) {
			return traverseForRemove(temp->left, deleteDataItem);
		}

		else if (deleteDataItem > temp->data) {
			return traverseForRemove(temp->right, deleteDataItem);
		}

	}

public:
	BSTree() : root(NULL) {
	}

	Node<DT>* getRoot() {
		return root;
	}

	void insert(const DT& newDataItem) {
		root = traverseForInserting(root, newDataItem);
	}

	bool retrieve(const DT& searchDataItem) {
		return traverseForSearching(root, searchDataItem);
	}

	bool isEmpty() {
		if (root == NULL) {
			return true;
		}
		return false;
	}

	int getHeight() {
		return calculateHeight(root);
	}

	bool remove(const DT& deleteDataItem) {
		return traverseForRemove(root, deleteDataItem);
	}

	void inOrderDisplay(Node<DT>* temp) {
		if (temp != NULL) {
			inOrderDisplay(temp->left);
			cout << temp->data;
			inOrderDisplay(temp->right);
		}
	}

	void preOrderDisplay(Node<DT>* temp) {
		if (temp != NULL) {
			cout << temp->data;
			preOrderDisplay(temp->left);
			preOrderDisplay(temp->right);
		}
	}

	void postOrderDisplay(Node<DT>* temp) {
		if (temp != NULL) {
			postOrderDisplay(temp->left);
			postOrderDisplay(temp->right);
			cout << temp->data;
		}
	}

	~BSTree() {
		while (root != NULL) {
			remove(root->data);
		}
	}
};