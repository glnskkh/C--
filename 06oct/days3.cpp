#include <iostream>

using namespace std;

bool isLeap(int year)
{
  bool leap =
      (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

  return leap;
}

int main()
{
  int day, month, year;

  cout << "Введите дату: ";
  cin >> day >> month >> year;

  if (day < 0 || day > 31 || month < 0 || month > 12)
  {
    cerr << "Такой даты не существует!";
    return -1;
  }

  int daysElapsed = 0;

  switch (month - 1)
  {
  case 12:
    daysElapsed += 31;
  case 11:
    daysElapsed += 30;
  case 10:
    daysElapsed += 31;
  case 9:
    daysElapsed += 30;
  case 8:
    daysElapsed += 31;
  case 7:
    daysElapsed += 31;
  case 6:
    daysElapsed += 30;
  case 5:
    daysElapsed += 31;
  case 4:
    daysElapsed += 30;
  case 3:
    daysElapsed += 31;
  case 2:
    daysElapsed += isLeap(year) ? 29 : 28;
  case 1:
    daysElapsed += 31;
  default:
    break;
  }

  daysElapsed += day;

  cout << daysElapsed;

  return 0;
}