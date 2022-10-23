#include <iostream>

using namespace std;

#define MAX_LEN 100

int remainders[MAX_LEN] = {-1};
int digits[MAX_LEN] = {0};

int findRepeat(int reminder, int digit) {
  int index = 0;

  while (index < MAX_LEN) {
    if (remainders[index] == reminder && digits[index] == digit)
      return index;
    else if (remainders[index] == -1)
      break;

    ++index;
  }

  return -1;
}

int main() {
  int a, b;

  cout << "Введите числа a и b: ";
  cin >> a >> b;

  if (b == 0) {
    cerr << "Деление на ноль невозможно!";
    return -1;
  }

  int integerPart = a / b;
  cout << "Тогда a/b: " << integerPart;

  if (a % b == 0) {
    cout << endl;
    return 0;
  }

  a = a % b;

  cout << ".";

  int q, r;
  int repeatIndex;
  int *curRemainder = remainders, *curDigit = digits;

  while (true) {
    a *= 10;

    q = a / b;
    r = a % b;

    repeatIndex = findRepeat(r, q);

    if (repeatIndex != -1)
      break;

    *curDigit = q, ++curDigit;
    *curRemainder = r, ++curRemainder;

    a = r;
  }

  int i = 0;
  while (i < repeatIndex)
    cout << digits[i++];

  if (curRemainder == remainders + i)
    return 0;

  cout << '(';

  while (remainders + i < curRemainder)
    cout << digits[i++];

  cout << ')';

  cout << endl;
}