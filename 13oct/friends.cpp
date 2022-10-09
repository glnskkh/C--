#include <iostream>
#include <cmath>

using namespace std;

int S(int a)
{
  int s = 0;

  for (int i = 2; i < a; i++)
    if (a % i == 0)
      s += i;

  return s;
}

int main()
{
  int a, b;

  cout << "Введите числа a и b: ";
}