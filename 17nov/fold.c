#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

const char REPLACE = ' ';

int main(void)
{
	int c;
	bool inSpace = false;

	while ((c = getchar()) != EOF) {
		if (isspace(c)) {
			if (!inSpace) {
				putchar(REPLACE);
				inSpace = true;
			}
		} else {
			if (inSpace) {
				inSpace = false;
			}

			putchar(c);
		}
	}
	
	return 0;
}