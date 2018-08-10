#include <bits/stdc++.h>
using namespace std;
char s[1005], t[1005];
int n, m, q;
int sum[1005];
int main() {
  scanf("%d%d%d", &n, &m, &q);
  scanf("%s", s + 1); scanf("%s", t + 1);
  for (int i = 1; i <= n - m + 1; i++) {
    int j = 1;
    for (j = 1; j <= m; j++) {
      if (s[i + j - 1] != t[j]) break;
    }
    if (j == m + 1) sum[i + m - 1] = 1;
  }
  for (int i = 1; i <= n; i++) sum[i] += sum[i-1];
  //for (int i = 1; i <= n; i++) printf("%d\n", sum[i]);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (l + m - 2 > r) printf("0\n");
    else printf("%d\n", sum[r] - sum[l + m - 2]);
  }
}