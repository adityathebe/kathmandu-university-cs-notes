// Addition of two square matrix
#include <stdio.h>
#include <conio.h>

int i,j,row,col, matA[10][10], matB[10][10], matRes[10][10];
int add(int a[][10] , int b[][10]); // Function prototype

int main()
{
	printf("Enter the order of matrix :: ");
	scanf("%d",&row);
	col=row;
	
	printf("Enter the elements of Matrix A\n");
	for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				scanf("%d",&matA[i][j]);
			}	
		}
		
	printf("Enter the elements of Matrix B\n");
	for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				scanf("%d",&matB[i][j]);
			}	
		}
		
	printf("\nThe Sum two Matrices is :: \n");
	
	add(matA,matB); // Function calling
}

int add(int a[][10],int b[][10]) // Function Definition
{
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			matRes[i][j] = a[i][j] + b[i][j];
			printf("%d\t",matRes[i][j]);
		}
		printf("\n");
	}

}


