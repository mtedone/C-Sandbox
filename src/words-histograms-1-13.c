/*
 * Far-Cel.c
 *
 *  Created on: 1 May 2012
 *      Author: tedonema
 */
#include <stdio.h>

#define MAX_WORD_LENGTH 30
#define OUT 0
#define IN 1

int main(void)
{
	int length, c, i, j, status;

	int wordsLength[MAX_WORD_LENGTH];

	length = c = 0;

	status = OUT;

	for (i = 0 ; i < MAX_WORD_LENGTH; ++i)
	{
		wordsLength[i] = 0;
	}

	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\n' || c == '\t')
		{
			if (status == IN)
			{
				status = OUT;
				wordsLength[length] = wordsLength[length] + 1;
				length = 0;
				printf("\n");
			}


		} else {
			status = IN;
			++length;
			printf("%c",c);
		}
	}

	for (i = 0; i < MAX_WORD_LENGTH; ++i)
	{
		printf("Length: %d = ", i);
		for (j = 0; j < wordsLength[i]; ++j)
		{
			printf("+");
		}
		printf("\n");
	}


	return 0;

}

