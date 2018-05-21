/* Program by
		- Aditya Thebe */

#include <iostream>
using namespace std;

struct node {
	int info;
	struct node *next;
}*start, *last;

void insert(int x) {
	struct node *temp;
	temp = new node;
	temp->info = x;
	temp->next = NULL;
	if(start == NULL) {
		start = temp;
		last = temp;
	} else {
		last->next = temp;
		temp->next = start;
		last = temp;
	}	
}

void del_beg() {
	if(start == NULL) {
		cout << "Nothing to delete!" <<endl;
	} else if (start == last) {
		struct node *temp;
		temp = start;
		start = NULL;
		last = NULL;
		cout << "Deleted : " << temp->info << endl;
		delete temp;
	} else {
		struct node *temp;
		temp = start;
		start = start->next;
		last->next = start;
		cout << "Deleted : " << temp->info << endl;
		delete temp;
	}
}

void del_end() {
	if(start == NULL) {
		cout << "Nothing to delete!" <<endl;
	} else if (start == last) {
		struct node *temp;
		temp = start;
		start = NULL;
		last = NULL;
		cout << "Deleted : " << temp->info << endl;
		delete temp;
	} else {
		struct node *temp, *temp_last;
		temp_last = last;
		temp = last;
		while(temp->next != last) {
			temp = temp->next;
		}
		temp->next = start;
		last = temp;
		cout << "Deleted : " << temp_last->info << endl;
		delete temp_last;
	}
}

void display_all() {
	if(start == NULL) {
		cout << "Nothing to display!" << endl;
	} else {
		struct node *temp;
		temp = start;
		do {
			cout << temp->info << endl;
			temp = temp->next;
		} while (temp != start);
	}
}

int main() {
	start = NULL;
	last = NULL;
	int user_option;
	int temp;	// to store user value
	bool loop = true;
	do {
		cout << "\n1. Insert \n2. Delete start\n3. Delete end" << endl;
		cout << "4. Display all elementsL\n5. Quit" << endl;
		cin >> user_option;
		cout << "------------------------------------------------------------" << endl;
		switch(user_option) {
			case 1:
				cout << "Enter the value: ";
				cin >> temp;
				insert(temp);	
				break;
				
			case 2:
				del_beg();
				cout << "Remaining Elements" << endl;
				display_all();
				break;
			
			case 3:		
				del_end();
				cout << "Remaining Elements" << endl;
				display_all();
				break;
			
			case 4:
				display_all();
				break;
				
			case 5:	
				loop = false;
				break;
				
			default:
				cout << "Invalid entry !" << endl;
		}
	} while(loop);
}

