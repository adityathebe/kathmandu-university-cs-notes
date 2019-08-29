#include <stdio.h>
#include <conio.h>
#include <math.h> // Header file to use pow(a,b) library function

int a,b,c; // Global Variables
long int calc(int a, int b, int c); // Function prototype
int main()
{
	printf("Enter the value for a,b and c :: ");
	scanf("%d%d%d",&a,&b,&c);
	calc(a,b,c);
	getch();	
}

long int calc(int a,int b, int c) // Function definition
{
	if( (pow(b,2) - 4*a*c ) >=0)
		printf("Real Root");
	else
		printf("Imaginary Solution");
}
