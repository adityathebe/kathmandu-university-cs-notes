// Structure

#include <stdio.h>
#include <conio.h>

int i,j,k,row1,col1,row2,col2,sum,matA[10][10],matB[10][10],matRes[10][10];

int main()
{
	// Working with Matrix A
	printf("Enter the number of rows and columns for Matrix A :: ");
	scanf("%d%d",&row1,&col1);
	
	printf("Enter the elements of Matrix A\n");
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col1;j++)
		{
			scanf("%d",&matA[i][j]);
		}
	}
	
	// Working with Matrix B
	printf("Enter the number of rows and columns for Matrix B :: ");
	scanf("%d%d",&row2,&col2);
	
	if(row2!=col1)
	{
		printf("This multiplication is invalid"); // Matrices with unequal row and columns cannot be multiplied
	}
	
	else
	{
		printf("Enter the elements of Matrix B\n");
		for(i=0;i<row2;i++)
		{
			for(j=0;j<col2;j++)
			{
				scanf("%d",&matB[i][j]);
			}
		}
	
		// Multiplying two matrices
		for(i=0;i<row1;i++)
		{
			for(j=0;j<col2;j++)
			{
				for(k=0;k<row1;k++)
				{
					sum = sum + matA[i][k] * matB[k][j];
				}
			matRes[i][j] = sum;
	        sum = 0;
	    	}
		}
		
		// Display result
		printf("The Product of Matrix A & Matrix B is \n");
		for(i=0;i<row1;i++)
		{
			for(j=0;j<col2;j++)
			{
				printf("%d\t",matRes[i][j]);
			}
			printf("\n");
		}	
	
	}
	getch();	
}
