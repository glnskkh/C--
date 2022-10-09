#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
  bool prime = true;

  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0)
    {
      prime = false;
      break;
    }

  return prime;
}

int main()
{
  int n, count, maxCount = 0, maxCountPrime = 0, j, i;

  cout << "Введите n: ";
  cin >> n;

  for (i = n; i > 1; i--)
    if (n % i == 0 && isPrime(i))
    {
      count = 0, j = n;

      while (j % i == 0)
      {
        j /= i;
        count++;
      }

      if (count > maxCount)
      {
        maxCount = count;
        maxCountPrime = i;
      }

      cout << i << "^" << count << endl;
    }

  cout << "Максимальная степень: " << maxCountPrime << "^" << maxCount << endl;
}