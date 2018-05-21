// Swapping two variables using Pointers and Function
#include <stdio.h>
#include <conio.h>

int a,b; // Global variables

int swap(int *a, int *b); // Function prototype

int main()
{
	printf("a = ");
	scanf("%d",&a);
	printf("b = ");
	scanf("%d",&b);
	swap(&a,&b);
	getch();
}

int swap(int *a, int *b) // Function definition
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	printf("A = %d, B = %d",*a,*b);	
}
