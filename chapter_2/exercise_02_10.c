#include <stdio.h>
int lower(char c);


int main() 
{
	printf("%c\n", lower('A')); 
	return 0;
}

int lower(char character)
{
	int lim = 'a' - 'A';
	return (character >= 'A' && character <= 'Z') ? (character + lim ) : -1;
}
