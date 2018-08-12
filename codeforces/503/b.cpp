#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
using namespace std;
int n, p[1005];
int ans[1005], cnt[1005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
  for (int i = 1; i <= n; i++) {
    memset(cnt, 0, sizeof(cnt));
    int j = i;
    while (true) {
      cnt[j]++;
      if (cnt[j] == 2) break;
      j = p[j];
    }
    ans[i] = j;
  }
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
}
