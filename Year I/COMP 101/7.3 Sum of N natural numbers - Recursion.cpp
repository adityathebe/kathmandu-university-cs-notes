/* Sum of n natural numbers
			- Aditya */

#include <stdio.h>
#include <conio.h>

long int sum(int a); // Function Prototype

int main()
{
	int num; 
	printf("N = ");
	scanf("%d",&num);
	printf("sum = %d",sum(num));
	getch();
}

long int sum(int a) // Function definition
{
	if (a>=1)
		return a+sum(a-1); // Recursion
	else 
		return 0;
}
