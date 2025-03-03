#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int lenght);
void rm_trailing_blanks(char line[], int lenght);

int main() {
	int c;
	char line[MAXLINE];
	c = get_line(line, MAXLINE);
	rm_trailing_blanks(line, c);

	return 0;
}
int get_line(char line[], int lenght) {
	int c, i;
	for (i = 0; (c = getchar()) != EOF && i < lenght && c != '\n'; ++i) {
		line[i] = c;
	}
	if (c == '\n') {
		line[i] = c; 
		++i;
	}
	line[i] = '\0';
	return i; 
}	
/* TODO: remove single newlines */
void rm_trailing_blanks(char line[], int lenght) {
	int newline = 0, i = lenght, whitespace_len = 0 ;
	/* iterate through the string, decrement i by 1 if the string is a whitespace,
		except for newlines and whitespaces */

	while (line[i] == ' ' 
			|| line[i] == '\t'
			|| line[i] == '\n'
			|| line[i] == '\0') {
		if (line[i] == '\n') {
			++newline; /* amount of newlines in the string, added to lenght later */
			++whitespace_len;
		}
		if (line[i] == '\0' ) { ++whitespace_len; }
		
		--i;
	}
	/* lenght of the new string */
	int new_length = i + 1 + newline + whitespace_len;
	char temp_line[new_length];

	i = new_length - 1;
	temp_line[i] = '\0';
	i = i - 1;
	if(newline > 0) {
		temp_line[i] = '\n';
		--i;
	}
	/* copies the rest of line[] into line_temp[] */
	while (i >= 0) {
		temp_line[i] = line[i];
		--i;
	}
	printf("%s\n", temp_line);
}
