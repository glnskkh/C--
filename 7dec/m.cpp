#include <iostream>

using namespace std;

int main(void) {
  int n, m;

  cin >> n >> m;

  for (int i = 0; i < n; ++i)
    A[i] = new int[m];

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> A[i][j];

  int maxRow[n], minColumn[m];

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)

}