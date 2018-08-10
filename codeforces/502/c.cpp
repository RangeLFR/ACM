#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  int num = (int)sqrt(n);
  int res = n % num;
  for (int i = n - res + 1; i <= n; i++) printf("%d ", i);
  n -= res;
  int tot = n / num;
  //printf("%d\n", tot);
  //printf("%d\n", n);
  for (int i = 0; i < num; i++) {
    for (int j = n-tot+1; j <= n; j++) printf("%d ", j);
    n -= tot;
  }
}