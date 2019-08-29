#include<stdio.h>
#include<conio.h>

int main()

{
	int score;
	printf("Enter your score :: ");
	scanf("%d",&score);
	switch(score/10)
	{
		case 10:
       	case 9 :
            printf("Your Grade : A\n" );
           	break;
       	case 8 :
       	case 7 :
            printf("Your Grade : B\n" );
           	break;
       	case 6 :
       	case 5 :
           	printf("Your Grade : C\n" );
           	break;
       	case 4 :
           	printf("Your Grade : D\n" );
           	break;
       	default :
            printf("You failed\n" );
	}
	getch();
	
}
