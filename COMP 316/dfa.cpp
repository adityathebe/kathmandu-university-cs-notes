#include <iostream>
using namespace std;

int i;
struct state {
	int label;
	struct state *in0;
	struct state *in1;
};

state* getNextState (state *cur_state, char input) {
	if (input == '0') return cur_state->in0;
	else return cur_state->in1;
}

state** createDFA (int total_states) {
	state** states = new state*[total_states];
	for ( i = 0; i < total_states; i++) {
		struct state *temp;
		temp = new state;
		temp->label = i;
		states[i] = temp;
	}
	return states;
}

void setTransition (state **states, int transition[]) {
	cout << "Size: " << sizeof(transition) / 2;
	for ( i = 0; i < sizeof(transition) / 2 ; i += 2 ) {
		states[i/2]->in0 = states[transition[i]];
		states[i/2]->in1 = states[transition[i + 1]];
	}
}

int main() {

	int total_states;
	cout << "Total states: ";
	cin >> total_states;
	state** states = createDFA(total_states);
	state* current_state = states[0];
	int transitions[] = {1, 0, 0, 1};
	setTransition(states, transitions);

	// Take Input String
	string input;
	cout << "Enter a string: ";
	cin >> input;
	
	//	Make transition
	for (i = 0; i < input.length(); i++) {
		char alphabet = input[i];
		current_state = getNextState(current_state, alphabet);
	}

	// Display Final State
	cout << current_state->label;
	return 0;
}