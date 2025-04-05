#include <stdio.h>

/* rudimentary memory allocator */
/*  alloc(n) -> returns a pointer p
 *  			to n consecutive
 *  			character positions.
 *
 *  afree(p) -> releases the storage
 *  			aquired by alloc(n).
 */

char *alloc(int bytes);
void afree(char *p);

#define MAXALLOC 1000

char alloc_buffer[MAXALLOC];
char *alloc_pointer = &alloc_buffer[0];

char *alloc(int n)
{
	if (&alloc_buffer[0] + MAXALLOC - alloc_pointer >= n) {
		alloc_pointer += n;
		return alloc_pointer - n;
	}
	printf("alloc: memory full");
	return 0;
}

void afree(char *p)
{
	if (alloc_pointer == &alloc_buffer[0]) {
		printf("afree: empty buffer");
	}
	else if (alloc_pointer < p) {
		printf("afree: invalid pointer");
	}
	else if (p > alloc_buffer + MAXALLOC) {
		printf("afree: pointer out of range");
	}
	else {
		alloc_pointer = p;
	}
}
