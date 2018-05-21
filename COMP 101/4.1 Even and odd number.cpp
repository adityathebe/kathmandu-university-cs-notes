#include<stdio.h>
#include<conio.h>

int main()

{
	int i;
	printf("Enter a number : ");
	scanf("%d",&i);
	if(i%2 == 0)
	{
		printf("Even Number.");
	}
	else
	printf("Odd Number.");
	getch();	
}
