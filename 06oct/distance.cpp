#include <iostream>
#include <cmath>

using namespace std;

struct Point
{
  double x, y;
};

double distance(struct Point p1, struct Point p2)
{
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double Sgeron(double a, double b, double c)
{
  double p = (a + b + c) / 2.0;

  double S = sqrt(p * (p - a) * (p - b) * (p - c));

  return S;
}

int main(void)
{
  struct Point a, b, c;
  double l, p, q, h;

  cout << "Координаты a: ";
  cin >> a.x >> a.y;

  cout << "Координаты b: ";
  cin >> b.x >> b.y;

  cout << "Координаты c: ";
  cin >> c.x >> c.y;

  l = distance(a, b);

  p = distance(c, a);
  q = distance(c, b);

  if (p * p + l * l < q * q || q * q + l * l < p * p)
  {
    cout << min(p, q);
  }
  else
  {
    h = 2 * Sgeron(l, p, q) / l;

    cout << min(min(p, q), h);
  }
}