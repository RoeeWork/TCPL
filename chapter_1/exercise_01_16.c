#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
/*void copy(char to[], char from[]);*/


main () 
{
	int line_lenght;
	char line[MAXLINE];

	while((line_lenght = getline(line, MAXLINE)) > 0)
		printf("%d\n", line_lenght);

	return 0;
}

int getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}

/*void copy(char to[] char from[])
{
	
}*/
