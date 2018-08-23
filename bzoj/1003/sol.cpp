#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>
using namespace std;
struct Edge {
  int u, v, nxt, w;
}e[505];
int tot, last[205];
void add(int u, int v, int w) {
  tot++;
  e[tot].u = u, e[tot].v = v, e[tot].w = w;
  e[tot].nxt = last[u]; last[u] = tot;
}
int cost[105][105];
int f[105];
int p[105], a[105], b[105];
int n, m, k, E;
int vis[25], dis[105], cant[25];
int dij(int s, int t) {
  priority_queue<pair<int, int> >q;
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= m; i++) dis[i] = 1e9;
  dis[s] = 0;
  q.push(make_pair(0, s));
  while (!q.empty()) {
    int u = q.top().second; q.pop();
    vis[u] = 1;
    for (int i = last[u]; i; i = e[i].nxt) {
      int v = e[i].v;
      if (!vis[v] && !cant[v] && dis[v] > dis[u] + e[i].w) {
        dis[v] = dis[u] + e[i].w;
        q.push(make_pair(-dis[v], v));
      }
    }
  }
  return dis[t];
}
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &E);
  for (int i = 1; i <= E; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    add(u, v, w);
    add(v, u, w);
  }
  int d; scanf("%d", &d);
  for (int i = 1; i <= d; i++) {
    scanf("%d%d%d", &p[i], &a[i], &b[i]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      memset(cant, 0, sizeof(cant));
      for (int now = 1; now <= d; now++) {
        if (cant[p[now]]) continue;
        if (b[now] < i || a[now] > j) cant[p[now]] = 0;
        else cant[p[now]] = 1;
      }
      cost[i][j] = dij(1, m);
      //printf("%d\n", cost[i][j]);
    }
  }
  memset(f, 63, sizeof(f));
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) if (cost[i][j] < 1e9) cost[i][j] *= (j-i+1);
  }
  for (int i = 1; i <= n; i++) f[i] = cost[1][i];
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      f[i] = min(f[i], f[j] + cost[j+1][i] + k);
    }
  }
  printf("%d\n", f[n]);
}
