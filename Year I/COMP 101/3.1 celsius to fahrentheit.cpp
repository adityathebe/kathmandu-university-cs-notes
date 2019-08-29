#include<conio.h>
#include<stdio.h>

int main()
{
	float cel, fahr;
	printf("Enter temperature in celsius");
	scanf("%f",&cel);
	
	fahr=((cel*9)/5) +32;
	printf("%.2f", fahr);
	getch();
	
}
