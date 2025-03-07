#include <stdio.h>

int find_length(char line[]);
void rm_comments(char prog[], char prog_new[]);

int main()
{
	char prog[] = "int main() { /* this is a comment */ return 0; }";
    char prog_new[100]; 

    rm_comments(prog, prog_new);
    printf("Processed Code: %s\n", prog_new);

    return 0;
}

int find_length(char line[])
{
	int i;

	for (i = 0; line[i] != '\0'; ++i)
		;

	return i;
}

void rm_comments(char prog[], char prog_new[])
{
	int i, out_index = 0;
	int len = find_length(prog);
	for (i = 0; i <= len; ++i, ++out_index) {
		if (prog[i] == '/' && prog[i + 1] == '*') {
			i = i + 2;
			while (prog[i] != '*' && prog[i + 1] != '/') {
				++i;
			}
			i = i + 2;
			prog_new[out_index] = prog[i];
		}
		else {
			prog_new[out_index] = prog[i];
		}
		
	}
}

