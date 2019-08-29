/* Infix to Postfix */

// A+(B*C-(D/E-F)*G)*H --> ABC*DE/F-G*-H*+

#include "stack.h"
#include <iostream>
#include <string.h>

using namespace std;

bool isOperator(char x) {
	char operators[10] = {'+','-','*','/','%','(',')'};
	int count = 0;
	bool isop = false;
	while(count < strlen(operators)) {
		if(x == operators[count])
			isop =  true;
		count++;
	}
	return isop;
}

int getWeight(char x) {
	switch(x) {
		case '(': return 1;
		case '+':
	    case '-': return 2;
	    case '*':
	    case '/': 
	    case '%': return 3; 
	    case ')': return 4;
	}
}

int main() {	
	Stack s1;
	string user_input;
	string postfix = "";
	int N;
	
	cout << "Enter the infix expresion: ";
	cin >> user_input;
	N = user_input.length();
	
	for(int i=0; i<N; i++) {
		if (!isOperator(user_input[i])) {
			cout << "Added " << user_input[i] << " to the postfix string" << endl;
			postfix += user_input[i] ;
			cout << "Current postfix status: " << postfix << endl << endl;
		}
		else {
			if(s1.isEmpty()) {
				cout << "pushed operator: " << user_input[i] << " inside empty stack" << endl;
				s1.push(user_input[i]);
			} else {
				// Compare the precedence of current operator and the one in stack 
				if(getWeight(s1.peek()) >= getWeight(user_input[i])) {
					if(user_input[i] == ')') {
						while(s1.peek() != '(') {
							postfix += s1.pop();
						}
						s1.pop();
			 		} else {
						int stackTop = s1.topVal();
						while(stackTop >= 0) {
							if(getWeight(s1.peek()) >= getWeight(user_input[i])) {
								if(s1.peek() != '(' || s1.peek() != ')')
									postfix += s1.pop();0
								cout << "(Inside topVal) Current postfix: " << postfix << endl;
							}
							stackTop--;
						}
						s1.push(user_input[i]);
					}
				} else {
					cout << "pushed operator: " << user_input[i] << " inside not empty stack" << endl;
					s1.push(user_input[i]);
				}
			}
		} 
	}
	
	if(!s1.isEmpty()) {
		int stackTop = s1.topVal();
		while(stackTop >= 0) {
			postfix+=s1.pop();
			stackTop--;
		}
	}
	
	cout << "\nAnswer:" <<postfix;
}
