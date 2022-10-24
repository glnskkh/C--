#include <math.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main() {
  char digits[MAX_LEN], digit;
  int i, len, A, B, dotPosition;
  long intermedian;
  double normal;

  printf("Введите исходную систему счисления: ");
  scanf("%d", &A);

  printf("Введите число: ");
  scanf("%s", digits);

  len = strlen(digits);

  printf("Введите желаемую систему счисления: ");
  scanf("%d", &B);

  intermedian = 0, dotPosition = -1;
  for (i = 0; i < len; ++i) {
    digit = digits[i];

    if (digit == '.') {
      dotPosition = i;
      continue;
    }

    if ('0' <= digit && digit <= '9') {
      if (digit - '0' >= A) {
        printf("Одна из цифр числа больше основания системы счисления!");
        return -1;
      } else {
        intermedian = A * intermedian + (digit - '0');
      }
    } else if ('a' <= digit && digit <= 'z') {
      if (digit - 'a' + 10 >= A) {
        printf("Одна из цифр числа больше основания системы счисления!");
        return -1;
      } else {
        intermedian = A * intermedian + (digit - 'a' + 10);
      }
    }
  }

  normal = (double)intermedian;
  if (dotPosition != -1)
    normal /= pow(A, len - dotPosition - 1);

  printf("%f\n", normal);
}