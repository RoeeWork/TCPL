#include <stdio.h>
#include "exercise_05_02.c"

int main() {
	float num, val;

	val = getfloat(&num);
	printf("number = %f\n", num);
	if (val == 0) {
		printf("not a number!\n");
	}
	else if (val > 0) {
		printf("number!\n");
	}
	printf("number = %f\n", num);
	printf("value = %f\n", val);
	return 0;
}
