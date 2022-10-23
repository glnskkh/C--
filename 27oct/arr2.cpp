#include <ctype.h>
#include <stdio.h>

int main() {
  int n = __INT_MAX__ + 1, m = 0;
  int sign = 1;
  int ch;

  while ((ch = getchar())) {
    if (isdigit(ch)) {
      m = 10 * m + (ch - '0');
    } else if (isspace(ch)) {
      if (n > sign * m) {
        printf("Не по неубыванию!");
        return -1;
      }

      n = sign * m, m = 0;
      sign = 1;
    } else if (ch == '-')
      sign = -1;
  }

  printf("По неубыванию!");
}