#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main() {
  //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int last = m;
  for (int i = 1; i <= n; i++) {
    if (a[i] < last) {
      last -= a[i];
      printf("0 ");
    } else {
      a[i] -= last;
      printf("%d ", a[i] / m + 1);
      last = m - a[i] % m;
    }    
  }
}