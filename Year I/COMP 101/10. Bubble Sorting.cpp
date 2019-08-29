/* Bubble sort code */
 
#include <stdio.h>
#include <conio.h> 

int main()
{
	int array[100], n, temp;
	
	printf("Enter number of elements\n");
	scanf("%d", &n);
	
	// Take the numbers
	printf("Enter %d integers\n", n);
	for (int c = 0; c < n; c++) 
	scanf("%d", &array[c]);
	
	
	// SORTING
	for (int c = 0 ; c < ( n - 1 ); c++)
	{
		for (int d=0 ; d < n - c - 1; d++)
		{
		  if (array[d] > array[d+1]) /* For decreasing order use < */
		  {
		    temp       = array[d];
		    array[d]   = array[d+1];
		    array[d+1] = temp;
		  }
		}
	}
	
	
	// Output
	printf("Sorted list in ascending order:\n");
	for ( int c = 0 ; c < n ; c++ ) 
	printf("%d\n", array[c]);
	
	return 0;
}
