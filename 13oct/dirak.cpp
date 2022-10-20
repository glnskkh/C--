#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  for (int i = 0; i < 5; i++)
  {
    int n = 6 + 8 * i;
    int x = (27 * n + 38) / 8;
    cout << x << endl;
  }
}