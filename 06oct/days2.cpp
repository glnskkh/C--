#include <iostream>

using namespace std;

bool isLeap(int year) {
  bool leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

  return leap;
}

int main() {
  int day, month, year;

  cout << "Введите дату: ";
  cin >> day >> month >> year;

  if (day < 0 || day > 31 || month < 0 || month > 12) {
    cerr << "Такой даты не существует!";
    return -1;
  }

  int daysElapsed = 31 * (month > 1) +                       // Январь
                    (isLeap(year) ? 29 : 28) * (month > 2) + // Февраль
                    31 * (month > 3) +                       // Март
                    30 * (month > 4) +                       // Апрель
                    31 * (month > 5) +                       // Май
                    30 * (month > 6) +                       // Июнь
                    31 * (month > 7) +                       // Июль
                    31 * (month > 8) +                       // Август
                    30 * (month > 9) +                       // Сентябрь
                    31 * (month > 10) +                      // Октябрь
                    30 * (month > 11) +                      // Ноябрь
                    31 * (month > 12); // Декабрь - никогда не выполняется

  daysElapsed += day;

  cout << daysElapsed;

  return 0;
}