#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int i = 0;
  while ((3 * i) % 8 != 2)
    i++;

  int x = 27 * i + 38;

  cout << x;
}