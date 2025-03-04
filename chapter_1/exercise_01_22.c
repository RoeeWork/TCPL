#include <stdio.h>
#define MAXLINE 1000
int fold_limit;
int fold_getline(int line[]);

int main()
{
	
}

int fold_getline(char line[])
{
	int i, c;
	int col_count = 1;
	extern int fold_limit;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i, ++col_count) {
		if (col_count == fold_limit) {
			col_count = 0;
			line[i] = '\n';
			++i;
		} 
		line[i] = c;
	}
}
