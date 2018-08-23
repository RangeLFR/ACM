#include <bits/stdc++.h>
using namespace std;
int n;
int a[9] = {0,1,2,1,2,3,4,3,2};
int query(int x) {
  printf("? %d\n", x);fflush(stdout);
  int t; scanf("%d", &t); return t;
  //return a[x];
}
int main() {
  scanf("%d", &n);
  if (n % 4 != 0) {
    printf("! -1\n");
    fflush(stdout);
    return 0;
  }
  int x = query(1), y = query(1+n/2);
  int l = 1, r = n / 2;
  for (int i = 1; i <= 30; i++) {
    int mid = (l + r) / 2;
    int nx = query(mid), ny = query(mid+n/2);
    if (nx == ny) {
      printf("! %d\n", mid);
      fflush(stdout);
      return 0;
    }
    if ((nx < ny) == (x < y)) l = mid+1;
    else r = mid - 1;
  }
}

