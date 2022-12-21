#include <iostream>

using namespace std;

struct Point
{
  double x;
  double y;
};

void swap(Point *array, int i, int j)
{
  Point p = array[i];
  array[i] = array[j];
  array[j] = p;
}

void sortPoints(Point *array, int n, double maxY)
{
  if (n == 1)
    return;

  int max = 0;

  for (int i = 0; i < n; ++i)
    if (array[max].x * maxY + array[max].y < array[i].x * maxY + array[i].y)
      max = i;

  swap(array, n - 1, max);

  sortPoints(array, n - 1, maxY);
}

int main(void)
{
  int n;

  cin >> n;

  Point points[n];

  for (int i = 0; i < n; ++i)
    cin >> points[i].x >> points[i].y;

  double maxY = 0;

  for (int i = 0; i < n; ++i)
    if (abs(maxY) < abs(points[i].y))
      maxY = abs(points[i].y);

  sortPoints(points, n, maxY + 1);

  for (int i = 0; i < n; ++i)
    cout << points[i].x << " " << points[i].y << endl;
}
