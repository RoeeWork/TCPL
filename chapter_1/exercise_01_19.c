#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[]);
void reverse(char s[]);
int get_last_index(char line[]);

int main() 
{
	char line[MAXLINE];
	my_getline(line);
	reverse(line);
	printf("\n%s\n", line);
	return 0;
}

int my_getline(char line[]) 
{
	int i;
	int character;

	for (i = 0; ((character = getchar()) != EOF) && character != '\n'; ++i) {
		line[i] = character;
	}

	if (character == '\n') {
		line[i] = character;
		++i;
	}

	line[i] = '\0';

	return i; /* returns last index */
}

int get_last_index(char line[])
{
	int i = 0; 

	while (line[i] != '\0') {
		++i;
	}

	return i;
	
	
}

void reverse(char s[])
{
	int i;
	int last_index = get_last_index(s) - 1; /* -1 to skip over null terminator */
	int opp_index;
	char char_curr, char_opp;
	for (i = last_index; i > last_index / 2; --i) {
		opp_index = last_index - i;
		char_curr = s[i];
		char_opp = s[opp_index];
		
		s[i] = char_opp;
		s[opp_index] = char_curr;
	}
	
}
