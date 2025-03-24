#include <stdio.h>
#define MAXLINE 1000
int escape(char string[], char to[]);
int r_escape(char string[], char to[]);

int main() 
{
	char s[MAXLINE] = {'h', 'e', 'y', '\\', 'n', '\0'};
	char t[MAXLINE];
	int num = r_escape(s, t);
	printf("\n%s\n", t);
	printf("%d", num);
	return 0;
}

int escape(char s[], char t[])
{
	int c;
	int i;
	int j = 0;
	for (i = 0; (c = s[i]) != '\0'; ++i, ++j) {
		printf("%c\n", c);
		printf("%d\n", i);
		printf("%d\n", j);
		switch (c) {
			case '\n':
				t[j] = '\\';
				t[j + 1] = 'n';
				j += 2;
				break;
			case '\t':
				t[j] = '\\';
				t[j + 1] = 't';
				j += 2;
				break;
			default:
				t[j] = s[i];
				break;
			
		}
	}
	return j - i - 1;
}

int r_escape(char s[], char t[])
{
	int i;
	int j = 0;
	for (i = 0; s[i] != '\0'; ++i, ++j) {
	
		printf("%c\n", s[i]);
		
		switch (s[i]) {
			case '\\':
				switch(s[++i]) {
					case 't':
						t[j] = '\t';
						break;
						
					case 'n':
						t[j] = '\n';
						printf("t[j] = %c", t[j]);
						break;
				}
				break;
			default:
				t[j] = s[i];
				break;
		}
	}
	
	if (s[i] == '\0') {
		t[j] = s[i];
	}
	return i - j;
}
