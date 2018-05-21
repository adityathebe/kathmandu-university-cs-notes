// Evaluate Postfix expressionss

#include <iostream>
#include "stack.h"
#include <conio.h>

bool isOperator(char x) {
	char operators[10] = {'+','-','*','/','%'};
	int count = 0;
	bool isop = false;
	while(count < strlen(operators)) {
		if(x == operators[count]) {
			isop =  true;
			break;
		}
		count++;
	}
	return isop;
}

float operate(float x, float y, char symbol) {
	switch(symbol) {
		case '+':
			return x+y;
			break;
		case '-':
			return x-y;
			break;
		case '*':
			return x*y;
			break;
		case '/':
			return x/y;
			break;
		case '%':
//			return x % y;
			break;
	}
}

int main() {
	int N;
	float tempResult;
	string user_input;
	Stack s1;
	cout << "Enter the postfix expression: " ;
	cin >> user_input;
	N = user_input.length();
	for(int i=0; i<N; i++) {
		char cur_val = user_input[i];
		if(!isOperator(cur_val)) {
			cout << "Pushed: " << (cur_val - 48) << endl;
			s1.push(cur_val - 48);
		} else {
			float tempY = s1.pop();
			float tempX = s1.pop();
			tempResult = operate(tempX,tempY,cur_val);
			cout << "Operating -> " << tempX << cur_val << tempY << " = " << tempResult <<endl;
			s1.push(tempResult);		
		}
	}	
	cout << "Answer: " << tempResult << endl;
}
