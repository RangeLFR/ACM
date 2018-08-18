#include <bits/stdc++.h>
using namespace std;
int T,n;
char s[105];
int main(){
  scanf("%d",&T);
  while (T--){
    bool flag=true;
    scanf("%d",&n);
    scanf("%s",s);
    for (int i=0;i<n;i++){
      int j=n-i-1;
      if (s[i]==s[j]||abs(s[i]-s[j])==2)continue;
      flag=false;
    }
    if (flag)puts("YES");
    else puts("NO");
  }
}
