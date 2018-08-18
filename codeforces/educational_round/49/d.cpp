#include <bits/stdc++.h>
using namespace std;
int n;
int c[200005],a[200005];
int deg[200005];
int vis[200005];
int mi=1e9;
void dfs(int u){
  vis[u]=1;
  int v=a[u];
  if (vis[v])return;
  mi=min(c[v],mi);
  dfs(v);
}
int main(){
  scanf("%d",&n);
  long long ans=0;
  for (int i=1;i<=n;i++)scanf("%d",&c[i]);
  for (int i=1;i<=n;i++){
    scanf("%d",&a[i]);
    deg[a[i]]++;
  }
  queue<int>q;
  for (int i=1;i<=n;i++){
    if (deg[i]==0)q.push(i);
  }
  while (!q.empty()){
    int u=q.front();q.pop();
    vis[u]=1;
    int v=a[u];
    deg[v]--;
    if (deg[v]==0)q.push(v);
  }
  for (int i=1;i<=n;i++)if (!vis[i]) {
    if (i==a[i]){
      ans+=(long long)c[i];
      vis[i]=1;
    }
  } 
  for (int i=1;i<=n;i++){
    if (!vis[i]){
      mi=c[i];
      dfs(i);
      ans+=(long long)mi;
    }
  }
  cout<<ans<<endl;
}
