#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convert(char *c) {
  if (islower(*c))
    *c = toupper(*c);
  else if (isupper(*c))
    *c = tolower(*c);
}

void combine(char *s, int len, int i) {
  if (len == i) {
    printf("%s\n", s);
    return;
  }

  combine(s, len, i + 1);

  if (isalpha(s[i])) {
    convert(s + i);

    combine(s, len, i + 1);
  }
}

int main(int argc, char **argv) {
  while (--argc > 0) {
    ++argv;

    combine(*argv, strlen(*argv), 0);
  }
}
