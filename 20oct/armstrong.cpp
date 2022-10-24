#include <iostream>

using namespace std;

int countDigits(int n) {
  int count = 0;

  while (n > 0)
    ++count, n /= 10;

  return count;
}

int pow(int n, int power) {
  int b = 1, c = n, k = power;

  while (k > 0) {
    if (k % 2 == 0) {
      c *= c;
      k /= 2;
    } else {
      b *= c;
      k--;
    }
  }

  return b;
}

int main() {
  int n, k, S, digits;

  cout << "Введите число n: ";
  cin >> n;

  k = n, S = 0, digits = countDigits(n);
  while (k > 0) {
    S += pow(k % 10, digits);
    k /= 10;
  }

  if (n == S)
    cout << "Число " << n << " является числом армстронга!";
  else
    cout << "Число " << n << " не является числом армстронга";
}