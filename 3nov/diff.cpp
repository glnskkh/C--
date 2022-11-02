#include <iostream>

using namespace std;

int main() {
  int n;

  cout << "Введите степень многочлена: ";
  cin >> n;

  if (!(n >= 0)) {
    cerr << "Многочлена с такой степенью не существует!";
    return -1;
  }

  cout << "Вид уравнения: a_n * x^n + ... + a_1 * x + a_0;" << endl;

  cout << "Введите коэфициенты при степенях x: ";
  double coef[n + 1];
  for (int i = 0; i < n + 1; ++i)
    cin >> coef[i];

  // При вычислении производной каждый коэфициент
  // умножатеся на соответствущую степень при х:
  // в выбраной нами системе индексации - индекс коэфициента
  for (int i = 0; i < n + 1; ++i)
    coef[i] *= i;

  cout << "Введите x_0: ";
  double x;
  cin >> x;

  // Схема горнера
  double result = 0;
  for (int i = n; i > 0; --i)
    result = result * x + coef[i];

  cout << "Прозводная этого многочлена в точке x_0: " << result;
}