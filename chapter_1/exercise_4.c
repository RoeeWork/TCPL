#include <stdio.h>

	/* Uses F = (C * 9/5) + 32 formula */

main()
{
	float cel, fahr;
	float lower, upper, step;

	lower = 0.0;
	upper = 300.0;
	step = 20.0;

	cel = lower;
	while(cel <= upper){
		fahr = (cel*9/5) + 32;
		printf("%3.0f %6.1f\n", cel, fahr);
		cel += step;
	}
}
