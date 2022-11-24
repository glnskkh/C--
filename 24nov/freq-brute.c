#include <stdio.h>

// Пусть у нас n голосов и m кандидатов, тогда O(nm)
int consider(int *votes, size_t len) {

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
