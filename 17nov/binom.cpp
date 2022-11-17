#include <iostream>

using namespace std;

int main(void) {
	int C = 1, k = 0, n, m;

	cin >> n;

	m = n;
	while (k < n + 1) {
		cout << C << " ";

		C *= (m--);
		C /= (++k);
	}

	cout << endl;
}