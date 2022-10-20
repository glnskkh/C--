#include <iostream>

using namespace std;

int countDigits(int n, int digit)
{
  int count = 0;

  while (n > 0)
  {
    if (n % 10 == digit)
      count++;

    n /= 10;
  }

  return count;
}

int main()
{
  int n, i, j, result = 0;

  cout << "Введите n: ";
  cin >> n;

  // За 9*n проходов цикла

  for (i = 9; i >= 0; --i)
    for (j = countDigits(n, i); j > 0; j--)
      result = result * 10 + i;

  cout << "Максимальное число, полученное перестановкой цифр числа: " << result;
}