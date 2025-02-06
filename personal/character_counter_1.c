#include <stdio.h>

main()
{
	/*
	double character_num;

	for(character_num = 0; getchar() != EOF; ++character_num);
	printf("%f", character_num);
	*/

	long nc;

	nc = 0;
	while (getchar() != EOF)
		++nc;
	printf("\n%ld", nc);
}
