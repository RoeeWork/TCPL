#include <stdio.h>

 /* Temprature conversion program (same as exercise 3) with a conversion function */

#define LOWER 0.0
#define UPPER 300.0
#define STEP 20.0

float convert_fahr_celsius(float fahr);

int main()
{
	float fahr = LOWER;
	float celsius;

	printf("  ----------------------- \n");
	printf("| Farenheit-Celsius table |\n");
	printf("  -----------------------\n\n");

	while (fahr <= UPPER)
	{
		celsius = convert_fahr_celsius(fahr);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + STEP;
	}
	return 0;
}

float convert_fahr_celsius(float fahr)
{
	float celsius = (5.0 / 9.0) * (fahr - 32.0);

	return celsius;
}

