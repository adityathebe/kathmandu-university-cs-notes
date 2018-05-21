#include<stdio.h>
#include<conio.h>

int aditya (int a); // Function protype
int num,sum=0;
int main()
{
	printf("Enter a number :: ");
	scanf("%d",&num);
	aditya(num);
	getch();	
}

int aditya(int a) // Funcion Definition
	{
	 	for(int i=1;i<num;i++)
			{
			if(num%i == 0)
				sum=sum+i;	
			}
	
		if (sum==num)
			printf("%d is a perfect number",num);
		else
			printf("%d is not a perfect number",num);
	}

	
