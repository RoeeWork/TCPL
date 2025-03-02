#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int limit);

main()
{
	int c;
	char line[MAXLINE];

	while ((c = getline(line, MAXLINE)) > 0)
	{
		if (c > 80) { 
			printf("%s\n", line);
		}
	}
	return 0;
}

int getline(char line[], int limit)
{
	char c;
	int i;

	for (i = 0; ((c = getchar()) != EOF) && i < limit && c != '\n' ; ++i)
	{
		line[i] = c;
	}
	if (c == '\n')
	{
		line[i] = c;
		++i;
	}
	return i;
}
