#include <stdio.h>
#include <algorithm>
#include <cmath>
int m, id[200005];
long long d;
long long q[200005];
int head, tail;
int main() {
  scanf("%d%lld", &m, &d);
  long long ans = 0;
  int cnt=0;
  for (int i=1;i<=m;i++){
    char s[3];
    int a;
    scanf("%s%d", s, &a);
    if (s[0]=='A'){
      long long tmp=(a+ans)%d;
      while (head<tail&&q[tail-1]<tmp)tail--;  
      q[tail]=tmp,id[tail]=cnt;
      tail++;
      cnt++;
    } else {
      int tmp=head;
      while (tmp<tail&&id[tmp]<cnt-a)tmp++;
      ans=q[tmp];
      printf("%lld\n",ans);
    }
  }
}
