#include <iostream>
#include <cstdlib>
#include "BST.h"

using namespace std;

BST::BST() {
	root = NULL;
}

BST::node* BST::createLeaf(int key) {
	node *temp = new  node;
	temp->key = key;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

void BST::addLeaf(int key) {
	addLeafPvt(key, root);
}

void BST::addLeafPvt(int key, node *ptr) {
	if(root == NULL) {
		root = createLeaf(key);
	} else if ( key < ptr->key) {
		if(ptr->left != NULL)
			addLeafPvt(key, ptr->left);
		else
			ptr->left = createLeaf(key);
	} else if ( key > ptr->key) {
		if(ptr->right != NULL)
			addLeafPvt(key, ptr->right);
		else
			ptr->right = createLeaf(key);	
	} else {
		cout << "The key " << key << " has already been added to the tree" << endl;
	}
}

void BST::display() {
	displayPvt(root);
}

void BST::displayPvt(node *ptr) {
	if (root == NULL) {
		cout << "The tree is empty!" << endl;
	} else {
		if(ptr->left != NULL) {
			displayPvt(ptr->left);
		}
		cout << ptr->key << " ";
		if(ptr->right != NULL) {
			displayPvt(ptr->right);
		}
	}
}

BST::node* BST::ReturnNode(int key) {
	ReturnNodePvt(key, root);
}

BST::node* BST::ReturnNodePvt(int key, node *ptr) {
	if (ptr == NULL) {
		return NULL;
	} else {
		if(ptr->key == key) {
			return ptr;
		} else {
			if (key < ptr->key) {
				return ReturnNodePvt(key, ptr->left);
			} else {
				return ReturnNodePvt(key, ptr->right);
			}
		}
	}
}
