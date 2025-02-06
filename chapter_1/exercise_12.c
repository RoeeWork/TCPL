#include <stdio.h>

 /* Prints its input one word per line */

main()
{
	char ch;

	while ((ch = getchar()) != EOF)
	{
		if (ch == ' ' || ch == '\t')
		{
			putchar('\n');
		}
		else
		{
			putchar(ch);
		}
	}
}
