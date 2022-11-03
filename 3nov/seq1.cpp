#include <iostream>

using namespace std;

#define BUFFER_SIZE 2

int main() {
  int a, b;
  int n, current, next, value, curLen, maxLen;

  cout << "Введите число чисел, с которыми будем работать: ";
  cin >> n;

  if (n < 3) {
    cerr
        << "Менее трех чисел не могут образовывать арифметическую прогрессию: ";
    return -1;
  }

  cout << "Введите последовательность чисел: ";

  cin >> a;
  cin >> b;

  n -= 2;

  current = 0, curLen = 2, maxLen = -1;
  while (n-- > 0) {
    cin >> value;

    if (a + value == 2 * b)
      ++curLen;
    else
      curLen = 2;

    if (maxLen < curLen)
      maxLen = curLen;

    a = b, b = value;

    current = next;
  }

  cout << maxLen << endl;
}