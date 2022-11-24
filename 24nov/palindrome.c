#include <stdio.h>
#include <string.h>

void applyMask(char *s, int mask) {
	char *i = s;

	while (*s != '\0') {
		if (!(mask & 1))
			*(i++) = *s;

		mask >>= 1;
		++s;
	}

	*(i++) = '\0';
}

int countOnes(long long n) {
	int count = 0;

	while (n > 0) {
		if (n & 1)
			++count;

		n >>= 1;
	}

	return count;
}

long long findLeastMask(char *s, size_t len) {
	if (len <= 1) {
		return 0;
	}

	if (s[0] == s[len - 1])
		return findLeastMask(s + 1, len - 2) << 1;
	else {
		long long m1, m2;

		m1 = (findLeastMask(s + 1, len - 1) << 1) | 1;
		m2 = findLeastMask(s, len - 1) | (1 << (len - 1));

		int c1 = countOnes(m1), c2 = countOnes(m2);

		if (c1 < c2)
			return m1;
		else
			return m2;
	}
}

int main(int argc, char **argv)
{
	while (--argc > 0) {
		++argv;

		applyMask(*argv, findLeastMask(*argv, strlen(*argv)));

		printf("%s\n", *argv);
	}
}