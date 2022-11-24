#include <stdio.h>
#include <stdlib.h>

// Пусть n число голосов, m число кандидатов, тогда O(n)
int consider(int *votes, size_t len) {
	int i = 0, count = 0, candidate;

	while (i < len) {
		if (count <= 0)
			candidate = votes[i];

		count += votes[i] == candidate ? 1 : -1;

		++i;
	}

	return candidate;
}

int main(void) {
	size_t len;
	int *votes, i;

	scanf("%lu", &len);

	votes = malloc(len * sizeof(int));

	for	(i = 0; i < len; ++i)
		scanf("%d", votes + i);

	printf("%d\n", consider(votes, len));
}
