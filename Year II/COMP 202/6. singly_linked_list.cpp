/* Program by
	- Aditya Thebe */
	
//1.	Insertion at beginning					- Done
//2.	Insertion at end						- Done
//3.	Insertion at arbitary node				- Done
//4.	Count the number of node in SLL			- Done
//5.	Deletion of a node based upon value		- Done
//6.	Deletion of an arbitrary node			- Done
//7.	Display elements of SLL					- Done
//8.	Reverse of a list						- Done
//9.	Sort the list (ascending order)			- Done

#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
	int info;
	struct node *next;
}*Head;

int count_node() {
	int count = 0;
	struct node *temp;
	temp = Head;
	while(temp != NULL) {
		count ++;
		temp = temp->next;
	}
	return count;
}

void insert_at_beg(int x) {
	struct node *temp;
	temp = new node;
	temp->info = x;
	temp->next = NULL;
	if ( Head == NULL) {
		Head = temp;
	} else {
		temp->next = Head;
		Head = temp;
	}
}

void insert_at_end(int x) {
	struct node *temp;
	struct node *current_ptr;
	temp = new node;
	temp->info = x;
	temp->next = NULL;
	current_ptr = Head;
	if(current_ptr == NULL){
		insert_at_beg(x);
	} else {
		while(current_ptr->next != NULL) {
			current_ptr = current_ptr->next;
		}
		current_ptr->next = temp;
	}	
}

void insert_at_node(int val, int pos) {
	if (pos > count_node() + 2) {
		cout << "Cannot insert here!" <<endl;
	} else {
		struct node *current_ptr;
		struct node *temp;
		current_ptr = Head;
		temp = new node;
		temp->info = val;
		temp->next = NULL;
		if(pos == 1) {
			insert_at_beg(val);
		} else if (pos == count_node() + 1) {
			insert_at_end(val);
		} else {
			struct node *temp_1;
			for(int i=2; i<pos; i++){				
				current_ptr = current_ptr->next;
			}	
			temp_1 = current_ptr->next;
			current_ptr->next = temp;		
			temp->next = temp_1;
		}		
	}
}

bool del_node_val(int val) {
	struct node *temp;
	bool deleted = false;
	if(Head->info == val) {
		temp = Head;
		Head = Head->next;
		delete temp;
		deleted = true;
	} else {	
		struct node *cur_ptr, *prev_ptr;
		prev_ptr = NULL;
		cur_ptr = Head;
		while(cur_ptr != NULL) {
			if(cur_ptr->info == val) {
				struct node *temp;
				temp = cur_ptr;
				prev_ptr->next = cur_ptr->next;
				delete temp;
				deleted = true;
				break;
			}
			prev_ptr = cur_ptr;
			cur_ptr = cur_ptr->next;
		}
	}
	return deleted;
}

int del_node(int pos) {
	if(pos>count_node()) {
		return -1;
	} else {
		if(pos == 1) {
			int temp_val = Head->info;
			
			if(Head->next != NULL) {
				Head = Head->next;
			} else {
				Head = NULL;
			}
			return temp_val;
		} else {
			struct node *prev_node;
			struct node *current_node;
			struct node *next_node;
			prev_node = Head;
			for(int i=0; i<pos-2; i++) {
				prev_node = prev_node->next;
			}
			current_node = prev_node->next;
			next_node = current_node->next;
			prev_node->next = next_node;
			
			return current_node->info;	
		}
	}
}

void display_all() {
	struct node *temp;
	temp = Head;
	while(temp != NULL) {
		cout << "Displaying "<< temp->info << endl;
		temp = temp->next;
	}
}

void sort_list(){
	struct node *cur_ptr, *prev_ptr;
	int k;
	for(prev_ptr = Head; prev_ptr != NULL; prev_ptr = prev_ptr->next) {
		for(cur_ptr = prev_ptr->next; cur_ptr != NULL; cur_ptr = cur_ptr->next) {
			if (prev_ptr->info > cur_ptr->info) {
				k = prev_ptr->info;
				prev_ptr->info = cur_ptr->info;
				cur_ptr->info = k;
			}
		}
	}
}

void reverse_list() {
	struct node *cur_ptr, *prev_ptr, *temp;
	cur_ptr = Head;
	prev_ptr = NULL;
	while(cur_ptr != NULL) {
		temp = prev_ptr;
		prev_ptr = cur_ptr;
		cur_ptr = cur_ptr->next;
		prev_ptr->next = temp;
	}
	Head = prev_ptr;
}

int main() {
	Head = NULL;
	int user_option;
	int temp, temp_1;	// to store user value
	bool loop = true;
	do {
		cout << "\n1. Insert at beginning\n2. Insertion at end\n3. Insertion at arbitary node" << endl;
		cout << "4. Count the number of node in SLL\n5. Deletion of a node based upon value\n6. Deletion of an arbitrary node" << endl;
		cout << "7. Display elements of SLL\n8. Reverse of a list\n9. Sort the list" << endl;
		cout << "10. Quit"<< endl;
		cin >> user_option;
		switch(user_option) {
			case 1:
				cout << "Enter the value: ";
				cin >> temp;
				insert_at_beg(temp);
				break;
				
			case 2:
				cout << "Enter the value: ";
				cin >> temp;
				insert_at_end(temp);
				break;
			
			case 3:
				int position;
				cout << "Enter the value: ";
				cin >> temp;
				cout << "Enter the position: ";
				cin >> position;
				insert_at_node(temp, position);
				break;
			
			case 4:
				cout << "Number of nodes: " << count_node() << endl;
				break;
				
			case 5:		// Deletion of a node based upon value
				cout << "Enter the value of node: ";
				cin >> temp;
				if(del_node_val(temp))
					cout << "Succesfully deleted " << temp << endl;
				else
					cout << "No value found!!" << endl;
				break;
				
			case 6:
				cout << "Enter the value of node: ";
				cin >> temp;
				temp_1 = del_node(temp);
				if(temp_1 == -1)
					cout << "Cannot delete arbitrary element!" << endl;
				else
					cout << "Deleted item: " << temp_1 << endl;
				
				break;
				
			case 7:		// Display
				display_all();
				break;
				
			case 8:		// Reverse
				reverse_list();
				break;
				
			case 9:		// Sort
				sort_list();
				break;
				
			case 10:	// End Loop
				loop = false;
				break;
				
			default:
				cout << "Invalid entry !" << endl;
		}
	} while(loop);
}
