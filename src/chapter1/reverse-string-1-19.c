#include <stdio.h>

#define MAXLINE  			1000
#define IS_BLANK_LINE		1
#define IS_NOT_BLANK_LINE	0

/** Fills the sink with a line and returns the non-blank characters read */
int getLine(char sink[]);

void reverse(int length, char source[], char target[]);


int main() {

	int read;

	char source[MAXLINE];

	char target[MAXLINE];

	while ((read = getLine(source)) > 0) {

		//Got a line. Now reverse it
		reverse(read - 1, source, target);
		printf("Reversed line: %s\n", target);
	}

	return 0;
}

int getLine(char sink[]) {

	int i, c, inWord;

	inWord = 0;

	for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		sink[i] = c;

	if (c == '\n')
	{
		sink[i] = c;
		++i;
	}

	//It closes the array with the null character
	sink[i] = '\0';

	if (c == EOF) i = -1;

	return i;

}

/*
 * length: length of source
 * source: the line to be reversed
 * target: the sink where the line gets reversed
 */
void reverse(int length, char source[], char target[])
{


	int i, j;

	i = 0;

	for (j = length; j >= 0; --j)
	{
		target[i] = source[j];

		i++;
	}

	target[++length] = '\0';

}


