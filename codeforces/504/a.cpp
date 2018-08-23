#include <bits/stdc++.h>
using namespace std;
char s[200005],t[200005];
int n,m;
int has;
int main(){
  scanf("%d%d",&n,&m);
  scanf("%s%s",s,t);
  if (m<n-1){puts("NO");return 0;}
  bool flag=true;
  for (int i=0;i<n;i++){
    if (s[i]=='*'){has=1;break;}
    if (s[i]!=t[i]){
      flag=false;
      break;
    }
  }
  if (!flag){puts("NO");return 0;}
  if (!has&&m!=n){puts("NO");return 0;}
  for (int i=n-1,j=m-1;s[i]!='*'&&i>=0&&j>=0;i--,j--){
    if (s[i]!=t[j]){
      flag=false;
      break;
    }
  }
  if (!flag)puts("NO");
  else puts("YES");
}
