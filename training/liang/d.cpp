#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <cmath>
#define ll long long
using namespace std;
ll f[2005][11];
int n, k;
int main() {
  cin >> n >> k;
  f[1][0] = 0;
  for (int i = 1; i < k; i++) f[1][i] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < k; j++) {
      if (j) {
        for (int val = 1; val < k; val++) f[i][j] += f[i-1][val];
      } else {
        for (int val = 0; val < k; val++) f[i][j] += f[i-1][val];
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i < k; i++) ans += f[n][i];  printf("%lld\n", ans);
}