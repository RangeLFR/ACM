#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[105], b[105], sumc, sumr;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    sumr ^= a[i];
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &b[i]);
    sumc ^= b[i];
  }
  if (sumc != sumr) puts("NO");
  else {
    puts("YES");
    int sum = 0;
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) printf("0 ");
      printf("%d\n", a[i]);
      sum ^= a[i];
    }
    for (int j = 1; j < m; j++) printf("%d ", b[j]);
    printf("%d\n", sum ^ b[m]);
  }
}