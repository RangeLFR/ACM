#include <bits/stdc++.h>
using namespace std;
int T,n;
int a[1000005],cnt[10005];
struct Ans{
  int s,p;
  int l1,l2;
  int emp;
}ans;
struct Seg{
  int l,num;
  bool operator <(const Seg&rhs)const {
    return l<rhs.l;
  }
}s[10005];
int main(){
  scanf("%d",&T);
  while (T--){
    memset(cnt,0,sizeof(cnt));
    ans.emp=0;
    scanf("%d",&n);
    int mx=0;
    for (int i=1;i<=n;i++){
      scanf("%d",&a[i]);
      cnt[a[i]]++;
      mx=max(mx,a[i]);
    }
    int tot=0;
    for (int i=1;i<=mx;i++)if (cnt[i]>=2){
      tot++;
      s[tot].l=i;
      s[tot].num=cnt[i];
    }
    sort(s+1,s+1+tot);
    //printf("%d %d\n",s[1].l,s[1].num);
    bool flag=false;
    for (int i=1;i<=tot;i++){
      if (s[i].num>=4){
        //printf("%d\n",i);
        printf("%d %d %d %d\n",s[i].l,s[i].l,s[i].l,s[i].l);
        flag=true;
        break;
      }
      if (i==tot)break;
      int j=i+1;
      if (!ans.emp){
        ans.s=s[i].l*s[j].l;
        ans.p=2*(s[i].l+s[j].l);
        ans.l1=s[i].l;
        ans.l2=s[j].l;
        ans.emp=1;
      } else {
        int ss=s[i].l*s[j].l;
        int p=2*(s[i].l+s[j].l);
        if ((long long)ans.p*(long long)ans.p*(long long)ss>=(long long)ans.s*(long long)p*(long long)p){
          ans.s=ss;ans.p=p;
          ans.l1=s[i].l;ans.l2=s[j].l;
        }
      }
    }
    if (!flag)printf("%d %d %d %d\n",ans.l1,ans.l1,ans.l2,ans.l2);
  }
}
