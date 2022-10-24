#include <iostream>

using namespace std;

int len(int n, int sys = 10) {
  int l = 0;

  while (n > 0)
    ++l, n /= sys;

  return l;
}

int main() {
  int position;

  cin >> position;

  int a = 0, b = 1;
  int l;

  while ((l = len(b)) < position) {
    position -= l;
    b = b + a;
    a = b - a;
  }

  while ((l - position) > 0)
    b /= 10, ++position;

  b %= 10;

  cout << b;
}