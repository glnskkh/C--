#include <stdio.h>

int main(void)
{
  int n, m, k, t, count = 0;

  scanf("%d %d %d", &n, &m, &k);


  while (!(n < k && m < k))
  {
    if (n < m)
      t = n, n = m, m = t;

    int d1 = n % k, d2 = m % k;

    if (d1 == 0 || d2 == 0)
    {
      count += n * m / k;

      n = m = 0;
    }
    else if (d1 == d2 && d1 > 1)
    {
      count += 2 * ((n / k) * d2 + (m / k) * d1);

      n -= 2 * d1;
      m -= 2 * d2;
    }
    else
    {
      count += (n / k) * m;
      n %= k;

      count += (m / k) * n;
      m %= k;
    }
  }

  printf("%d\n", count);
}
