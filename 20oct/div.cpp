#include <iostream>

using namespace std;

int main() {
  int n, k, digit;

  cout << "Введите n: ";
  cin >> n;

  k = n;
  while (k > 0) {
    digit = k % 10;

    if (digit != 0 && n % digit == 0)
      break;

    k /= 10;
  }

  if (n % digit == 0)
    cout << "Число " << n << " делится на " << digit;
  else
    cout << "Число " << n << " не делится ни на одну из своих цифр!";
}