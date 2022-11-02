#include <iostream>

using namespace std;

int main() {
  int x, y, z, n;

  cin >> n;

  cin >> x >> y >> z;

  int a, b, c;

  if (x >= y && y >= z)
    a = x, b = y, c = z;
  if (x >= z && z >= y)
    a = x, b = z, c = y;
  if (y >= x && x >= z)
    a = y, b = x, c = z;
  if (y >= z && z >= x)
    a = y, b = z, c = x;
  if (z >= x && x >= y)
    a = z, b = x, c = y;
  if (z >= y && y >= x)
    a = z, b = y, c = x;

  for (int i = 3; i < n; ++i) {
    int value;

    cin >> value;

    if (value > a) {
      c = b;
      b = a;
      a = value;
    } else if (a >= value && value > b) {
      c = b;
      b = value;
    } else if (b >= value && value > c) {
      c = value;
    }
  }

  cout << a << " " << b << " " << c;
}