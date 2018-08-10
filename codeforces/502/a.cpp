#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
using namespace std;
int n, a, b, c, d;
int sum1, sum;
int main() {
  cin >> n;
  int ans = 0;
  for (int i =1; i <= n; i++) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (i == 1) sum1 = a+b+c+d;
    else {
      sum = a+b+c+d;
      if (sum > sum1) ans++;
    }
  }
  printf("%d\n", ans+1);
}