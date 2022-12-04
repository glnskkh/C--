#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isFree(int *Q, int len, int posX, int posY) {
  for (int i = 0; i < len; ++i)
    if (posX == Q[i] || Q[i] + i == posX + posY || Q[i] - i == posX - posY)
      return false;

  return true;
}

int count(int *Q, int len, int i) {
  if (i == len) {
    for (i = 0; i < len; ++i)
      printf("(%d %d)\t", Q[i], i);
    printf("\n");
    return 1;
  }

  int sum = 0;

  for (int j = 0; j < len; ++j)
    if (isFree(Q, i, j, i)) {
      Q[i] = j;
      sum += count(Q, len, i + 1);
    }

  return sum;
}

int main(void) {
  int n;

  scanf("%d", &n);

  int *Q = malloc(sizeof(int) * n);

  printf("%d\n", count(Q, n, 0));
}
