#include <stdio.h>
#define MAX_WORDS 100

main()
{
	int c, i, word_number = 1, max_arr[MAX_WORDS];

	/* set all values of max_arr[] to 0. */
	for(i = 0; i < MAX_WORDS; ++i) { max_arr[i] = 0;}

	/* Insert all words lenghts into the array. */
	while((c = getchar()) != '\n')
	{
		printf("word_number: %d\n", word_number);
		if(c != ' ' && c != '\t' && c != '\n')
		{
			++max_arr[word_number];
		}
		else
		{
			++word_number;
		}
		printf("lenght: %d\n", max_arr[word_number]);

	}

	/* reduce max_arr's size with word_arr */
	int word_arr[word_number];
	for(i = 0; i < word_number; ++i)
	{
		word_arr[i] = max_arr[i];
	}


/*need to find max value in word_arr*/

	int state = word_number;
	printf("state: %d\n", state);


	for(; state > 0; --state)
	{
		printf("%d", state);
		for(i = 0; i < word_number; ++i)
		{
			if(word_arr[i] == state)
			{
				printf("X ");
				--word_arr[i];
			}
		}
		printf("\n");
	}
}
