/* Average of N Numbers using array
		- Aditya */

#include <stdio.h>
#include <conio.h>

int a,z=0,sum=0,num[80];
float avg;
int main()
{
	printf("How many numbers ?\n");
	scanf("%d",&a);
	
	for(int i;i<a;i++)
	{
		printf("Enter %d number: ",i+1);
		scanf("%d",&num[i]);
		sum = sum + num[i];
	}
	printf("***********************");
	printf("\nSum of %d numbers = %d\n",a,sum);
	avg = (float) sum/a; // Type Casting
	printf("Their average = %.2f",avg);
	printf("\n\n\n\t- Aditya Thebe Limbu \\m/(0_0)\\m/");
	getch();

}


