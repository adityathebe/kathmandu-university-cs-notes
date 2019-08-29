// Calculate the percentage

#include<stdio.h>
#include<conio.h>

int main()
{
	float a,b,c,d,total,per;
	printf("Enter the marks for maths, physics, chemistry, computer\n");
	scanf("%f%f%f%f",&a,&b,&c,&d);
	total = a+b+c+d;
	per = (total * 100 ) / 80;
	printf("Percentage = %.2f",per) ;
	getch();	
}
