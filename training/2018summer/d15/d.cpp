/*QYitong1smyBOSS*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, k, pos[105], sign[105];
char s[10];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= k; i++) {
    scanf("%s", s);
    if (s[0] == 'u') {
      scanf("%s", s);
      int step = 0;
      for (int j = 0; j < strlen(s); j++) step = step * 10 + s[j] - '0';
      int cnt = 0, o = i-1;
      while (cnt < step) {
        if (!sign[o]) 
          {
            cnt++;
            sign[o] = 1;
          }
        o--;
      }
      pos[i] = pos[o];
      sign[i] = 1;
    } else {
      int step = 0;
      if (s[0] != '-') {
        for (int j = 0; j < strlen(s); j++) {
          step = step * 10 + s[j] - '0';
        }
      } else {
        for (int j = 1; j < strlen(s); j++) {
          step = step * 10 + s[j] - '0';
        }
        step = -step;
      }
      //printf("%d: %d\n", i, step);
      pos[i] = pos[i-1] + step;
      while (pos[i] < 0) pos[i] += n;
      pos[i] %= n;
    }
    //printf("%d: %d\n", i, pos[i]);
  }
  printf("%d\n", pos[k]);
}