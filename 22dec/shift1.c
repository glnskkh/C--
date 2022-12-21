#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

void cycle(int *A, int n)
{
  int current = 0, next;

  do
  {
    next = (current + 1) % n;

    swap(A + current, A + next);

    current = next;
  } while (current != n - 1);
}

int main(void)
{
  int shift, n, *A;

  scanf("%d %d", &shift, &n);

  A = (int *)calloc(n, sizeof(int));

  for (int i = 0; i < n; i++)
    scanf("%d", A + i);

  for (int i = 0; i < shift; ++i)
    cycle(A, n);

  for (int i = 0; i < n; i++)
    printf("%d ", A[i]);
}
