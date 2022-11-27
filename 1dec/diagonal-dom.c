#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
  int n, i, j;
  double *A, sum;
  bool strictly, more;

  scanf("%d", &n);

  A = malloc(sizeof(double) * n * n);

  for (i = 0; i < n * n; ++i)
    scanf("%lf", A + i);

  strictly = more = false;
  
  for (i = 0; i < n; ++i) {
    sum = 0.0;

    for (j = 0; j < n; ++j)
      if (j != i)
        sum += abs(A[i * n + j]);

    sum = abs(A[i * n + i]) - sum;

    if (sum >= 0.0) {
      if (sum > 0.0)
        strictly = true;

      more = true;
    } else {
      more = false;
      break;
    }
  }

  if (strictly && more)
    printf("%s\n", "Диагональ доминирует");
  else
    printf("%s\n", "Диагональ не доминирует");
}
