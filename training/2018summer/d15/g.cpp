/*QYitong1smyBOSS*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[105], amount[105], f[150][150];
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  amount[0] = m;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) amount[i] = amount[i-1]*2/3;
  f[1][1] = min(amount[0], a[1]);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= n; j++) {
      if (j) f[i+1][j-1] = max(f[i+1][j-1], f[i][j]);
      f[i+1][j+1] = max(f[i+1][j+1], f[i][j] + min(amount[j], a[i+1]));
      f[i+2][0] = max(f[i+2][0], f[i][j]);
      f[i+2][j] = max(f[i+2][j], f[i][j] + min(amount[j], a[i+1]));
      if (j) f[i+2][j-1] = max(f[i+2][j-1], f[i][j]);
    }
  }
  int ans = 0; for (int j = 0; j <= n; j++) {
    ans = max(ans, f[n][j]);
  }
  cout << ans << endl;
}