#include <stdio.h>

int max(int a, int b) {
  if (a > b)
    return a;

  return b;
}

int max_arr(int *arr, size_t len) {
  if (len == 1)
    return *arr;

  return max(*arr, max_arr(arr + 1, len - 1));
}

int main(void) {
  size_t n;

  scanf("%ld", &n);

  int arr[n];

  for (int i = 0; i < n; ++i)
    scanf("%d", arr + i);

  printf("%d\n", max_arr(arr, n));
}