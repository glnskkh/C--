#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

int *read(int n)
{
  int *A = (int *)calloc(n, sizeof(int));

  for (int i = 0; i < n; ++i)
    scanf("%d", A + i);

  return A;
}

void print(int *A, int n)
{
  for (int i = 0; i < n; ++i)
    printf("%d ", A[i]);
}

int main(void)
{
  int shift, n, *A;

  scanf("%d %d", &shift, &n);

  A = read(n);

  shift %= n;

  if (shift == 0)
  {
    print(A, n);
    return 0;
  }

  for (int count = 0, i = 0; count < n; ++i, ++count)
  {
    int current = (i + shift) % n, next;

    while (current != i)
    {
      next = (current + shift) % n;

      swap(A + current, A + next);

      current = next;

      ++count;
    }
  }

  print(A, n);
}
