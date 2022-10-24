#include <iostream>

using namespace std;

#define MAX_LEN 100

size_t readArr(double *array) {
  size_t len;

  cout << "Введите число элементов: ";
  cin >> len;

  cout << "Введите " << len << " элементов: ";

  size_t i = 0;
  while (i < len && i < MAX_LEN)
    cin >> array[i++];

  return i;
}

int main() {
  double X[MAX_LEN], Y[MAX_LEN];

  size_t lenX = readArr(X);
  size_t lenY = readArr(Y);

  if (lenX == 0 && lenY == 0) {
    cerr << "Массивы пусты";
    return -1;
  }

  double a;

  cout << "Введите число a: ";
  cin >> a;

  int i = 0, j = 0;
  double M = abs(X[i] + Y[j] - a), Mi = i, Mj = j;
  double dX = abs(X[i + 1] + Y[j] - a), dY = abs(X[i] + Y[j + 1] - a);

  while (dX < M || dY < M) {
    if (dX < M)
      M = dX, Mi = i + 1, Mj = j;
    if (dY < M)
      M = dY, Mi = i, Mj = j + 1;

    i = Mi, j = Mj;

    if (i + 1 < lenX)
      dX = abs((X[i + 1] + Y[j]) - a);

    if (j + 1 < lenY)
      dY = abs((X[i] + Y[j + 1]) - a);
  }

  cout << "Минимальная i: " << Mi << endl;
  cout << "Минимальная j: " << Mj << endl;
  cout << "Минимальная разница с a: " << M << endl;
}