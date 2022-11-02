#include <iostream>

using namespace std;

#define BUFFER_SIZE 2

int main() {
	int buffer[BUFFER_SIZE];
	int n, i, current, next, value, curLen, maxLen;

	cout << "Введите число чисел, с которыми будем работать: ";
	cin >> n;

	if (n < 3) {
		cerr << "Менее трех чисел не могут образовывать арифметическую прогрессию: ";
		return -1;
	}

	cout << "Введите последовательность чисел: ";

	i = 0;
	while (i < BUFFER_SIZE)
		cin >> buffer[i++];

	current = 0, curLen = 2, maxLen = -1;
	while ((i++) < n) {
		cin >> value;

		next = (current + 1) % BUFFER_SIZE;

		if (buffer[current] + value == 2 * buffer[next])
			++curLen;
		else			
			curLen = 2;

		if (maxLen < curLen)
			maxLen = curLen;

		buffer[current] = value;

		current = next;
	}

	cout << maxLen << endl;
}