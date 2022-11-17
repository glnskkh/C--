#include <cmath>
#include <iostream>

using namespace std;

double distance(double x1, double y1, double x2, double y2) {
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double cosAngle(double x1, double y1, double x2, double y2, double x3,
                double y3, double d1, double d2) {
  double p = (x1 - x2) * (x3 - x2) + (y1 - y2) * (y3 - y2);

  return p / (d1 * d2);
}

int main(void) {
  int n;

  cin >> n;

  if (n < 3) {
    cerr << "Углов нет" << endl;
    exit(EXIT_FAILURE);
  }

  double P[n][2];

  for (int i = 0; i < n; ++i)
    cin >> P[i][0] >> P[i][1];

  double Max[3][2];
  double minCos = 2;

  double d1, d2, cosA;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j)
        continue;

      double d1 = distance(P[i][0], P[i][1], P[j][0], P[j][1]);
      for (int k = 0; k < n; ++k) {
        if (k == j || k == i)
          continue;

        double d2 = distance(P[k][0], P[k][1], P[j][0], P[j][1]);

        cosA = cosAngle(P[i][0], P[i][1], P[j][0], P[j][1], P[k][0], P[k][0],
                        d1, d2);

        if (cosA < minCos) {
          minCos = cosA;
          Max[0][0] = P[i][0];
          Max[0][1] = P[i][1];
          Max[1][0] = P[j][0];
          Max[1][1] = P[j][1];
          Max[2][0] = P[k][0];
          Max[2][1] = P[k][1];
        }
      }
    }
  }

  double *start = (double *)Max;

  for (int i = 0; i < 6; ++i)
    cout << *(start++) << " ";

  cout << endl;

  cout << acos(minCos) << endl;

  exit(EXIT_SUCCESS);
}