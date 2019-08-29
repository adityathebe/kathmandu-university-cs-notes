#include<iostream>
#include<cstdlib>
#define MAX_SIZE 3
 
using namespace std;
 
class Queue{
    private:
        int item[MAX_SIZE];
        int head;
        int tail;
    public:
        Queue();
        void enqueue(int);
        int dequeue();
        int size();
        void display();
        bool isEmpty();
        bool isFull();
};
 
Queue::Queue(){
    head = 0;
    tail = 0;
}
 
 
void Queue::enqueue(int data){
    item[tail] = data;
    tail = (tail+1)%MAX_SIZE;
}
 
 
int Queue::dequeue(){
    int temp;
    temp = item[head];
    head = (head+1)%MAX_SIZE;
    return temp;
}
 
 
int Queue::size(){
    return (tail - head);
}
 
void Queue::display(){
    int i;
    if(!this->isEmpty()){
        for(i=head; i!=tail; i=(i+1)%MAX_SIZE){
            cout<<item[i]<<endl;
        }
    }else{
        cout<<"Queue Underflow"<<endl;
    }
}
 
 
bool Queue::isEmpty(){
    if(abs(head == tail)){
        return true;
    }else{
        return false;
    }
}
 
bool Queue::isFull(){
    if(head==(tail+1)%MAX_SIZE){
        return true;
    }else{
        return false;
    }
}
 
 
int main(){
    Queue queue;
    int choice, data;
    while(1){
        cout<<"\n1. Enqueue\n2. Dequeue\n3. Size\n4. Display all element\n5. Quit";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
            if(!queue.isFull()){
                cout<<"\nEnter data: ";
                cin>>data;
                queue.enqueue(data);
            }else{
                cout<<"Queue is Full"<<endl;
            }
            break;
            case 2:
            if(!queue.isEmpty()){
                cout<<"The data dequeued is :"<<queue.dequeue();
            }else{
                cout<<"Queue is Emtpy"<<endl;
            }
            break;
            case 3:
            cout<<"Size of Queue is "<<queue.size();
            break;
            case 4:
            queue.display();
            break;
            case 5:
            exit(0);
            break;
        }
    }
    return 0;
}
