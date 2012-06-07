/*
 * limits-2-1.c
 *
 *  Created on: Jun 7, 2012
 *      Author: tedonema
 */
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	printf("Signed Char min: %d, Signed Char max: %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("Unsigned Char min: %d, Unsigned Char max: %d\n", 0, UCHAR_MAX);
	return 0;
}

