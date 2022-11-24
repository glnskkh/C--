#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int generatePalindromes(char *s, size_t len) {
	if (len == 0)
		return;

	if (len == 1) {
		printf("%c,", s[0]);

		return;
	}

	if (s[0] == s[len - 1]) {
		printf("%c", s[0]);

		if (len != 2) {
			puts("{");
			generatePalindromes(s + 1, len - 2);
			puts("{");
		}

		printf("%c", s[0]);
	}

	if () {
		printf("%c{", s[0]);
			generatePalindromes(s + 1, len - 2);

		printf("}%c", s[0]);
	}	else {
		generatePalindromes(s + 1, len);
		generatePalindromes(s + 1, len - 1);
	}
}

int main(int argc, char **argv)
{
	while (--argc > 0) {
		++argv;

		printf("{");
		generatePalindromes(*argv, strlen(*argv));
		printf("}\n");
	}
}