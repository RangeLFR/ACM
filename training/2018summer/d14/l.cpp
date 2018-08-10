#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;
const double pi = acos(-1.0), eps = 1e-10;
int r, R;
bool check(double A, double mid) {
  double sum1 = 0.0, sum2 = 0.0;
  sum1 = sin(A/2.0) + sin(mid/2.0) + sin(A/2.0 + mid/2.0);
  sum2 = sin(A) + sin(mid) - sin(A + mid);
  if (2 * sum1 / sum2 - (double)R/(double)r < eps) return true;
  return false;
}
int main() {
  while (scanf("%d%d", &r, &R) != EOF) {
    if (r * 2 > R) {
      puts("NO Solution!");
      continue;
    }
    double a, b, c, A, B;
    A = 2.0*pi/3.0;
    double left = 0.0, right = 4.0*pi/3.0;
    for (int i = 1; i <= 100; i++) {
      double mid = (left + right) / 2.0;
      if (check(A, mid)) left = mid;
      else right = mid;
    }
    B = left;
    a = 2.0 * R * sin(A/2.0);
    b = 2.0 * R * sin(B/2.0);
    c = 2.0 * R * sin((A+B)/2.0);
    printf("%.18f %.18f %.18f\n", a, b, c);
  }
}