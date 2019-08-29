// Read a sentence and count the total number of character using while loop

#include<stdio.h>
#include<conio.h>

#define EOL '\n'

int main()
{
	char words[80];
	int count=0;
	printf("Type a sentence and press enter\n");
	
	while( (words[count] = getchar() ) != EOL )
	{
		if(words[count] == ' ') // if it contains blank space
			continue;			// donot count
		count++;
	}	
	printf("Total words = %d",count);
	getch();	
}
