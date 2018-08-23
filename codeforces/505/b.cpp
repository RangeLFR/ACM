#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int a[150005],b[150005];
vector<int>v;
int used[150005];
void divide(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            v.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        } 
    }
    if (n > 1) {
        v.push_back(n);
    }
}
int main(){
  scanf("%d",&n);
  for (int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]);
  bool flag=false;
  divide(a[1]);divide(b[1]);
  for (int i=2;i<=n;i++){
    int sig=0;
    for (int j=0;j<v.size();j++){
      if (!used[j]&&(a[i]%v[j]==0||b[i]%v[j]==0)){
        sig=1;
      } else {
        used[j]=1;
      }
    }
    if (sig==0) {puts("-1");return 0;}
  }
  for (int j=0;j<v.size();j++){
    if (!used[j]){
      printf("%d\n",v[j]);
      return 0;
    }
  }
}
