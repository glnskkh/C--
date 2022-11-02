#include <iostream>

using namespace std;

double *tree;
int maxLen;
int treeTop = 0;

void swap(double *a, double *b) {
  double t;

  t = *a, *a = *b, *b = t;
}

double pop() {
  int childL, childR, parent;

  if (treeTop == 0) {
    cerr << "Нет элементов дерева!";
    return 0.0;
  }

  double value = tree[0];

  swap(tree, tree + treeTop - 1);

  --treeTop;

  parent = 0, childL = parent * 2 + 1, childR = parent * 2 + 2;

  while (childL < treeTop) {
  	if (childR < treeTop && tree[childR] < tree[childL] && tree[childR] < tree[parent]) {
      swap(tree + childR, tree + parent);

      parent = childR;
      childL = parent * 2 + 1, childR = parent * 2 + 2;
    } else if (tree[childL] < tree[parent]) {
      swap(tree + childL, tree + parent);

      parent = childL;
      childL = parent * 2 + 1, childR = parent * 2 + 2;
    } else
      break;
  }

  return value;
}

void push(double value) {
  int child, parent;

  if (treeTop == maxLen && value < tree[0])
    return;

  if (treeTop == maxLen)
    pop();

  tree[treeTop] = value;

  child = treeTop, parent = (treeTop - 1) / 2;

  treeTop++;

  while (tree[child] < tree[parent]) {
    swap(tree + child, tree + parent);

    child = parent;
    parent = (child - 1) / 2;
  }
}

int main() {
  int n, i, value;

  cin >> n;
  cin >> maxLen;

  tree = (double *)malloc(maxLen * sizeof(double));

  for (i = 0; i < n; ++i) {
    cin >> value;

    push(value);
  }

  for (; treeTop > 0;)
    cout << pop() << " ";
}