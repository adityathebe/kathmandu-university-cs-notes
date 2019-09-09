// Stack Implementation

#define SIZE 10
#include <conio.h>
#include <iostream>

using namespace std;

class Stack {
private:
  int stack[SIZE];
  int top = -1;

public:
  bool isEmpty() { return top == -1; }

  bool isFull() { return top == (SIZE - 1); }

  void push(int x) {
    if (!isFull()) {
      top++;
      stack[top] = x;
    } else {
      cout << "The stack full!!";
    }
  }

  int pop() {
    if (!isEmpty()) {
      int tempVal = stack[top];
      top--;
      return tempVal;
    } else {
      cout << "The stack is Empty!";
      return 0;
    }
  }

  int peek() {
    if (!isEmpty()) {
      return stack[top];
    }
  }
};

int main() {
  Stack myStack;
  int userOption, temp;
  int proceed = true;
  while (proceed) {
    cout << "\n1. PUSH\t2. POP\t3. FULL\t4. EMPTY\t5. PEEK\t6. QUIT" << endl;
    cin >> userOption;
    switch (userOption) {
    case 1:
      cout << "Enter the integer to be pushed: ";
      cin >> temp;
      myStack.push(temp);
      break;

    case 2:
      cout << endl << myStack.pop() << endl;
      break;

    case 3:
      if (myStack.isFull())
        cout << "The Stack is full" << endl;
      else
        cout << "The stack is not full!" << endl;
      break;

    case 4:
      if (myStack.isEmpty())
        cout << "The Stack is Empty!" << endl;
      else
        cout << "The stack is not empty!" << endl;
      break;

    case 5:
      if (!myStack.isEmpty())
        cout << '\n' << myStack.peek() << endl;
      else
        cout << "The stack is empty!" << endl;
      break;

    case 6:
      proceed = false;
      break;

    default:
      cout << "Invalid input";
      break;
    }
  }
}
