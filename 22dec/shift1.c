#include <stdio.h>
#include <stdlib.h>

#define swap(T, a, b) \
  {                   \
    T t = a;          \
    a = b;            \
    b = t;            \
  }

int main(void)
{
  int shift, n, *A;

  scanf("%d %d", &shift, &n);

  A = (int *)calloc(n, sizeof(int));

  for (int i = 0; i < n; i++)
    scanf("%d", A + i);

  int current = 0, next;

  do
  {
    next = (current + shift) % n;

    swap(int, A[current], A[next]);

    current = next;
  } while (current != 0);

  for (int i = 0; i < n; i++)
    printf("%d", A[i]);
}
