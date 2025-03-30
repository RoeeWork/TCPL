#include <stdio.h>
#include <stdlib.h>

int main()
{
	char s[] = { '1' , '2' , '3' , '\0' };
	printf("%f", atof(s));
	return 0;
}
