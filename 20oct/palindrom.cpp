#include <iostream>

using namespace std;

int reversed(int n, int sys = 10) {
  int result = 0;

  while (n > 0) {
    result = (sys * result) + (n % sys);
    n /= sys;
  }

  return result;
}

int main() {
  int n, k;

  cout << "Введите число n: ";
  cin >> n;

  if (n == reversed(n))
    cout << "Это число - палиндром";
  else
    cout << "Это число - не палиндром";
}