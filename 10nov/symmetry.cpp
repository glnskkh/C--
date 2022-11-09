#include <iostream>

using namespace std;

bool areSymmetrical(int a, int b) {
  int pow10 = 1;

  while (!(pow10 > b))
    pow10 *= 10;

  pow10 /= 10;

  while (a > 0) {
    if (a % 10 != (b / pow10) % 10)
      return false;

    a /= 10;
    pow10 /= 10;
  }

  return true;
}

int main(void) {
  int n;

  cout << "Введите длину массивов чисел: ";

  cin >> n;

  cout << "Введите массивы A и B: ";

  int A[n], B[n];

  for (int i = 0; i < n; ++i)
    cin >> A[i];

  for (int i = 0; i < n; ++i)
    cin >> B[i];

  for (int i = 0; i < n; ++i)
    if (!areSymmetrical(A[i], B[n - i - 1])) {
      cerr << "Несимметричные!";
      exit(EXIT_FAILURE);
    }

  cout << "Cимметричные!" << endl;
  exit(EXIT_SUCCESS);
}