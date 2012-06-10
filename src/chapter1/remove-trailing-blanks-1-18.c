#include <stdio.h>

#define MAXLINE  			1000
#define IS_BLANK_LINE		1
#define IS_NOT_BLANK_LINE	0

/** Fills the sink with a line and returns the non-blank characters read */
int getLine(char sink[]);

/** Returns 1 if the line contains all blank chars, 0 otherwise */
int isBlankLine(char source[]);

/** Copies a source string into the target */
void createTrailedLine(char source[], char target[]);

int main() {

	int read;

	char source[MAXLINE];

	char target[MAXLINE];

	while ((read = getLine(source)) > 0) {

		//Got a line. Now checks if it's all blanks
		if ((read = isBlankLine(source)) == IS_NOT_BLANK_LINE)
		{
			createTrailedLine(source, target);
			printf("Trailed line: [%s]\n", target);
		} else {
			printf("Skipped blank line: [%s]\n", source);
		}
	}

	return 0;
}

int getLine(char sink[]) {

	int i, c, inWord;

	inWord = 0;

	for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		sink[i] = c;

	//It closes the array with the null character
	sink[i] = '\0';

	return i;

}

int isBlankLine(char source[])
{
	int i, retValue;

	retValue = IS_BLANK_LINE;

	for (i = 0; source[i] != '\0'; ++i)
	{
		if (source[i] != ' ' && source[i] != '\t')
			return IS_NOT_BLANK_LINE;
	}

	return retValue;

}

void createTrailedLine(char source[], char target[]) {

	int i, j, c, inWord;

	inWord = j = 0;

	//Removes spaces at the beginning
	for (i = 0; source[i] != '\0'; ++i)
	{
		if (source[i] != ' ' && source[i] != '\t')
		{
			inWord = 1;
			target[j] = source[i];
			++j;

		}
		else
		{
			//It's a blank
			if (inWord > 0)
			{
				target[j] = source[i];
				++j;
			}

		}
	}

	--j;

	//Now removes the ending blanks
	while (target[j] == ' ' || target[j] == '\t')
		--j;

	target[++j] = '\0';

}

