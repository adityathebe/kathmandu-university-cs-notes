#include <iostream>
#include <cstdlib>
#include "BST.cpp"

using namespace std;

int main() {
	int keys[10] = {10,15,4,6,23,90,40,55,17,89};
	BST myTree;

	for(int i=0; i<10; i++) {
		myTree.addLeaf(keys[i]);
	}

	myTree.display();	
}
