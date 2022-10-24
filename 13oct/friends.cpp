#include <cmath>
#include <iostream>

using namespace std;

int S(int a) {
  int s = 1;

  for (int i = 2; i < a; i++)
    if (a % i == 0)
      s += i;

  return s;
}

int main() {
  int a, b;

  cout << "Введите числа a и b: ";

  cin >> a >> b;

  if (S(a) == b && a == S(b))
    cout << "Они дружественные!";
  else
    cout << "Они не дружественные!";
}