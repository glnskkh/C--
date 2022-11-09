#include <iostream>
#include <string.h>

using namespace std;

#define MAX_LEN 100
#define ROMAN_COUNT 7

#define FIVE_TIMES_SHIFT 1
#define TEN_TIMES_SHIFT 2

char ROMAN_DIGITS[ROMAN_COUNT] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

void reverse(char *buffer, int len) {
  char t;

  for (int i = 0; i < len / 2; ++i) {
    t = buffer[i];
    buffer[i] = buffer[len - 1 - i];
    buffer[len - 1 - i] = t;
  }
}

int main() {
  char arabic[MAX_LEN];

  scanf("%s", arabic);

  int len = strlen(arabic);

  reverse(arabic, len);

  char roman[MAX_LEN];

  char *roman_top = roman;
  char *roman_digit = ROMAN_DIGITS;

  char *arabic_digit = arabic;

  while (roman_digit < ROMAN_DIGITS + ROMAN_COUNT &&
         arabic_digit < arabic + len) {
    *arabic_digit -= '0';

    if (1 <= *arabic_digit && *arabic_digit <= 3) {
      while ((*arabic_digit)-- > 0)
        *(roman_top++) = *roman_digit;
    } else if (*arabic_digit == 4) {
      *(roman_top++) = *(roman_digit + FIVE_TIMES_SHIFT);
      *(roman_top++) = *roman_digit;
    } else if (5 <= *arabic_digit && *arabic_digit <= 8) {
      while ((*arabic_digit)-- > 5)
        *(roman_top++) = *roman_digit;
      *(roman_top++) = *(roman_digit + FIVE_TIMES_SHIFT);
    } else if (*arabic_digit == 9) {
      *(roman_top++) = *(roman_digit + TEN_TIMES_SHIFT);
      *(roman_top++) = *roman_digit;
    }

    arabic_digit++;
    roman_digit += TEN_TIMES_SHIFT;
  }

  *(roman_top++) = '\0';

  reverse(roman, (roman_top - roman - 1));

  printf("%s\n", roman);
}