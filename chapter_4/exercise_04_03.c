#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUMBER '0'
#define MAXOP 100
#define MAXSTACK 100
#define BUFFER 100

void push(double c); /* push to stack */
double pop(void); 	 /* pop current element */
int getop(char s[]); /* get operator */
int getch(void);	 /* getchar() that outputs buffer's content before getting input */
void ungetch(int c); /* outputs to buffer */

float stack[100];
int stackp = 0;
char buf[BUFFER];
int bufp = 0;

int main()
{
	int type;
	double op;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER :
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				push(pop() - pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				push(pop() / pop());
				break;
			/*case '%':
				push(pop() % pop());
				break;*/
			case '\n':
				printf("\n\t%f\n", pop());
				break;
			default:
				printf("ERROR: unkown command %s\n", s);
				break;
		}
	}
	return 0;
}

void push(double f)
{
	if (stackp < MAXSTACK) {
		stack[stackp++] = f;
	}
	else {
		printf("ERROR: cannot push, stack full.");
	}
}

double pop(void)
{
	if (stackp > 0) {
		return stack[--stackp];
	}
	else {
		printf("ERROR: cannot pop, stack empty.");
		return 0.0;
	}
}

int getop(char s[]) 
{
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;

	s[1] = '\0';
	if (!isdigit(c) && c != '.') {
		return c; /* not a number */ 
	}
	i = 0;
	if (isdigit(c)) {
		while (isdigit(s[++i] = c = getch()));
	}
	if (c == '.') {
		while (isdigit(s[++i] = c = getch()));
	}
	s[i] = '\0';
	if (c != EOF) {
		ungetch(c);
	}
	return NUMBER;
}


int getch(void)
{
	if (bufp > 0) {
		return buf[--bufp]; 
	}
	return getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFFER) 
		printf("ungetch: full buffer, too many characters");
	else 
		buf[bufp++] = c;
}
