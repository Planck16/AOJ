#include <bits/stdc++.h>
using namespace std;

struct Point{
  double x, y;

  Point(double a, double b) {
    x = a;
    y = b;
  }

  void pointprint() {
    printf("%.5f %.5f\n", x, y);
  }
};

// theta = pi / 3 [rad]
const double th = M_PI /3;

void koch(int n, Point p1, Point p2) {
  if (n == 0) return;

  Point s((2 * p1.x + p2.x) / 3, (2 * p1.y + p2.y) / 3);
  Point t((p1.x + 2 * p2.x) / 3, (p1.y + 2 * p2.y) / 3);

  double ux, uy;
  ux = cos(th) * (t.x - s.x) + sin(th) * (s.y - t.y) + s.x;
  uy = cos(th) * (t.y - s.y) + sin(th) * (t.x - s.x) + s.y;
  Point u(ux, uy);

  koch(n-1, p1, s);
  s.pointprint();
  koch(n-1, s, u);
  u.pointprint();
  koch(n-1, u, t);
  t.pointprint();
  koch(n-1, t, p2);
}

int main() {
  int n;
  cin >> n;

  Point p1(0, 0);
  Point p2(100, 0);

  p1.pointprint();

  koch(n, p1, p2);

  p2.pointprint();
  return 0;
}