#include <iostream>
#include <fstream>

using namespace std;

double trace(double **A, int n)
{
  double sum = 0;

  while (--n >= 0)
    sum += A[n][n];

  return sum;
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

  double maxTrace = __DBL_MIN__, **maxMartix = nullptr, maxMartixN = 0, maxMartixM = 0;

  ifstream inputFile("matrix.txt");

  while (!inputFile.eof())
  {
    A = readMatrix(inputFile, n, m);

    if (n != m)
    {
      destroy(A, n);
      continue;
    }

    t = trace(A, n);

    if (t <= maxTrace)
    {
      destroy(A, n);
      continue;
    }

    destroy(maxMartix, maxMartixN);

    maxMartix = A;
    maxTrace = t;
    maxMartixN = n;
    maxMartixM = m;
  }

  ofstream output("max.txt");

  writeMatrix(output, maxMartix, maxMartixN, maxMartixM);
}
