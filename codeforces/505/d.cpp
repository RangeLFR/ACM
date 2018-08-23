#include <bits/stdc++.h>
using namespace std;
int n,a[1000];
int f[1005][1005][2];
int g[1000][1000];
int gcd(int a,int b){
  if (b==0)return a;
  return gcd(b,a%b);
}
int main(){
  scanf("%d",&n);
  for (int i=1;i<=n;i++)scanf("%d",&a[i]);
  for (int i=1;i<=n;i++){
    for (int j=1;j<=n;j++){
      g[i][j]=gcd(a[i],a[j]);
    }
  }
  for (int i=1;i<=n;i++){
    if (i>1)f[i][i][0]=(gcd(a[i],a[i-1])>1);
    if (i<n)f[i][i][1]=(gcd(a[i],a[i+1])>1);
    g[i][0]=g[0][i]=g[i][n+1]=g[n+1][i]=a[i];
  }
  for (int len=2;len<=n;len++){
    for (int i=1;i<=n-len+1;i++){
      int j=i+len-1;
      for (int k=i;k<=j;k++){
        if (k==i){
          if (!f[i][j][1])f[i][j][1]=f[i+1][j][0]&&(g[i][j+1]>1);
          if (!f[i][j][0])f[i][j][0]=f[i+1][j][0]&&(g[i][i-1]>1);
        }
        else if (k==j){
          if (!f[i][j][1])f[i][j][1]=f[i][j-1][1]&&(g[j][j+1]>1);
          if (!f[i][j][0])f[i][j][0]=f[i][j-1][1]&&(g[i-1][j]>1);
        }
        else {
          if (!f[i][j][1])f[i][j][1]=f[i][k-1][1]&&f[k+1][j][0]&&(g[k][j+1]>1);
          if (!f[i][j][0])f[i][j][0]=f[i][k-1][1]&&f[k+1][j][0]&&(g[i-1][k]>1);
        }
      }
    }
  }
  //printf("%d\n",f[1][5][1]);
  //printf("%d\n",f[7][9][0]);
  //printf("%d %d\n",f[8][8][0],f[7][8][1]);
  if (f[1][n][1]||f[1][n][0])puts("Yes");
  else puts("No");
}
