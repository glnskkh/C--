#include <iostream>

using namespace std;

#define LEN 3
#define MIN_INT32 (INT32_MAX + 1)

int main() {
  int n, i, j, max, value, maxArray[LEN] = {MIN_INT32};

  cout << "Введите число чисел: ";
  cin >> n;

  cout << "Введите числа: ";

  for (i = 0, j = 0; i < n; ++i) {
    cin >> value;

    if (value > maxArray[j % LEN])
      maxArray[j % LEN] = value;

    ++j;

    if (j == LEN) 
      j = 0;
  }

  cout << "Максимальные: ";

  if (n < LEN)
    for (i = 0; i < j; ++i)
      cout << maxArray[i] << " ";
  else
    for (i = 0; i < LEN; ++i)
      cout << maxArray[(j + i) % LEN] << " ";
  
  cout << endl;
}