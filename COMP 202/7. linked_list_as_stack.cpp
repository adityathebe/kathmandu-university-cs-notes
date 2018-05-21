/* Linked list as Stack
			- Aditya Thebe */
			
#include <iostream>
using namespace std;

struct node {
	int data;
	struct node *next;
}*Head;

bool isEmpty() {
	return Head==NULL;
}

void push(int x) {
	struct node *temp;
	temp = new node;
	temp->data = x;
	temp->next = NULL;
	if(isEmpty()) {
		Head = temp;
	} else {
		temp->next = Head;
		Head = temp;
	}
}

int pop() {
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

int peek() {
	if(isEmpty()) {
		return -1000;
	} else {
		return Head->data;
	}
}

int main() {
	int option, val, x;
	bool loop = true;
	while(loop) {
		cout << "\n1. Push\t2. Pop\t3. Peek\t.4 isEmpty\t5. Quit" << endl;
		cin >> option;
		switch(option) {
			case 1:
				cout << "Enter tha value: ";
				cin >> val;
				push(val);
				break;
				
			case 2:
				x = pop();
				if( x == -1000) {
					cout << "The Stack is Empty!! " << endl;
				} else {
					cout << x << endl;					
				}
				break;
				
			case 3:
				x = peek();
				if( x == -1000) {
					cout << "The Stack is Empty!! " << endl;
				} else {
					cout << x << endl;					
				}
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
