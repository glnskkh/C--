#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool decending(int a) {
  if (a < 10)
    return true;

  return (a / 10) % 10 < a % 10 && decending(a / 10);
}

int main(void) {
  int a;

  scanf("%d", &a);

  if (decending(a))
    printf("%s\n", "Убывает");
  else
    printf("%s\n", "Неубывает");

  exit(EXIT_SUCCESS);
}