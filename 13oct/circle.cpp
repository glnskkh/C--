#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  double R, x, y, d;
  cout << "Введите R, x, y: ";
  cin >> R >> x >> y;

  if (y > 0)
    d = abs(sqrt(x * x + y * y) - R);
  else
    d = sqrt(pow(abs(x) - R, 2) + y * y);

  cout << d;
}