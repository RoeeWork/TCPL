#include <stdio.h>
#include <limits.h>

int main()
{
	printf("-------------------CHARS------------------\n");
	printf("unsigned char: (%d) - %d\n", 0, UCHAR_MAX);
	printf("signed char: (%d) - %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("\n");
	printf("-------------------INTS--------------------\n");
	printf("unsigned int: %d - %u\n", 0, UINT_MAX);
	printf("signed int: (%d) - %d\n", INT_MIN, INT_MAX);
	printf("\n");
	printf("-------------------SHORTS----------------\n");
	printf("unsigned short: %d - %d\n", 0, USHRT_MAX);
	printf("signed short: (%d) - %d\n", SHRT_MIN, SHRT_MAX);
	printf("\n");
	printf("-------------------LONGS-----------------\n");
	printf("unsinged long: %d - %lu\n", 0, ULONG_MAX);
	printf("signed long: (%ld) - %ld\n", LONG_MIN, LONG_MAX);
	printf("\n");

	return 0;

}
