#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int n,m,k;
int sum[1000005],cnt[2000005],a[1000005],bl[1000005];
struct query{
  int l,r;
  int id;
  bool operator < (const query&rhs)const{
    if (bl[l]==bl[rhs.l])return r<rhs.r;
    return l<rhs.l;
  }
}q[1000005];
long long res[1000005];
int main(){
  scanf("%d%d%d",&n,&m,&k);
  int tot=(int)sqrt(n);
  for (int i=1;i<=n;i++)bl[i]=(i-1)/tot+1;
  for (int i=1;i<=n;i++)scanf("%d",&a[i]);
  for (int i=1;i<=n;i++)sum[i]=sum[i-1]^a[i];
  for (int i=1;i<=m;i++){
    scanf("%d%d",&q[i].l,&q[i].r);
    q[i].id=i;
  }
  sort(q+1,q+1+m);
  int l=1,r=0;
  long long ans=0;
  for (int i=1;i<=m;i++){
    while (r<q[i].r){
      r++;
      ans+=(long long)cnt[sum[r]^k];
      cnt[sum[r]]++;
    }
    while (r>q[i].r){
      cnt[sum[r]]--;
      ans-=(long long)cnt[sum[r]^k];
      r--;
    }
    while (l>q[i].l-1){
      l--;
      ans+=(long long)cnt[sum[l]^k];
      cnt[sum[l]]++;
    }
    while (l<q[i].l-1){
      cnt[sum[l]]--;
      ans-=(long long)cnt[sum[l]^k];
      l++;
    }
    res[q[i].id]=ans;
  }
  for (int i=1;i<=m;i++)printf("%lld\n",res[i]);
}
