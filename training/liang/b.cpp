#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <cmath>
#define ll long long
using namespace std;
struct Point {
  double x, y;
  Point (double x = 0, double y =  0) : x(x), y(y) {}
  friend bool operator < (const Point& a, const Point& b) {
      return a.x < b.x || (a.x==b.x && a.y < b.y);
  }
};
typedef Point Vector;
Vector operator + (Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }
Vector operator - (Vector A, Vector B) { return Vector(A.x - B.x, A.y - B.y); }
Vector operator * (Vector A, double p) { return Vector(A.x * p, A.y * p); }
Vector operator / (Vector A, double p) { return Vector(A.x / p, A.y / p); }
const double eps = 1e-10;
const double pi = acos(-1.0);
int dcmp(double x) {
  if (fabs(x) < eps) return 0;
  else return x < 0 ? -1 : 1;
}
bool operator == (const Point& A, const Point& B) {
  return dcmp(A.x - B.x) == 0 && dcmp(A.y - B.y) == 0;
}
double dot(Vector A, Vector B) { return A.x*B.x + A.y*B.y; }
double length(Vector A) { return sqrt(dot(A, A)); }
double angle(Vector A, Vector B) { return acos(dot(A, B) / length(A) / length(B)); }
double cross(Vector A, Vector B) { return A.x*B.y - A.y*B.x; }
Vector rotate(Vector A, double rad) {
  return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad));
}
int ConvexHull(Point* p, int n, Point* ch) {
  int m = 1;
  ch[0] = p[1];
  for (int i = 2; i <= n; i++) {
    while (m > 1 && dcmp(cross()))
  }
  /*sort(p, p+n);
  int m = 0;
  for (int i = 0; i < n; i++) {
      while (m > 1 && dcmp(cross(ch[m-1]-ch[m-2], p[i]-ch[m-2])) <= 0) m--;
      ch[m++] = p[i];
  }
  int k = m;
  for (int i = n-2; i >= 0; i--) {
      while (m > k && dcmp(cross(ch[m-1]-ch[m-2], p[i]-ch[m-2])) <= 0) m--;
      ch[m++] = p[i];
  }
  if (n > 1) m--;
  return m;*/
}
Point p[600005], ch[600005];
int tot, n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    double a; scanf("%lf", &a);
    p[i].x = (double)i, p[i].y= a;
  }
  int m = ConvexHull(p, n, ch);
  
}