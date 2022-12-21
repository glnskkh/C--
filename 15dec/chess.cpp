#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
  int n, **A;

  cin >> n;

  A = new int*[n];

  ofstream output("chess.txt");

  for (int i = 0; i < n; ++i)
    A[i] = new int[n];

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      A[i][j] = (i + j + n + 1) % 2;

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
      output << A[i][j] << "\t";

    output << endl;
  }

  output.close();
}
