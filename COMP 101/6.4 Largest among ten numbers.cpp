// Largest among ten numbers

#include <stdio.h>
#include <conio.h>

int num[10],large,b; // Global Variables
int largest(int a); // Function protype

int main()
{
	for(int i=0;i<10;i++)
	{
		printf("Enter number %d = ",i+1);
		scanf("%d",&num[i]);
		large = largest(num[i]); // Calling Function
	}
	printf("\n\n\n%d is the largest number",large);
	getch();
}

int largest(int a) // Function definition
{
	if (a>=b)
		{
			//b=a;
			return a;
			b=a;
		}
	else
		{
			return b;
		}
}
