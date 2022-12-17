#include <iostream>

using namespace std;

int main(void)
{
  int n, m;

  cin >> n >> m;

  int **A = new int *[n];

  for (int i = 0; i < n; ++i)
    A[i] = new int[m];

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> A[i][j];

  int maxRow[n], minColumn[m], max, min;

  for (int i = 0; i < n; ++i)
  {
    maxRow[i] = 0;
    max = A[i][0];

    for (int j = 1; j < m; ++j)
    {
      if (A[i][j] > max)
      {
        max = A[i][j];
        maxRow[i] = j;
      }
    }
  }

  for (int j = 0; j < m; ++j)
  {
    minColumn[j] = 0;
    min = A[0][j];

    for (int i = 1; i < n; ++i)
    {
      if (A[i][j] < min)
      {
        min = A[i][j];
        minColumn[j] = i;
      }
    }
  }

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (minColumn[j] == i && maxRow[i] == j) {
        cout << i << " " << j << endl;
        break;
      }
}
