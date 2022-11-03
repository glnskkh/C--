#include <iostream>

using namespace std;

string SENT_SEP = "!?.\n";
string WORDS_SEP = " -!?.,:;\n";

bool contains(string s, char c) {
  for (const char t : s)
    if (t == c)
      return true;

  return false;
}

int main() {
  string text;

  getline(cin, text);

  int totalSentences = 0, totalWords = 0;

  bool inWord = false, inSentence = false;
  for (const char c : text) {
    if (contains(SENT_SEP, c)){
      if (inSentence)
        ++totalSentences;

      inSentence = false;
    } else
      inSentence = true;

    if (contains(WORDS_SEP, c)) {
      if (inWord)
        ++totalWords;

      inWord = false;
    } else
      inWord = true;
  }

  if (inWord)
    ++totalWords;

  if (inSentence)
    ++totalSentences;

  if (totalSentences == 0) {
    cerr << "Нет предложений в тексте!";
    return -1;
  }

  double wordsPerSentence = (double)totalWords / totalSentences;

  cout << "Среднее число слов в предложении: " << wordsPerSentence << endl;
  cout << "Всего предложений: " << totalSentences << endl;
}