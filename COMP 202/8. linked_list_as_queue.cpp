/* Linked list as Queue
			- Aditya Thebe */
			
#include <iostream>
using namespace std;

struct node {
	int data;
	struct node *next;
}*Head, *curPtr;

bool isEmpty() {
	return Head==NULL;
}

void enqueue(int x) {
	struct node *temp;
	temp = new node;
	temp->data = x;
	temp->next = NULL;
	if(isEmpty()) {
		Head = temp;
		curPtr = Head;
	} else {
		curPtr->next = temp;
		curPtr = curPtr->next;
	}
}

int dequeue() {
	if(isEmpty()) {
		return -1000;
	} else {
		struct node *temp;
		int k;
		temp = Head;
		Head = Head->next;
		k = temp->data;
		delete temp;
		return k;
	}
}

void display_all() {
	if(isEmpty()) {
		cout << "The Queue is Empty!" << endl;
	} else {
		struct node *temp;
		temp = Head;
		while(temp != NULL) {
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
}

int main() {
	int option, val, x;
	bool loop = true;
	while(loop) {
		cout << "\n1. Enqueue\t2. Dequeue\t3. Display \t4. isEmpty\t5. Quit" << endl;
		cin >> option;
		switch(option) {
			case 1:
				cout << "Enter tha value: ";
				cin >> val;
				enqueue(val);
				break;
				
			case 2:
				x = dequeue();
				if( x == -1000) {
					cout << "The Queue is Empty!! " << endl;
				} else {
					cout << x << endl;					
				}
				break;
				
			case 3:
				display_all();
				break;
				
			case 4:
				if ( isEmpty())
					cout << " Stack is Empty!" << endl;
				else 
					cout << "Stack is not Empty!" << endl;
				break;
				
			case 5:
				loop = false;
				break;
			
			default:
				cout << "Invalid Input !!" <<endl <<endl;
		}		
	}	
}
