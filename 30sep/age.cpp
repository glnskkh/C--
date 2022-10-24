#include <iostream>

int main() {
  int a;

  std::cin >> a;

  if ((a % 100) / 10 == 1)
    std::cout << a << " лет" << std::endl;
  else {
    int p = a % 10;

    if (p == 1)
      std::cout << a << " год" << std::endl;
    else if (2 <= p && p <= 4)
      std::cout << a << " года" << std::endl;
    else
      std::cout << a << " лет" << std::endl;
  }
}