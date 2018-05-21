#include <stdio.h>
#include <conio.h>
int gcd(int a, int b);	// Function Prototype

int main(void)
{
	int a, b;
	printf("Enter two positive integers: ");
	scanf("%d %d", &a, &b);
	printf("G.C.D of %d and %d is %d.", a, b, gcd(a,b));
	getch();
	return 0;
}

int gcd(int a, int b) // Function Definition
{
    int result=1, k=2;
    while(k<=a && k<=b)
    {
    	if(a%k==0 && b%k ==0)
    		{
				result=k;
    		}
		k++;
	}
	
	return result;
} 	
