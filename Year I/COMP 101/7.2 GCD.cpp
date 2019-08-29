#include <stdio.h>
#include <conio.h>
int gcd(int a, int b);	// Funcion Prototype

int main()
{
   int a, b;
   printf("Enter two positive integers: ");
   scanf("%d %d", &a, &b);
   printf("G.C.D of %d and %d is %d.", a, b, gcd(a,b));
   getch();
}

int gcd(int a, int b) // Function Definition
{
    while(a!=b)
    {
    	if(a>b)
    		return gcd(a - b, b);
    	else
    		return gcd(a, b - a);
	}
	
	return a;
} 	
