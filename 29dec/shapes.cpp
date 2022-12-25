#include <iostream>

using namespace std;

struct Point
{
  double x;
  double y;
};

double distanceSq(Point p1, Point p2)
{
  return p1.x * p2.x + p1.y * p2.y;
}

struct Shape
{
  Point *points;
  int size;
  double maxDiagonal;
};

Shape **read(int N)
{
  Shape **shapes = (Shape **)calloc(N, sizeof(Shape *));

  for (int i = 0; i < N; ++i)
  {
    shapes[i] = (Shape *)malloc(sizeof(Shape));

    int n;

    cin >> n;

    shapes[i]->points = (Point *)calloc(n, sizeof(Point));
    shapes[i]->size = n;

    for (int j = 0; j < n; ++j)
      cin >> shapes[i]->points[j].x >> shapes[i]->points[j].y;
  }

  return shapes;
}

int filter(Shape **shapes, int N)
{
  int top = 0;

  for (int i = 0; i < N; i++)
  {
    if (shapes[i]->size <= 3)
      continue;

    int j = 0;
    while (j < shapes[i]->size && shapes[i]->points[j].x >= 0)
      ++j;

    if (j == shapes[i]->size)
    {
      Shape *t = shapes[top];

      shapes[top] = shapes[i];
      shapes[i] = t;

      ++top;
    }
  }

  return top;
}

void destroy(Shape **shapes, int N)
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < shapes[i]->size; j++)
      free(shapes[i]->points + j);

    free(shapes[i]);
  }

  free(shapes);
}

void computeLongest(Shape **shapes, int N)
{
  for (int i = 0; i < N; ++i)
  {
    double max = 0;

    for (int j = 0; j < shapes[i]->size; ++j)
      for (int k = j; k < shapes[i]->size; ++k)
      {
        double d = distanceSq(shapes[i]->points[j], shapes[i]->points[k]);

        if (d > max)
        {
          max = d;
        }
      }

    shapes[i]->maxDiagonal = max;
  }
}

void sort(Shape **shapes, int N)
{
  if (N == 1)
    return;

  int max = shapes[N - 1]->maxDiagonal;

  for (int i = 0; i < N - 1; ++i)
    if (shapes[i]->maxDiagonal > shapes[max]->maxDiagonal)
      max = i;

  {
    Shape *t = shapes[N - 1];
    shapes[N - 1] = shapes[max];
    shapes[max] = t;
  }

  sort(shapes, N - 1);
}

int main(void)
{
  int N, K;

  cin >> N >> K;

  Shape **shapes = read(N);

  int n = filter(shapes, N);

  if (n == 0)
  {
    cerr << "Они все по правую сторону от Ox или у них меньше 4х сторон" << endl;
    exit(EXIT_FAILURE);
  }

  computeLongest(shapes, n);

  sort(shapes, n);

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < shapes[i]->size; j++)
      cout << shapes[i]->points[j].x << ' ' << shapes[i]->points[j].y << ' ';

    cout << endl;
  }

  // destroy(shapes, N);
}
