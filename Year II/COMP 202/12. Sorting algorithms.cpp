#include <iostream>
#include <conio.h>
#define SIZE 15

using namespace std;

// Sorting functions
void insertion_sort(int num[], int size);
void bubble_sort(int num[], int size);
void selection_sort(int num[], int size);
void merge_sort(int num[], int left, int right);
void quick_sort(int num[], int);

// Utility funcitons
void merge(int num[], int left, int middle, int right);
void display(int num[], int size);

int main() {
	int numbers[SIZE] = {84, 58, 23, 11, 92, 33, 67, 54, 34, 100, 7, 1, 105, 123, 55};
//	insertion_sort(numbers, SIZE);
//	bubble_sort(numbers, SIZE);
//	selection_sort(numbers, SIZE);
//	merge_sort(numbers, 0, SIZE-1);
	quick_sort(numbers, SIZE);
	display(numbers, SIZE);
	getch();
}

void insertion_sort(int num[], int size) {
	int key, j;
	for(int i=0; i<size; i++) {
		key = num[i];
		j = i - 1;
		while (j >=0 && num[j] > key) {
			num[j+1] = num[j];
			j = j - 1;
		}
		num[j+1] = key;
	}
}

void bubble_sort(int num[], int size) {
	for(int i=0; i<size; i++) {
		for(int j=0; j<size-i-1; j++) {
			if(num[j] > num[j+1]) {
				int temp = num[j+1];
				num[j+1] = num[j];
				num[j] = temp;
			}
		}
	}
}

void merge_sort(int num[], int left, int right) {
	if ( left < right ) {
		int middle = left + ( (right - left) / 2 );
		
		merge_sort(num, left, middle);
		merge_sort(num, middle+1, right);
		
		merge(num, left, middle, right);
	}
}

void merge(int num[], int left, int middle, int right) {
	int n1 = middle - left + 1;
	int n2 = right - middle;
	
	//	Create temp arrays
	int L[n1], R[n2];
	
	//	Copy data to temp arrays
	for (int i=0; i<n1; i++) {
		L[i] = num[left + i];
	}
	for (int j=0; j<n2; j++) {
		R[j] = num[middle + 1 + j];
	}
	
	// Merge the temp arrays back into num
	int i = 0;
	int j = 0;
	int k = left;
	
	while ( i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			num[k] = L[i];
			i++;
		} else {
			num[k] = R[j];
			j++;
		}
		k++;
	}
	
	// copy the remaining elements of L[] if there are any
	while(i < n1) {
		num[k] = L[i];
		i++;
		k++;
	}
	
	// copy the remaining elements of R[] if there are any
	while(j < n2) {
		num[k] = R[j];
		j++;
		k++;
	}
}

void selection_sort(int num[], int size) {
	for(int i=0; i<size; i++) {
		int smallest = num[i];
		int smallestIndex = i;
		
		// Find minimum from (i+1, SIZE)
		for(int j=i+1; j<size; j++) {
			if(smallest > num[j]) {
				smallest = num[j];
				smallestIndex = j;
			}
		}
		
		// Swap first element with smallest if needed
		if(num[i] > smallest) {
			num[smallestIndex] = num[i];
			num[i] = smallest;
		}
	}	
}

void display(int num[], int size) {
	for(int i=0; i<size; i++) {
		cout << num[i] << endl;
	}
}
