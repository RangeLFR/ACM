#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;
ll l, r;
int main() {
  while (scanf("%lld%lld", &l, &r) != EOF) {
    if (r > 2) {
      if (l == 1) printf("%lld\n", (r-3)/2+2);
      else if (l == 0) printf("%lld\n", (r-1)/2+1);
      else {
        if (l == r || l == r-1) puts("2");
        else printf("%lld\n", (r-l-2)/2+2);
      }
    } else if (r <= 1) puts("0");
    else if (r == 2) puts("1");
  }
}