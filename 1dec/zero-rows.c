#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, m;

	scanf("%d %d", &n, &m);

	double *A = malloc(sizeof(double) * n * m);

	int i, j, count = 0;

	for (i = 0; i < n * m; ++i)
		scanf("%lf", A + i);

	for (i = 0; i < n; ++i) {
		for (j = 0; j < m && A[i * n + j] == 0; ++j);

		if (j == m)
			++count;
	}

	printf("%d\n", count);
}
