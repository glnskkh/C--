#include <iostream>
#include <cmath>

using namespace std;

double distance(double p1x, double p1y, double p2x, double p2y)
{
  return sqrt(pow(p1x - p2x, 2) + pow(p1y - p2y, 2));
}

double Sgeron(double a, double b, double c)
{
  double p = (a + b + c) / 2.0;

  double S = sqrt(p * (p - a) * (p - b) * (p - c));

  return S;
}

int main(void)
{
  double ax, bx, cx, ay, by, cy;
  double l, p, q, h;

  cout << "Координаты a: ";
  cin >> ax >> ay;

  cout << "Координаты b: ";
  cin >> bx >> by;

  cout << "Координаты c: ";
  cin >> cx >> cy;

  l = distance(ax, ay, bx, by);

  p = distance(cx, cy, ax, ay);
  q = distance(cx, cy, bx, by);

  if (p * p + l * l < q * q || q * q + l * l < p * p)
    cout << min(p, q);
  else
  {
    h = 2 * Sgeron(l, p, q) / l;

    cout << h;
  }
}