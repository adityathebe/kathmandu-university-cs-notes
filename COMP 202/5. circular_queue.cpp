#include <iostream>
#include <conio.h>
#define SIZE 4
using namespace std;

// array = 0,1,2,3

class cQueue {
	private:
		int queue[SIZE];
		int front;
		int rear;
	
	public:
		cQueue() {
			front = - 1;
			rear = 0	;
		}
		
		void MakeEmpty() {
			front = SIZE - 1;
			rear = SIZE - 1;
		}
		
		bool isFull() {
			return front == (rear + 1) % SIZE;
		}
		
		bool isEmpty() {
			return (front == rear);
		}
		
		void enqueue(int x) {
			rear = (rear + 	1) % SIZE;
			queue[rear] = x;
		}
		
		int dequeue() {
			front = (front + 1) % SIZE;
			return queue[front];
		}
		
		void fr() {
			cout <<"front: " << front << "\tRear: " << rear << endl;
		}
		
		void display() {
			if(isEmpty())
				cout << "****** Queue is Empty ***** " << endl;
			else {
				for(int i = front; i<rear ; i++) {
					if(front <= rear)
						cout << "Element is : " << queue[i] << '\t';
				}
			}
		}
};

int main() {
	cQueue q;
	bool loop = true;
	int user_option;
	
	do {
		cout << "\nOptions\n1.Enqueue\t2.Dequeue\t3.isFull\t4.isEmpty\t5.Display\t6.Quit: ";
		cin >> user_option;
		int temp;
		switch(user_option) {
			case 1:
				if(!q.isFull()) {
					cout << "Enter a number to enqueue: ";
					cin >> temp;
					q.enqueue(temp);
				} else {
					cout << "***** Queue Overflow *****" << endl;
				}
				break;
				
			case 2:
				if(!q.isEmpty())
					cout << "Dequeued item : " << q.dequeue() << endl;
				else
					cout << "***** Queue underflow *****" << endl;
				break;
				
			case 3:
				if(q.isFull())
					cout << "***** The Queue is Full! *****" <<endl;
				else
					cout << "***** The Queue is not full *****" << endl;
				break;
			
			case 4:
				if(q.isEmpty())
					cout << "***** The queue is empty *****" << endl;
				else
					cout << "***** The queue is not empty. *****" << endl;
				break;
				
			case 5:
				q.display();
				break;
				
			case 6:
				q.fr();
				break;
				
			default:
				loop = false;
				break;					
		}
		
	} while(loop);
}
