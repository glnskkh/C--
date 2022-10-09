#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  double a, b, c;

  cout << "Введите стороны потенциального треугольника: ";
  cin >> a >> b >> c;

  bool isTriangle =
      a + b > c && b + c > a && c + a > b;

  if (!isTriangle)
  {
    cout << "Это не треугольник";
    return -1;
  }

  cout << "Это треугольник, а именно ";

  double a2 = a * a, b2 = b * b, c2 = c * c;

  bool isAcute = a2 + b2 > c2 && a2 + c2 > b2 && b2 + c2 > a2;
  bool isObtuse = a2 + b2 < c2 || a2 + c2 < b2 || c2 + b2 < a2;

  if (isAcute)
    cout << "остроугольный";
  else if (isObtuse)
    cout << "тупоугольный";
  else
    cout << "прямоугольный";

  return 0;
}