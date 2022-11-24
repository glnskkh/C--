#include <stdio.h>
#include <stdlib.h>

char itoc(int a, int b) {
	if (a < 10)
		return a + '0';

	if (a < 10 + 26)
		return a - 10 + 'a';
}

int convert(int n, int p, char* output) {
	if (n == 0) {
		*output = '\0';
		return 0;
	}

	*output = itoc(n % p, p);

	return 1 + convert(n / p, p, output + 1);
}

void reverse(char *s, int len) {
	int i = 0;
	char t;

	while (i < len / 2) {
		t = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = t;

		++i;
	}
}

int main(void) {
	int n, p;

	scanf("%d %d", &n, &p);

	if (p < 2 || p > 10 + 26) {
		fprintf(stderr, "%s\n", "Такое основание не представимо данной программой!");
		exit(EXIT_FAILURE);
	}

	char output[100];

	int len = convert(n, p, output);
	reverse(output, len);

	printf("%s\n", output);

	exit(EXIT_SUCCESS);
}