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

  int roman_top = 0;
  int roman_digit = 0;

  int arabic_digit = 0;

  int current_arabic_digit;
  while (roman_digit < ROMAN_COUNT && arabic_digit < len) {
    current_arabic_digit = arabic[arabic_digit] - '0';

    if (1 <= current_arabic_digit && current_arabic_digit <= 3) {
      while ((current_arabic_digit)-- > 0)
        roman[roman_top++] = ROMAN_DIGITS[roman_digit];
    } else if (current_arabic_digit == 4) {
      roman[roman_top++] = ROMAN_DIGITS[roman_digit + FIVE_TIMES_SHIFT];
      roman[roman_top++] = ROMAN_DIGITS[roman_digit];
    } else if (5 <= current_arabic_digit && current_arabic_digit <= 8) {
      while ((current_arabic_digit)-- > 5)
        roman[roman_top++] = ROMAN_DIGITS[roman_digit];
      roman[roman_top++] = ROMAN_DIGITS[roman_digit + FIVE_TIMES_SHIFT];
    } else if (current_arabic_digit == 9) {
      roman[roman_top++] = ROMAN_DIGITS[roman_digit + TEN_TIMES_SHIFT];
      roman[roman_top++] = ROMAN_DIGITS[roman_digit];
    }

    arabic_digit++;
    roman_digit += TEN_TIMES_SHIFT;
  }

  roman[roman_top++] = '\0';

  reverse(roman, roman_top - 1);

  printf("%s\n", roman);
}