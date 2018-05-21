// Factorial of a given number

#include <stdio.h>
#include <conio.h>

long int fact(int a); // Function Prototype

int main()
{
   int num;   
   printf("Enter a positive integer: ");
   scanf("%d",&num);
   printf("It's factorial = %ld",fact(num));
   getch();
}

long int fact(int a) // Function definition
{
    if (a>1)
    	return a * fact(a-1);
    else
    	return 1;
}
