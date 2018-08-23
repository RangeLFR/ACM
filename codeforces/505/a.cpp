#include <bits/stdc++.h>
using namespace std;
int cnt[26];
int n;
char s[100005];
int main(){
  scanf("%d%s",&n,s);
  if (n==1){
    puts("Yes");
    return 0;
  }
  bool flag=false;
  for (int i=0;i<n;i++){
    cnt[s[i]-'a']++;
  }
  for (int i=0;i<26;i++)if (cnt[i]>=2)flag=true;
  if (flag)puts("Yes");
  else puts("No");
}
