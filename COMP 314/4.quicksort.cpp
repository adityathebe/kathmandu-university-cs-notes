#include <iostream>

using namespace std;

void swap(int elements[], int x, int y) {
	int temp = elements[x];
	elements[x] = elements[y];
	elements[y] = temp;
}

int settlePivotElement (int elements[], int lowerRange, int upperRange) {
	int pivotElement = elements[lowerRange];
	int pL = lowerRange + 1;
	int pR = upperRange;
	while ( true ) {
		while(pL <= pR && elements[pL] < pivotElement) { pL += 1; }
		while(pL <= pR && elements[pR] > pivotElement) { pR -= 1; }
		if (pL > pR) {
			break;
		}
		swap(elements, pL, pR);
	}

	swap(elements, lowerRange, pR);
	return pR;
}

void quickSort (int elements[], int lowerRange, int upperRange ) {
	int indexOfPivotElement = settlePivotElement(elements, lowerRange, upperRange);

	if (lowerRange <= indexOfPivotElement - 1 ) {
		quickSort(elements, lowerRange, indexOfPivotElement - 1);
	}

	if (indexOfPivotElement + 1 <= upperRange) {
		quickSort(elements, indexOfPivotElement + 1 , upperRange);
	}
}

int main() {
	int input[] = { 11, 32, 99, 5, 206, 258, 111, 25, 252, 82, 434,23, 477, 1111, 1, 24,362,364,250,177,295,241,411,441,234,263,386,47,222,368,260,374,291,404,74};
	int inputSize = (sizeof(input)/sizeof(*input));
	cout << "Input Size = " << inputSize << endl;
	quickSort(input, 0, inputSize);
	for (int i = 0; i < inputSize; i++ ) {
		cout << input[i] << " ";
	}
	cout << endl;
}