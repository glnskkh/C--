#include <iostream>

int years0(int year)
{
  int d = year / 4;

  d -= year / 100;

  d += year / 400;

  return d;
}

int main()
{
  int year1, year2;

  std::cin >> year1 >> year2;

  std::cout << years0(year2) - years0(year1);
}