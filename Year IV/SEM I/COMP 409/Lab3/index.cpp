#include <fstream>
#include <iostream>

using namespace std;

struct node {
  int id;
  struct node *a;
  struct node *b;
}*startState;

void createStates() { 
  struct node *s1;
  struct node *s2;
  struct node *s3;
  struct node *s4;

  s1 = new node;
  s2 = new node;
  s3 = new node;
  s4 = new node;

  s1->id = 1;
  s1->a = s2;
  s1->b = s1;

  s2->id = 2;
  s2->a = s3;
  s2->b = s1;
  
  s3->id = 3;
  s3->a = s4;
  s3->b = s1;

  s4->id = 4;
  s4->a = s4;
  s4->b = s4;

  startState = s1;
}

int main() {
  createStates();

  // Read input from file
  ifstream file;
  file.open("input.txt");
  string input;
  file >> input;

  struct node *nextState = startState;
  for (char &c : input) {
    cout << "(" << nextState->id << ", " << c << ")" << endl;
    if (c == 'a')
      nextState = nextState->a;
    else if (c == 'b') 
      nextState = nextState->b;
    else
      throw invalid_argument("Invalid alphabet provided");
  }

  if (nextState->id == 4) {
    cout << "String Accepted" << endl;
    return 1;
  }
  cout << "String Rejected" << endl;
}