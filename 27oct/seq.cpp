#include <iostream>

using namespace std;

int main() {
  double x, epsilon;

  cout << "Введите x и e: ";
  cin >> x >> epsilon;

  double x2 = x * x;
  int f = 1;

  // d = (-1)^(n+1) * x^(2n-1) / (3^(n-1) * (2n - 1)!)
  double d = 1 * x / 1 * f;

  double sum = 0;

  while (abs(d) > epsilon) {
    sum += d;

    d *= (-1 * x2) / (3 * (f + 1) * (f + 2));

    f += 2;
  }

  cout << sum;
}