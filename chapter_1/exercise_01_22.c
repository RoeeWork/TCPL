#include <stdio.h>
#define MAXLINE 1000
int fold_limit = 10;
int fold_getline(char line[]);
int find_space(char line[], int index);

int main()
{
	char line[MAXLINE];
	fold_getline(line);

	printf("\n%s", line);
	return 0;
}

int find_space(char line[], int index)
{
	int i;
	int blank_count = 0;
	for (i = index; i >= 0 && line[i] == ' '; --i) 
		++blank_count;
	return blank_count;
}
int fold_getline(char line[])
{
	int i, c;
	int col_count = 1;
	int blank_count;
	extern int fold_limit;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
	
		if (col_count >= fold_limit && c != ' ' ) {
			int j = i;
			blank_count = find_space(line, i - 1);
			while (line[j] != ' ') {
			line[j + 1] = line[j];
			--j;
			}
			
			while (blank_count > 1) {
				line[j + 1] = line[j];
				--j;
				--blank_count;
			}
			line[j + 1] = line[j];
			
			col_count = 0;
			line[j] = '\n';
			++i;
			blank_count = 0;
		}
		

		else { 
			++col_count;
		}
		line[i] = c;
	}
	if ( c == '\n' ) {
		line[i] = '\n';
		++i;
	}
	line[i] = '\0';
	return i;
}	
