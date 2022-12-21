#include <iostream>

using namespace std;

int main(void) {
  int n;

  cin >> n;

  if (n < 2) {
    cout << "Условие гарантированно выполняется!" << endl;
    return 0;
  }

  double **A = new double*[n];

  for (int i = 0; i < n; ++i)
    A[i] = new double[n];

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> A[i][j];
  
  double min = A[0][1], max = A[1][0];

  for (int i = 0; i < n - 1; ++i)
    for (int j = i + 1; j < n; ++j) {
      if (min > A[i][j])
        min = A[i][j];
  
      if (max < A[j][i])
        max = A[j][i];
    }

  if (max <= min) {
    cout << "Условие выполняется!" << endl;
    return 0;
  }

  cout << "Условие не выполняется" << endl;
  return -1;
}
