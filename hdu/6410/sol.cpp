#include <stdio.h>
#include <algorithm>
#define mod 1000000007
#define ll long long
using namespace std;
int n,l[105],r[105];
ll f[105][2];
ll ksm(ll a,ll b){
  ll res=1;
  while (b){
    if (b&1)res=res*a%mod;
    a=a*a%mod;
    b>>=1;
  }
  return res;
}
ll inv(ll a){
  return ksm(a,mod-2);
}
ll calc(int high,int below,int MAX){
  high=MAX-high+1;
  below=MAX-below+1;
  return (1ll*(high+below)*(high-below+1)/2)%mod;
}
int main(){
  int T;scanf("%d",&T);
  while (T--){
    scanf("%d",&n);
    int hmin=0,hmax=0;
    for (int i=1;i<=n;i++){
      scanf("%d%d",&l[i],&r[i]);
      hmin=max(hmin,l[i]);
      hmax=max(hmax,r[i]);
    }
    ll ans=0ll;
    for (int h=hmin;h<=hmax;h++){
      if (r[1]<h){
        f[1][0]=calc(l[1],r[1],h);
        f[1][1]=0;
      } else {
        f[1][0]=calc(l[1],h-1,h);
        f[1][1]=1;
      }
      for (int i=2;i<=n;i++){
        if (r[i]<h){
          f[i][0]=f[i-1][0]*calc(l[i],r[i],h)%mod;
          f[i][1]=f[i-1][1]*calc(l[i],r[i],h)%mod;
        } else {
          f[i][0]=f[i-1][0]*calc(l[i],h-1,h)%mod;
          f[i][1]=(f[i-1][0]+f[i-1][1]*calc(l[i],h,h))%mod;
        }
      }
      ans=(ans+f[n][1])%mod;
    }
    for (int i=1;i<=n;i++){
      ans=ans*inv((ll)r[i]-l[i]+1)%mod;
    }
    printf("%lld\n",ans);
  }
}
