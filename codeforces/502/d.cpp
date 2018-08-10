#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
using namespace std;
int n, m, q, w[15];
char s[15];
int cnt[5005];
int sum[5000][105];
int tot2[15];
int main() {
  scanf("%d%d%d", &n, &m, &q);
  tot2[0] = 1;
  for (int i = 1; i <= 14; i++) tot2[i] = tot2[i-1] * 2;
  for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
  for (int i = 1; i <= m; i++) {
    scanf("%s", s);
    int len = strlen(s);
    int x = 0;
    for (int i = 0; i < len; i++) x = x * 2 + s[i] - '0';
    cnt[x]++;
  }
  for (int i = 0; i < tot2[n]; i++) {
    for (int j = 0; j < tot2[n]; j++) {
      int x = i ^ j;
      int tot = 0;
      for (int k = 0; k < n; k++) tot += (!((x>>k)&1))*w[n-k];
      if (tot <= 100) sum[i][tot] += cnt[j];
    }
  }
  for (int i = 0; i < tot2[n]; i++) {
    for (int j = 1; j <= 100; j++) {
      sum[i][j] += sum[i][j-1];
    }
  }
  while (q--) {
    int x = 0;
    char Q[15];
    int val;
    scanf("%s%d", Q, &val);
    for (int i = 0; i < n; i++) x = x * 2 + Q[i] - '0';
    printf("%d\n", sum[x][val]);
  }
}