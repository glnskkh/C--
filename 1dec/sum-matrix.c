#include <stdio.h>

int main(void) {
	int n, m;

	scanf("%d %d", &n, &m);

	double A[n * m], B[n * m];

	for (int i = 0; i < n * m; ++i)
		scanf("%lf", A + i);

	for (int i = 0; i < n * m; ++i)
		scanf("%lf", B + i);

	for (int i = 0; i < n * m; ++i) {
		printf("%lf\t", A[i] + B[i]);

		if (i % m == m - 1)
			printf("\n");
	}
}
