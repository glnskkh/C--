#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int count;
	int candidate;
} Pair;

int count(int *A, size_t len, int value) {
	int r = 0;

	while (len-- > 0)
		if (*(A++) == value)
			++r;

	return r;
}

// Пусть у нас n голосов и m кандидатов, тогда O(nlogm)
Pair* consider(int *votes, size_t len) {
	if (len == 0)
		return NULL;

	if (len == 1) {
		Pair *pp = (Pair *)malloc(sizeof(Pair));

		pp->candidate = *votes;
		pp->count = 1;

		return pp;
	}

	Pair *r = consider(votes, len / 2);
	Pair *l = consider(votes + len / 2, (len - len / 2));

	r->count += count(votes + len / 2, (len - len / 2), r->candidate);
	l->count += count(votes, len / 2, l->candidate);

	if (r->count < l->count) {
		free(r);
		return l;
	} else {
		free(l);
		return r;
	}
}

int main(void) {
	size_t len;
	int *votes, i;

	scanf("%lu", &len);

	votes = malloc(len * sizeof(int));

	for	(i = 0; i < len; ++i)
		scanf("%d", votes + i);

	printf("%d\n", consider(votes, len)->candidate);
}