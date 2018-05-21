//1.	Insertion at beginning					- Done
//2.	Insertion at end						- Done
//3.	Insertion at arbitary node				- Done
//4.	Count the number of node in SLL			- Done
//5.	Deletion of a node based upon value		- Pending
//6.	Deletion of an arbitrary node			- Done
//7.	Display elements of SLL					- Done
//8.	Reverse of a list						- Done
//9.	Sort the list (ascending order)			- Done

#include <iostream>
using namespace std;

struct node {		
	int info;
	node *next;
	node *prev;
} *Head, *Tail;

int count_node() {
	int count = 0;
	node *temp;
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
	temp->prev = NULL;
	if ( Head == NULL) {
		Head = temp;
		Tail = temp;
	} else {
		temp->next = Head;
		Head->prev = temp;
		Head = temp;
	}
}

void insert_at_end(int x) {
	struct node *temp;
	struct node *curPtr;
	temp = new node;
	temp->info = x;
	temp->next = NULL;
	temp->prev = NULL;
	curPtr = Head;
	if(curPtr == NULL){
		insert_at_beg(x);
	} else {
		while(curPtr->next != NULL) {
			curPtr = curPtr->next;
		}
		curPtr->next = temp;
		temp->prev = curPtr;
		Tail = temp;
	}	
}

void insert_at_node(int val, int pos) {
	if (pos > count_node() + 1 || pos == 0) {
		cout << "Cannot insert here!" <<endl;
	} else {
		if(pos == 1) {
			insert_at_beg(val);
		} else if (pos == count_node() + 1) {
			insert_at_end(val);
		} else {
			struct node *curPtr;
			struct node *prevPtr;
			struct node *temp;

			curPtr = Head;
			temp = new node;
			temp->info = val;
			temp->next = NULL;
			temp->prev = NULL;
			
			for(int i=1; i<pos; i++){				
				curPtr = curPtr->next;
			}	
			prevPtr = curPtr->prev;

			prevPtr->next = temp;
			temp->prev = prevPtr;
			curPtr->prev = temp;		
			temp->next = curPtr;
		}		
	}
}

int deleteByPosition(int pos) {
	if(pos > count_node() || pos == 0) {
		return -1000;
	} else {
		if(pos == 1) {
			int tempValue = Head->info;
			struct node *tempPtr;
			tempPtr = Head;
			if(Head->next != NULL) {
				Head = Head->next;
			} else {
				Head = NULL;
			}
			delete tempPtr;
			return tempValue;
		} else {
			struct node *prevNode;
			struct node *currentNode;
			struct node *nextNode;
			int nodeCount = count_node();
			currentNode = Head;
			for(int i=1; i<pos; i++) {
				currentNode = currentNode->next;
			}
			int tempValue = currentNode->info;
			prevNode = currentNode->prev;
			nextNode = currentNode->next;
			prevNode->next = nextNode;
			if(pos != nodeCount) {
				cout << "Position: " << pos << endl;
				cout << "Node Count: " << count_node() << endl;
				cout << "HERE" << endl;
				nextNode->prev = prevNode;
			}
			delete currentNode;
			return tempValue;	
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

void reverse_list() {
	struct node *curPtr;
	curPtr = Tail;
	while(curPtr != NULL) {
		cout << curPtr->info << endl;
		curPtr = curPtr->prev;
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

int main() {
	int user_option;
	int temp, tempVal;
	bool loop = true;
	do {
		cout << "\n1. Insert at beginning\n2. Insertion at end\n3. Insertion at arbitary node" << endl;
		cout << "4. Count the number of node in SLL\n5. Deletion of an arbitrary node" << endl;
		cout << "6. Display elements of SLL\n7. Reverse of a list\n8. Sort the list" << endl;
		cout << "9. Quit"<< endl;
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
				
			case 5:
				cout << "Enter the position of node: ";
				cin >> temp;
				tempVal = deleteByPosition(temp);
				if(tempVal == -1)
					cout << "Cannot delete arbitrary element!" << endl;
				else
					cout << "Deleted item: " << tempVal << endl;
				
				break;
				
			case 6:		// Display
				display_all();
				break;
				
			case 7:		// Reverse
				reverse_list();
				break;
				
			case 8:		// Sort
				sort_list();
				break;
				
			case 9:	// Quit
				loop = false;
				break;
				
			default:
				cout << "Invalid entry !" << endl;
		}
	} while(loop);
}
