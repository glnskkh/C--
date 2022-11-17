#include <iostream>

using namespace std;

int min(int a, int b) { return a < b ? a : b; }

int main(void) {
  int l, m;

  cin >> l;

  double L[l];

  for (int i = 0; i < l; ++i)
    cin >> L[i];

  cin >> m;

  double M[m];

  for (int i = 0; i < m; ++i)
    cin >> M[i];

  int a, b;
  double *A, *B;
  if (l > m) {
    a = l, A = L;
    b = m, B = M;
  } else {
    a = m, A = M;
    b = l, B = L;
  }

  for (int i = 0; i < a; ++i) {
    if (i < b)
      cout << A[i] + B[i] << " ";
    else
      cout << A[i] << " ";
  }

  cout << endl;

  double t;
  for (int i = 0; i < a + b - 1; ++i) {
    t = 0;

    l = min(i, a - 1), m = min(i - l, b - 1);
    while (m <= min(i, b - 1))
      t += A[l--] * B[m++];

    cout << t << " ";
  }

  cout << endl;
}