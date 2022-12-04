#include <iostream>

using namespace std;

int **create(int n, int m) {
	int **A = new int*[n];

	for (int i = 0; i < n; ++i)
		A[i] = new int[m];

	return A;
}

void read(int **A, int n, int m) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> A[i][j];
}

void swap(int **A, int i, int j, int I, int J) {
	int t = A[i][j];
	A[i][j] = A[I][J];
	A[I][J] = t;
}

void transpose(int **A, int n) {
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			swap(A, i, j, j, i);
}

int** mul(int **A, int n, int m, int **B, int k, int l, int *x, int *y) {
	if (m != k)
		return NULL;

	int **C = create(n, l);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < l; ++j) {
			int sum = 0;

			for (int h = 0; h < m; ++h) {
				sum += A[i][h] * B[h][j];
			}

			C[i][j] = sum;
		}
	}

	*x = n, *y = l;

	return C;
}

int main(void) {

}