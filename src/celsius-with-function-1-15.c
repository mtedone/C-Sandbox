#include <stdio.h>

#define LOWER 		0
#define UPPER		300
#define STEP		20

float calculateCelsiusFromFahr(float fahr);

int main()
{
	float fahr, celsius;

	fahr = LOWER;

	while (fahr <= UPPER)
	{
		celsius = calculateCelsiusFromFahr(fahr);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr += STEP;
	}

	return 0;
}

/**
 * It returns the Celsius value in floating point notation for a given Fahrenheit value
 * @param fahr The Fahrenheit value to convert into Celsius
 */
float calculateCelsiusFromFahr(float fahr)
{
	return (5.0 / 9.0) * (fahr - 32.0);

}
