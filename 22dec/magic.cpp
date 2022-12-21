#include <iostream>
#include <fstream>

int **createZeroed(int n)
{
  int **A = new int *[n];

  for (int i = 0; i < n; ++i)
  {
    A[i] = new int[n];

    for (int j = 0; j < n; ++j)
      A[i][j] = 0;
  }

  return A;
}

void destroy(int **A, int n)
{
  for (int i = 0; i < n; ++i)
    delete A[i];

  delete[] A;
}

void fillMagic(int **A, int n)
{
  int count = 0, i = 0, j = n / 2;

  while (count++ < n * n)
  {
    if (A[i][j] == 0)
    {
      A[i][j] = count;
      i = (n + i - 1) % n;
      j = (j + 1) % n;
    }
    else
    {
      i = (i + 2) % n;
      j = (n + j - 1) % n;
      count--;
    }
  }
}

int main(int argc, char **argv)
{
  if (argc < 3)
  {
    std::cerr << "Specify file with numbers and for output!" << std::endl;
    exit(EXIT_FAILURE);
  }

  std::ifstream file(argv[1]);
  std::ofstream output(argv[2]);

  while (!file.eof())
  {
    int n;

    file >> n;

    int **A = createZeroed(n);

    fillMagic(A, n);

    output << n << ' ' << n << '\n';

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        output << A[i][j] << ' ';
      }

      output << '\n';
    }

    output << std::endl;

    destroy(A, n);
  }
}
