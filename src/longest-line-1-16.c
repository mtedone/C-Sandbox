#include <stdio.h>

#define MAXLINE 100

int getLine(char line[], int maxLine);
void copy(char longest[], char line[]);

int main()
{
	int len;
	int max;

	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;


	while ((len = getLine(line, MAXLINE)) > 0)
	{
		if (len > max){

			if (len > MAXLINE)
				printf("Actual line length: %d, MAX LENGTH = %d \n\n", len, MAXLINE);
			max = len;
			copy(longest, line);
		}
	}

	if (max > 0)
		printf("%s\n\n", longest);
	return 0;
}

int getLine(char line[], int maxLine)
{
	int c, i;

	for (i = 0; i < maxLine - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n') /* Found EOF before MAXLINE */
	{
		line[i] = c;
		++i;
		line[i] = '\0';
	} else { /* Counts total length after MAXLINE */

		while ((c = getchar()) != EOF && c != '\n')
			++i;
		line[MAXLINE - 1] = '\0';
	}

	return i;

}

void copy(char longest[], char line[])
{
	int i;

	i = 0;

	while ((longest[i] = line[i]) != '\0')
		++i;
}
