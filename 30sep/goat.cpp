#include <cmath>
#include <iostream>

int main() {
  double l, a;

  std::cin >> l >> a;

  a /= 2;

  if (l >= a * M_SQRT2)
    std::cout << pow(a * 2, 2) << std::endl;
  else if (l <= a)
    std::cout << M_PI * pow(l, 2) << std::endl;
  else {
    double circleS = M_PI * pow(l, 2);

    double angle = acos(a / l);

    double sectorS = pow(l, 2) * angle;

    double triangleS = a * l * sin(angle);

    std::cout << circleS - 4 * (sectorS - triangleS) << std::endl;
  }
}