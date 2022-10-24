#include <cmath>
#include <iostream>

using namespace std;

bool isPrime(int a) {
  bool prime = true;

  for (int i = 2; i <= (int)floor(sqrt(a)); i++)
    if (a % i == 0) {
      prime = false;
      break;
    }

  return prime;
}

int main() {
  int a, b;

  cout << "Введите a, b: ";
  cin >> a >> b;

  if (!(a > 0 && b > 0)) {
    cerr << "Это не числа-близнецы: они не натуральны!";
    return -1;
  }

  if (abs(a - b) != 2) {
    cerr << "Это не числа-близнецы: они отличаются не на два!";
    return -1;
  }

  if (!isPrime(a)) {
    cerr << "Число a = " << a << " не является простым!";
    return -1;
  }

  if (!isPrime(b)) {
    cerr << "Число b = " << b << " не является простым!";
    return -1;
  }

  cout << "Числа a = " << a << " и b = " << b << " являются близнецами!";
  return 0;
}