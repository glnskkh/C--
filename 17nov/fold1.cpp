#include <iostream>

using namespace std;

const char REPLACE = ' ';

int main(void) {
  string text;

  getline(cin, text);

  bool inSpace = false;

  int i = 0, j = 0;
  while (i < text.length()) {
    if (isspace(text[i])) {
      if (!inSpace) {
        inSpace = true;

        text[j++] = REPLACE;
      }
    } else {
      if (inSpace)
        inSpace = false;

      text[j++] = text[i];
    }
    ++i;
  }

  text[j++] = '\0';

  cout << text << endl;
}