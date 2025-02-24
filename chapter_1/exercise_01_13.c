#include <stdio.h>

 /* prints a histogram of the lenghts of words in tis input */

main()
{
	char c;

	printf("INPUT: ");
	while((c = getchar()) != EOF)
	{
		if(c != ' ' && c != '\n')
		{
			printf("X");
		}
		else
		{
			printf("\n");
		}
	}
}

