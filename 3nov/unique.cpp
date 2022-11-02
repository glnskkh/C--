#include <iostream>

using namespace std;

void swap(int *a, int *b) {
  int t;

  t = *a, *a = *b, *b = t;
}

void copy(int *D, int *S, int n) {
  while ((n--) > 0)
    *(D++) = *(S++);
}

void merge(int *A, int n, int *B, int m) {
  int i = 0, j = 0, k = 0;

  int *C = (int *)malloc((n + m) * sizeof(int));

  while (k != n + m) {
    if (i < m && A[i] < B[j]) {
      C[k++] = A[i++];
    } else {
      C[k++] = B[j++];
    }
  }

  copy(A, C, n + m);
}

void sort(int *A, int n) {
  if (n == 1)
    return;

  sort(A, (n / 2));
  sort(A + (n / 2), n - (n / 2));

  merge(A, (n / 2), A + (n / 2), n - (n / 2));
}

int main() {
  int n, i;

  cin >> n;

  int A[n];

  for (i = 0; i < n; ++i)
    cin >> A[i];

  sort(A, n);

  for (i = 0; i < n - 1; ++i)
    if (A[i] == A[i + 1]) {
      cout << "Повтор";
      return -1;
    }

  cout << "Без повторов";
}