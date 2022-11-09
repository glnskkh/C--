#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define MAX_LEN 100

int removeNonDigits(char *buffer, int len) {
  int i = 0, j = 0;

  while (i < len) {
    if (isdigit(buffer[i]))
      buffer[j++] = buffer[i];

    ++i;
  }

  return j;
}

int main(void) {
  char A[MAX_LEN], B[MAX_LEN];
  int i, j;

  printf("%s\n", "Введите массив A: ");

  scanf("%s\n", A);

  printf("%s\n", "Введите массив B: ");

  scanf("%s\n", B);

  int lenA = removeNonDigits(A, strlen(A));
  int lenB = removeNonDigits(B, strlen(B));

  for (int i = 0, j = lenB - 1; i < lenA && j >= 0; ++i, --j) {
    if (A[i] != B[j]) {
      cerr << "Они несимметричны!";
      exit(EXIT_FAILURE);
    }
  }
}