#include <iostream>

using namespace std;

const char REPLACE = ' ';

int main(void) {
	string text;

	getline(cin, text);

	string result;

	bool inSpace = false;

	for (int i = 0; i < text.length(); ++i) {
		if (isspace(text[i])) {
			if (!inSpace) {
				inSpace = true;

				result += REPLACE;
			}
		} else {
			if (inSpace)
				inSpace = false;

			result += text[i];
		}
	}  

	cout << result << endl;
}