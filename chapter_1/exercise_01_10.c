#include <stdio.h>

main()
{
	int character;

	/* iterate through the text stream */

	while ((character = getchar()) != EOF)
	{
		if(character == '\t')
		{
			putchar('\\');
			putchar('t');
		}
		else if(character == '\b')
		{
			putchar('\\');
			putchar('b');
		}
		else if(character == '\\')
		{
			putchar('\\');
			putchar('\\');
		}
		else putchar(character);
	}
}
