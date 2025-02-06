#include <stdio.h>
#define MAX_WORDS 100

main()
{
	int c, i;
	int word_number = 1; /* Represents the number of words in the text-stream. */
	int max_arr[MAX_WORDS]; /* Saves the lenghts of each word in the text-stream. */

	/* Set all values of max_arr[] to 0. */
	for(i = 0; i < MAX_WORDS; ++i) { max_arr[i] = 0;}

	/* Insert all word lenghts into the array. */
	printf("input: ");
	while((c = getchar()) != '\n')
	{
		if(c != ' ' && c != '\t' && c != '\n')
		{
			++max_arr[ word_number - 1 ];
			/*if (word_number == 0) { ++word_number; }*/
		}
		else
		{
			++word_number;
		}
	}
	printf("output:\n");
	/* Reduce max_arr's size with word_arr */
	int word_arr[word_number];
	for(i = 0; i < word_number; ++i)
	{
		word_arr[i] = max_arr[i];
	}

    /* find max value in word_arr */
	int lenght = word_number;
	int max = word_arr[0];
	for(i = 0; i < lenght; ++i)
	{
		if(word_arr[i] > max) { max = word_arr[i]; }
	}

	/* Print! */
	int state = max;
	for(; state > 0; --state)
	{
		for(i = 0; i < word_number; ++i)
		{
			if(word_arr[i] == state)
			{
				printf(" X ");
				--word_arr[i];
			}
		}
		printf("\n");
	}
	for (i = 0; i < word_number; ++i) { printf("[%d]", i); }
}
