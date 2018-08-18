#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
int q;
int main(){
  cin>>n>>q;
  while (q--){
    int x,y;scanf("%d%d",&x,&y);
    ll ans=0;
    if ((x+y)%2==0){
        int row=(x-1)/2,res=x%2;
        ans=n*(ll)row;
        if (res==1){
          ans+=(ll)y/2+1ll;
        } else {
          if (n%2==0){
            ans+=n/2+(ll)y/2;
          } else {
            ans+=n/2+(ll)y/2+1;
          }
        }
    } else {
      ll tmp=n*n/2;
      ll d1=tmp+n/2+(n%2),d2=tmp-n/2;
      if (x%2==1)x++;
      else x--;
      //printf("%d %d\n",x,y);
      int row=(x-1)/2,res=x%2;
      ans=n*(ll)row;
      if (res==1){
        ans+=(ll)y/2+1ll;
      } else {
        if (n%2==0){
          ans+=n/2+(ll)y/2;
        } else {
          ans+=n/2+(ll)y/2+1;
        }
      }
      //printf("%lld\n",ans);
      if (x%2==1)ans+=d1;
      else ans+=d2;
    }
    printf("%lld\n",ans);
  }
}
