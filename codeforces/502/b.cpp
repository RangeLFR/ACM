#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
using namespace std;
int n;
char a[100005], b[100005];
long long cnt[2];
long long tot[2];
int main() {
  scanf("%d", &n);
  scanf("%s%s", a, b);
  for (int i = 0; i < n; i++) {
    if (b[i] == '0') {
      if (a[i] == '0') cnt[0]++;
      else cnt[1]++;
    }
    tot[a[i]-'0']++;
  }
  printf("%lld\n", cnt[0] * tot[1] + cnt[1] * tot[0] - cnt[0] * cnt[1]);
}