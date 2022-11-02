#include <iostream>

using namespace std;

double *tree;
int treeTop;

void swap(double *a, double *b) {
  double t;

  t = *a;
  *a = *b;
  *b = t;
}

bool uniquePushTree(int i) {
  int child, parent;

  tree[treeTop] = i;

  child = treeTop, parent = (child - 1) / 2;

  ++treeTop;

  while (tree[child] < tree[parent]) {
    swap(&tree[child], &tree[parent]);

    child = parent;
    parent = (child - 1) / 2;
  }

  return tree[child] != tree[parent] || child == 0;
}

int main() {
  int n;
  double value;

  cin >> n;

  tree = (double *)malloc(n * sizeof(value));
  treeTop = 0;

  for (int i = 0; i < n; ++i) {
    cin >> value;

    if (!uniquePushTree(value)) {
      cout << "Есть как минимум один неуникальный элемент: " << value << endl;
      break;
    }
  }

  free(tree);

  cout << "Все элементы уникальны" << endl;
}