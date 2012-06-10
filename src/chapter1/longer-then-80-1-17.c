#include <stdio.h>

#define MAX_LENGTH 		4
#define MAXLINE  		1000

/** Fills the sink with a line and returns the characters read */
int getLine(char sink[]);

/** Copies a source string into the target */
void copy(char source[], char target[]);

int main() {

	int length;

	char source[MAXLINE];

	char target[MAXLINE];

	while ((length = getLine(source)) > 0) {
		if (length > MAX_LENGTH) {
			copy(source, target);
			printf("Line over %d chars: %s\n", MAX_LENGTH, target);
		}
	}

	return 0;
}

int getLine(char sink[]) {

	int i, c;

	for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		sink[i] = c;

	//It closes the array with the null character
	sink[++i] = '\0';

	return --i;

}

void copy(char source[], char target[]) {

	int i, c;

	i = 0;

	while ((target[i] = source[i]) != '\0')
		++i;

}

