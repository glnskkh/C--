#include <iostream>

using namespace std;

#define MAX_LEN 100

size_t readArr(double *array)
{
  size_t len;

  cout << "Введите число элементов: ";
  cin >> len;

  cout << "Введите " << len << " элементов: ";

  size_t i = 0;
  while (i < len && i < MAX_LEN)
    cin >> array[i++];

  return i;
}

int main()
{
  double X[MAX_LEN], Y[MAX_LEN];

  size_t lenX = readArr(X);
  size_t lenY = readArr(Y);

  if (lenX == 0 && lenY == 0)
  {
    cerr << "Массивы пусты";
    return -1;
  }

  double a;

  cout << "Введите число a: ";
  cin >> a;

  int i = 0, j = lenY - 1;
  double M = abs(X[i] + Y[j] - a), Mi = i, Mj = j;

  while (i < lenX && M != 0 && j >= 0)
  {
    while (X[i] + Y[j] > a)
    {
      --j;
      if (!(j >= 0))
        break;

      if (abs(X[i] + Y[j] - a) < M)
        M = abs(X[i] + Y[j] - a), Mi = i, Mj = j;
    }

    if (!(j >= 0))
      break;

    if (X[i] + Y[j] == a)
    {
      M = 0, Mi = i, Mj = j;
      break;
    }

    while (X[i] + Y[j] < a)
    {
      i++;
      if (!(i < lenX))
        break;

      if (abs(X[i] + Y[j] - a) < M)
        M = abs(X[i] + Y[j] - a),
        Mi = i, Mj = j;
    }

    if (!(i < lenX))
      break;
  }

  cout << "Минимальная i: " << Mi << endl;
  cout << "Минимальная j: " << Mj << endl;
  cout << "Минимальная разница с a: " << M << endl;
}