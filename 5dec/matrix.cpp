#include <iostream>
#include <fstream>

using namespace std;

int **createMatrix(int n, int m)
{
  int **A = new int *[n];

  for (int i = 0; i < n; ++i)
    A[i] = new int[m];

  return A;
}

bool zeroed(int **A, int n)
{
  for (int i = 0; i < n; ++i)
    if (A[i][i] != 0)
      return false;

  return true;
}

void destroyMatrix(int **A, int n, int m)
{
  for (int i = 0; i < n; ++i)
    delete[] A[i];

  delete[] A;
}

void readMatrix(ifstream &file, int ***A, int &n, int &m)
{
  file >> n >> m;

  *A = createMatrix(n, m);

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      file >> (*A)[i][j];
}

void writeMatrix(ofstream &file, int **A, int n, int m)
{
  file << n << " " << m << endl;

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
      file << A[i][j] << " ";

    file << endl;
  }
}

int main(void)
{
  ifstream input("matrix.txt");
  ofstream out("output.txt");

  int n, m, **A;

  while (!input.eof())
  {
    readMatrix(input, &A, n, m);

    if (n == m && zeroed(A, n))
      writeMatrix(out, A, n, m);

    destroyMatrix(A, n, m);
  }

  input.close();
  out.close();
}
