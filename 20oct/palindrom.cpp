#include <iostream>

using namespace std;

int reversed(int n)
{
  int result = 0;

  while (n > 0)
  {
    result = (10 * result) + (n % 10);
    n /= 10;
  }

  return result;
}

int main()
{
  int n, k;

  cout << "Введите число n: ";
  cin >> n;

  if (n == reversed(n))
    cout << "Это число - палиндром";
  else
    cout << "Это число - не палиндром";
}