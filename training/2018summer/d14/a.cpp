#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;
long long v[10005];
int tot = 0;
long long qpow(long long a, int b) {
  long long res = 1;
  while (b) {
    if (b & 1) res *= a;
    a*=a;
    b>>=1;
  }
  return res;
}
void Init() {
  for (int a = 0; a <= 32; a++) {
    if (qpow(2, a) < 1000000005) {
      for (int b = 0; b <= 32; b++) {
        if (qpow(2, a) * qpow(3, b) < 1000000005) {
          for (int c = 0; c <= 32; c++) {
            if (qpow(2, a) * qpow(3, b) * qpow(5, c) < 1000000005) {
              for (int d = 0; d <= 32; d++) {
                if (qpow(2, a) * qpow(3, b) * qpow(5, c) * qpow(7, d) < 1000000005) {
                  tot++;
                  v[tot] = qpow(2, a) * qpow(3, b) * qpow(5, c) * qpow(7, d);
                  //printf("%lld\n", v[tot]);
                } else break;
              }
            } else break;
          }
        } else break;
      }
    } else break;
  }
  //printf("%d\n", tot);
  sort(v+1, v+1+tot);
}
int main() {
  int T; cin >> T;
  Init();
  //for (int i = 1; i <= 5; i++) printf("%lld\n", v[i]);
  while (T--) {
    long long n;
    scanf("%lld", &n);
    int pos = lower_bound(v+1, v+tot+1, n) - v;
    printf("%lld\n", v[pos]);
  }
}