#include <iostream>
#include <fstream>

using namespace std;

struct Counter
{
  string *word;
  int count;
};

Counter *readCounters(char *words_path, int *n_words)
{
  ifstream words(words_path);

  words >> *n_words;

  Counter *counters = (Counter *)calloc(*n_words, sizeof(Counter));

  for (int i = 0; i < *n_words; ++i)
  {
    counters[i].word = new string;
    words >> *counters[i].word;
    counters[i].count = 0;
  }

  words.close();

  return counters;
}

int findInCounters(Counter *counters, int n_words, string word)
{
  for (int i = 0; i < n_words; ++i)
  {
    int j = 0;

    while (j < word.length() && j < (*counters[i].word).length() && (*counters[i].word)[j] == word[j])
      ++j;

    if (j == (*counters[i].word).length() && j == word.length())
      return i;
  }

  return -1;
}

void countWords(Counter *counters, int n_words, char *text_path)
{
  ifstream text(text_path);

  while (!text.eof())
  {
    string word;

    text >> word;

    int index = findInCounters(counters, n_words, word);

    if (index != -1)
      counters[index].count++;
  }

  text.close();
}

void sortCounters(Counter *counters, int n_words)
{
  if (n_words <= 1)
    return;

  Counter *minCounter = counters + n_words - 1;

  for (int i = 0; i < n_words - 1; ++i)
    if (counters[i].count < minCounter->count)
      minCounter = counters + i;

  {
    static Counter *t = (Counter *)malloc(sizeof(Counter));

    t->word = minCounter->word;
    t->count = minCounter->count;

    minCounter->word = counters[n_words - 1].word;
    minCounter->count = counters[n_words - 1].count;

    counters[n_words - 1].word = t->word;
    counters[n_words - 1].count = t->count;
  }

  sortCounters(counters, n_words - 1);
}

void destroy(Counter *counters, int n_words)
{
  for (int i = 0; i < n_words; ++i)
    delete counters[i].word;

  free(counters);
}

int main(int argc, char **argv)
{
  if (argc < 3)
  {
    cerr << "Too few files: need words file and text file" << endl;
    exit(EXIT_FAILURE);
  }

  int n_words;
  Counter *counters = readCounters(argv[1], &n_words);

  countWords(counters, n_words, argv[2]);

  sortCounters(counters, n_words);

  for (int i = 0; i < n_words; ++i)
    cout << (*counters[i].word) << ": " << counters[i].count << endl;

  destroy(counters, n_words);
}
