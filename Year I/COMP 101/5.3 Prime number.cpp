// Identifying a prime number

#include<stdio.h>
#include <stdlib.h>
#include<conio.h>

int main()
{
	int num;
	printf("Enter a number :: \n");
	scanf("%d",&num);
	
	for(int i=2;i<=num;i++)
	{
		if((num %  i) != 0)
			exit(0);
			
		else if(i==num)
			{
				printf("Prime number");
				break;
			}
			
		else
		{
			printf("Not a prime number \n");
			break;
		}
	}
}
