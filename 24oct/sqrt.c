#include <math.h>
#include <stdio.h>

int main() {
  double a, b, guess, r, e;

  scanf("%lf %lf", &r, &e);

  if (r < 0) {
    printf("У отрицательных чисел нет корня!");
    return -1;
  }

  a = 0;
  b = r;

  while (1) {
    guess = (a + b) / 2;

    if (fabs(guess * guess - r) < e)
      break;

    if (guess * guess > r)
      b = guess;
    else
      a = guess;
  }

  printf("%f", guess);
}