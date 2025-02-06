#include <stdio.h>

main()
{
	int char_prev, char_curr;

	for(char_prev = 0; (char_curr = getchar()) != EOF; char_prev = char_curr)
	{
		if(char_prev == ' ' && char_curr == ' ')
			;
		else putchar(char_curr);
	}
}
