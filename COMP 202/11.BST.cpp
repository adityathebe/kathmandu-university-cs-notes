#include <iostream>
using namespace std;

struct node {
	int info;
	node *left;
	node *right;
} *Root = NULL;

/* ============================================
============= FUNCTION PROTOTYPES =============
==============================================*/

// Main Tree Functions
node* insert(node *root, int value);
bool searchTree(node* temp, int value);
int deleteNode(node* temp, int value);

// Tree Traversal
void inorder(node *root);
void preorder(node *root);
void postorder(node *root);

// Utility functions
int findMin(node* temp);
node* getParent(int value);

/* ============================================
================ MAIN FUNCTION ================
==============================================*/

int main() {
	int choice, userValue;
	while(1) {
		cout << "1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Search\n6. Delete\n7. Quit" << endl;
		cin >> choice;
		switch(choice) {
			case 1: // insert
				cout << "Enter the value to insert: ";
				cin >> userValue;
				Root = insert(Root, userValue);
				break;
				
			case 2: // inorder
				cout << "===================================" << endl;
				inorder(Root);
				cout << "===================================" << endl;
				break;
			
			case 3: // preorder
				cout << "===================================" << endl;
				preorder(Root);
				cout << "===================================" << endl;
				break;
				
			case 4: // postorder
				cout << "===================================" << endl;
				postorder(Root);
				cout << "===================================" << endl;
				break;
				
			case 5: // Search
				cout << "Enter the value to search: ";
				cin >> userValue;
				searchTree(Root, userValue);
				break;
				
			case 6: // Delete
				cout << "Enter the value to delete: ";
				cin >> userValue;
				deleteNode(Root, userValue);
				break;
				
			case 7:
				exit(0);
				break;
				
			default:
				cout << "Invalid Command!" << endl;
		}
	}	
}

/* ============================================
============= FUNCTION DEFINITIONS =============
==============================================*/

/* ========= Insert Node =========== */
node* insert(node *root, int value) {
	if (root == NULL) {
		struct node *temp;
		temp = new node;
		temp->info = value;
		temp->right = NULL;
		temp->left = NULL;
		root = temp;
	} else if (value < root->info) {
		root->left = insert(root->left, value);
	} else if ( value > root->info ) {
		root->right = insert(root->right, value);
	} else {
		cout << "Duplicate Value!" << endl;
	}		
	return root;
}

/* ========= Inorder Traversal =========== */
void inorder( node *root ) {
	if (root != NULL) {
		inorder(root->left);
		cout << root->info << endl;
		inorder(root->right);	
	}
}

/* ========= Preorder Traversal =========== */
void preorder(node *root) {
	if (root != NULL) {
		cout << root->info << endl;
		preorder(root->left);
		preorder(root->right);	
	}
}
/* ========= Postorder Traversal =========== */
void postorder(node *root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);	
		cout << root->info << endl;
	}
}

/* ======== Minimum value from a Tree ======== */
int findMin(node* temp) {
	while(temp->left != NULL) {
		temp = temp->left;
	}
	return temp->info;
}

/* ============== Search Tree ============== */
bool searchTree(node* temp, int value) {
	if (temp == NULL) {
		cout << "Number not found!" << endl;
		return false;
	} else if ( value > temp->info ) {
		searchTree(temp->right, value);
	} else if ( value < temp->info ) {
		searchTree(temp->left, value);
	} else {
		cout << "Number Found!" << endl;
		return true;
	}
}

/* =========== Returns Parent Node =========== */
node* getParent(int value) {
	node *curNode = Root;
	node *parentNode = NULL;
	while(curNode->info != value) {
		if ( value > curNode->info ) {
			parentNode = curNode;
			curNode = curNode->right;
		} else if ( value < curNode->info ) {
			parentNode = curNode;
			curNode = curNode->left;
		} 
	}
	return parentNode;
}

/* ========== Delete Node ========== */
void deleteNode(node* temp, int value) {
	if (temp == NULL) {
		cout << "Couldn't find the number" << endl;
	} else if ( temp->info == value) {
		if(temp->left == NULL && temp->right == NULL) {
			// Delete Leaf Node
			node* parent = getParent(value);
			if ( parent->left == temp ) {
				parent->left = NULL;
			} else if ( parent->right == temp ) {
				parent->right = NULL;
			}
			delete temp;
		} else if ( (temp->left != NULL && temp->right == NULL) || (temp->left == NULL && temp->right != NULL )){
			// Delete node with single child
			node* parent = getParent(value);
			if (temp->left != NULL) {
				if(parent->left == temp) {
					parent->left = temp->left;
				} else if (parent->right == temp) {
					parent->left = temp->left;
				}
			} else if (temp->right != NULL) {
				if (parent->left == temp) {
					parent->left = temp->right;
				} else if (parent->right == temp) {
					parent->left = temp->right;
				}
			}
			delete temp;
		} else if (temp->left != NULL && temp->right != NULL) {
			// Delete node with two children
			int min = findMin(temp->right);
			deleteNode(temp->right, min);
			temp->info = min;			
		}
	} else {
		if (value > temp->info) {
			deleteNode(temp->right, value);
		} else if (value < temp->info) {
			deleteNode(temp->left, value);
		}
	}
}