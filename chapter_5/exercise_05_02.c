#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);
int getint(int*);
int getfloat(float*);


int getfloat(float *pn)
{
	int c, sign;
	float val_orig = *pn;
	while (isspace(c = getch()))
		;

	while (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}

	sign = (c == '-') ? -1 : 1 ;
	
	if (c == '+' || c == '-'){
		if (!isdigit(c = getch())) { 
			ungetch(c);
			return 0;
		}
	}

	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	
	if (c == '.') {
		c = getch();
		if (!isdigit(c = getch())) { 
			ungetch(c);
			*pn = val_orig;
			return 0;
		}
		for (; isdigit(c); c = getch()) {
			*pn = (10 * *pn + (c - '0')) * 0.1;
		}
	}
	*pn *= sign;
	
	if (c != EOF)
		ungetch(c);

	return c; 

}

int getint(int *pn)
{
	int c, sign;
	while (isspace(c = getch()))
		;

	while (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}

	sign = (c == '-') ? -1 : 1;
	
	if (c == '+' || c == '-') {
		if (!isdigit(c = getch())) { 
			ungetch(c);
			return 0;
		}
	}

	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');

	*pn *= sign;
	
	if (c != EOF)
		ungetch(c);

	return c; 

}

int getch(void) 
{
	if (bufp > 0) {
		return buf[--bufp];
	}
	else {
		return getchar();
	}
}

void ungetch(int c) 
{
	if (bufp >= BUFSIZE) {
		printf("ungetch: too many characters\n");
	}
	else {
		buf[bufp++] = c;
	}
}
