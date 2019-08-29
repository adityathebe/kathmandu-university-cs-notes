// Structure

#include <stdio.h>
#include <conio.h>
#include <string.h>

struct STUDENT {
	char name[20];
	int roll_no;
	float GPA;
};

int i,j;

int main()
{
	struct STUDENT s[5];
	for(int i=0;i<5;i++)
	{
		printf("Enter Student's Name : ");
		scanf("%s",&s[i].name);
		printf("Enter the roll no: ");
		scanf("%d",&s[i].roll_no);
		printf("Enter GPA : ");
		scanf("%f",&s[i].GPA);
		printf("\n");
	}

	for (int j=0;j<5;j++)
	{
		printf("\n\nStudent's Name : %s",s[j].name);
		printf("\t\tRoll No : %d",s[j].roll_no);
		printf("\t\tSection : %.2f",s[j].GPA);
	}
	
	getch();
}
