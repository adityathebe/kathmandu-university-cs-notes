#include<stdio.h>
#include<conio.h>
#define PI 3.141593

int main()

{
	float radius,cir,area;
	printf("Enter the radius of circle:");
	scanf("%f",&radius);
	area = PI * radius * radius;
	cir = 2 * PI * radius;
	printf("Area of circle = %.2f",area);
	printf("\nCircumference = %.2f",cir);
	getch();	
}
