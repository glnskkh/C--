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

  int daysInMonthes[] = {
      31,                     // Январь
      isLeap(year) ? 29 : 28, // Февраль
      31,                     // Март
      30,                     // Апрель
      31,                     // Май
      30,                     // Июнь
      31,                     // Июль
      31,                     // Август
      30,                     // Сентябрь
      31,                     // Октябрь
      30,                     // Ноябрь
      31,                     // Декабрь
  };

  int daysElapsed = 0;
  for (int i = 0; i < month - 1; i++)
    daysElapsed += daysInMonthes[i];

  daysElapsed += day;

  cout << daysElapsed;

  return 0;
}