/*
 * Far-Cel.c
 *
 *  Created on: 1 May 2012
 *      Author: tedonema
 */
#include <stdio.h>

#define MAX_NUM_LETTERS 26
#define OUT 0
#define IN 1

int main(void)
{
	int length, c, i, j, status;

	int charFrequency[MAX_NUM_LETTERS];

	length = c = 0;

	int alphabet[MAX_NUM_LETTERS] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
			'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
			'r', 's', 't', 'u', 'v', 'w', 'z', 'y', 'z'};


	status = OUT;

	//Initialisation
	for (i = 0 ; i < MAX_NUM_LETTERS; ++i)
	{
		charFrequency[i] = 0;
	}

	while ((c = getchar()) != EOF)
	{
		if (c != ' ' && c != '\n' && c != '\t')
		{
			for (i = 0; i < MAX_NUM_LETTERS; i++)
			{
				if (c == alphabet[i]) {
					charFrequency[i] = charFrequency[i] + 1;
 				}
			}
		}

	}

	for (i = 0; i < MAX_NUM_LETTERS; ++i)
	{
		printf("Char: %c, frequency: \t ", alphabet[i]);
		for (j = 0; j < charFrequency[i]; ++j)
		{
			printf("+");
		}
		printf("\n\n");

	}


	return 0;

}

