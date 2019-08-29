#include<stdio.h>
#include<conio.h>
#include<math.h>
 
int main()
{
   	double a, b, c, s, area; 
   	printf("Enter the sides of triangle :: "); 
   	scanf("%lf%lf%lf",&a,&b,&c);
    
   	s = (a+b+c)/2;
   	area = sqrt(s*(s-a)*(s-b)*(s-c));
 
   	printf("Area = %.2lf\n", area);
	getch();
	//return 0; 
}
