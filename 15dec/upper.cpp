#include <iostream>
#include <fstream>

using namespace std;

bool isUpper(double **A, int n)
{
  double sum = 0;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < i; ++j)
      if (A[i][j] != 0)
        return false;

  return true;
}

double **create(int n, int m)
{
  double **A = new double *[n];

  while (--n >= 0)
    A[n] = new double[m];

  return A;
}

void destroy(double **A, int n)
{
  for (int i = 0; i < n; ++i)
    delete[] A[i];

  delete[] A;
}

double **readMatrix(ifstream &file, int &n, int &m)
{
  file >> n >> m;

  double **A = create(n, m);

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      file >> A[i][j];

  return A;
}

void writeMatrix(ofstream &file, double **A, int n, int m) {
  if (!(n > 0 && m > 0))
    return;

  file << n << " " << m << endl;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      file << A[i][j] << "\t";

    file << endl;
  }
}

int main(void)
{
  int n, m;
  double **A, t;

  double maxN = __DBL_MIN__, **maxMartix = nullptr, maxMartixN = 0;

  ifstream inputFile("matrix.txt");

  while (!inputFile.eof())
  {
    A = readMatrix(inputFile, n, m);

    if (n != m || !isUpper(A, n) || !(n > maxMartixN))
    {
      destroy(A, n);
      continue;
    }

    destroy(maxMartix, maxMartixN);

    maxMartix = A;
    maxMartixN = n;
  }

  ofstream output("max.txt");

  writeMatrix(output, maxMartix, maxMartixN, maxMartixN);
}
