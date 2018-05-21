#include <stdio.h>
#include<conio.h>
 
int main()
{
   int row,col, i, j, matrix[10][10], transpose[10][10];
 
   printf("Enter the number of rows and columns of matrix\n");
   scanf("%d%d", &row, &col);
 
   printf("Enter the elements of matrix\n");
 
   for (i=0; i<row; i++)
      	{	
	  		for(j=0; j < col; j++)
        		scanf("%d",&matrix[i][j]);
 		}
 		
   for (i=0; i<row; i++)
      for(j=0 ; j <col ; j++ )
         transpose[j][i] = matrix[i][j];
 
   printf("Transpose of entered matrix :-\n");
 
   for (i=0; i<row; i++) {
      for (j=0; j<col; j++)
         printf("%d\t",transpose[i][j]);
      printf("\n");
   }
 
   getch();
}
