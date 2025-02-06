#include <stdio.h>

main()
{
	double blank_number, tab_number, newline_number;
	int character;

	blank_number = 0.0;
	tab_number = 0.0;
	newline_number = 0.0;


	while ((character = getchar()) != EOF)
	{
		if (character == ' ')
			++blank_number;
		if (character == '\t')
			++tab_number;
		if (character == '\n')
			++newline_number;
	}
	printf("blanks: %.0f\ntabs: %.0f\nnewlines: %.0f\n", blank_number, tab_number, newline_number);
}
