#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  double a1x, a1y, a2x, a2y;
  double b1x, b1y, b2x, b2y;

  cout << "Первый квадрат: ";
  cin >> a1x >> a1y >> a2x >> a2y;

  cout << "Второй квадрат: ";
  cin >> b1x >> b1y >> b2x >> b2y;

  double intersectionX = min(a2x, b2x) - max(a1x, b1x);
  double intersectionY = min(a2y, b2y) - max(a1y, b1y);

  if (intersectionX < 0 || intersectionY < 0)
    cout << "Нет пересечения";
  else
  {
    double S = intersectionX * intersectionY;

    cout << "Площадь пересечения: " << S << endl;
  }
}