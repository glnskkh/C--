#include <iostream>

using namespace std;

int **create(int n, int m)
{
  int **A = new int*[n];

  for (int i = 0; i < n; ++i)
    A[i] = new int[m];

  return A;
}

void read(int **A, int n, int m)
{
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> A[i][j];
}

void destroy(int **A, int n, int m)
{
  for (int i = 0; i < n; ++i)
    delete[] A[i];

  delete[] A;
}

int main(void) 
{
  int n, m, **A;
  bool max, min;

  cin >> n >> m;

  A = create(n, m);

  read(A, n, m);

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      max = true;
      
      for (int k = 0; k < m; ++k)
        if (A[i][j] < A[i][k]) 
        {
          max = false;
          break;
        }

      if (!max) continue;

      min = true;

      for (int k = 0; k < n; ++k)
        if (A[i][j] > A[k][j])
        {
          min = false;
          break;
        }

      if (min && max)
        cout << i << " " << j << endl;
    }
  }

  destroy(A, n, m);
}
