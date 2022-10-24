#include <cmath>
#include <iostream>

using namespace std;

double distance(double p1x, double p1y, double p2x, double p2y) {
  return sqrt(pow(p1x - p2x, 2) + pow(p1y - p2y, 2));
}

double Sgeron(double a, double b, double c) {
  double p = (a + b + c) / 2.0;

  double S = sqrt(p * (p - a) * (p - b) * (p - c));

  return S;
}

bool isObtuseA(double a, double b, double c) {
  return pow(a, 2) > pow(b, 2) + pow(c, 2);
}

int main(void) {
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

  if (isObtuseA(q, p, l) || isObtuseA(p, q, l))
    cout << min(p, q);
  else {
    h = 2 * Sgeron(l, p, q) / l;

    cout << h;
  }
}