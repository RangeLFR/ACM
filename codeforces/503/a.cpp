#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
using namespace std;
int n, h, a, b, k;
int ta, fa, tb, fb;
int main() {
  scanf("%d%d%d%d%d", &n, &h, &a, &b, &k);
  while (k--) {
    scanf("%d %d %d %d", &ta, &fa, &tb, &fb);
    long long ans = 0;
    if (ta == tb) ans = (long long)abs(fa - fb);
    else {
      if (fa < a) {
        ans += (long long)(a-fa);
        fa = a;
      } 
      else if (fa > b) {
        ans += (long long)(fa - b);
        fa = b;
      }
      ans += (long long)abs(tb - ta) + (long long)abs(fb - fa);
    }
    printf("%I64d\n", ans);
  }
}
