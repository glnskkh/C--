#include <iostream>

using namespace std;

int main(void) {
  int n;

  cin >> n;

  int **A = new int*[n];

  for (int i = 0; i < n; ++i)
    A[i] = new int[n];

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> A[i][j];

  bool valid;
  for (int j = 0; j < n; ++j) {
    int M = A[j][j];
    for (int i = j + 1; i < n; ++i)
      if (A[i][j] > M)
        M = A[i][j];

    valid = true;
    for (int i = 0; i < j; i++)
      if (A[i][j] < M)
        valid = false;

    if (!valid)
      break;
  }

  if (valid)
    cout << "Условие выполняется!" << endl;
  else
    cout << "Условие не выполняется!" << endl;
}