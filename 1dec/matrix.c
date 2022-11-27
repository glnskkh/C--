#include <stdio.h>

int main(void) {
  int n, i, j;

  scanf("%d", &n);

  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j)
      printf("%d\t", (n + j - i) % n + 1);
    printf("\n");
  }
}
