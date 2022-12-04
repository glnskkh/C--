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

  int sum = 0;
  for (int i = 0; i < n; ++i)
    sum += A[i][i];

  int t = 0;
  for (int i = 0; i < n; ++i)
    t += A[n - 1 - i][n - 1 - i];

  if (t != sum) {
    cout << "Не магический!" << endl;
    return -1;
  }

  int t1, t2;
  for (int i = 0; i < n; ++i) {
    t1 = t2 = 0;

    for (int j = 0; j < n; ++j)
      t1 += A[i][j], t2 += A[j][i];

    if (!(t1 == sum && t2 == sum)) {
      cout << "Не магический!"  << endl;
      return -1;
    }
  }

  cout << "Магический!" << endl;

  return 0;
}