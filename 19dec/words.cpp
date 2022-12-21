#include <iostream>
#include <fstream>

using namespace std;

struct Word
{
  string word;

  int count;
};

#define MAX_LEN 100

Word words[MAX_LEN];
int top = 0;

void addToWords(string word)
{
  int i;
  for (i = 0; i < top && word != words[i]; ++i)
    ;

  if (i != top)
  {
    ++words[i].count;
    return;
  }

  words[top].word = word;
  words[top].count = 1;
  ++top;
}

int main(int argc, char **argv)
{
  ifstream input('line.cpp');
  string word;

  while (!input.eof())
  {
    input >> word;

    addToWords(word);
  }

  // for (int i <)
}
