#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#define ll long long
using namespace std;
char s[1000005];
double ans[1000005];
void Init() {
  double sum = 1.0;
  ans[1] = sum;
  for (int i = 2; i <= 1000004; i++) {
    ans[i] = sum + 1.0/(double)i/(double)i;
    sum = ans[i];
  }
}
int main() {
  Init();
  //for (int i = 1; i <= 1000004; i++) printf("%.5f\n", ans[i]);
  while (scanf("%s", s) != EOF) {
    if (strlen(s) > 6) printf("1.64493\n");
    else {
      int n = 0, sz = strlen(s);
      for (int i = 0; i < sz; i++) {
        n = n * 10 + s[i]-'0';
      }
      printf("%.5f\n", ans[n]);
    }
  }
}