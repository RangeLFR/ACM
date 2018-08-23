#include <bits/stdc++.h>
using namespace std;
char s[200005];
int n;
int main(){
  scanf("%s",s+1);
  n=strlen(s+1);
  int ans=1;
  int Ans=1;
  for (int i=1;i<=n;i++)s[i+n]=s[i];
  for (int i=1;i<=2*n-1;i++){
    if (s[i+1]!=s[i])ans++;
    else ans=1;
    Ans=max(ans,Ans);
  }
  printf("%d\n",min(n,Ans));
}
