#include <iostream>

using namespace std;

int main() {
  int N;

  cout << "Введите длину массива: ";
  cin >> N;

  int arr[N];

  for (int i = 0; i < N; ++i)
    cin >> arr[i];

  for (int i = 0; i < N - 1; ++i)
    if (!(arr[i] < arr[i + 1])) {
      cout << "Не по возрастанию!!!";
      return 0;
    }

  cout << "По возрастанию";
}