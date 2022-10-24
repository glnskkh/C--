#include <iostream>

using namespace std;

int main() {
  double x, y, a;

  cout << "Введите x, y, a: ";
  cin >> x >> y >> a;

  double absX = abs(x), absY = abs(y);
  double halfA = a / 2;

  bool inside = absX < halfA && absY < halfA;
  bool outside = absX > halfA || absY > halfA;

  if (inside)
    cout << "Точка находится внутри";
  else if (outside)
    cout << "Точка находится снаружи";
  else
    cout << "Точка лежит на границе";
}