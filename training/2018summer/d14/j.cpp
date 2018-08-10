#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define ll long long
using namespace std;
struct Edge {
  int u, v, flow, nxt;
}e[20005];
int tot = 1, last[1005], n, m, deep[1005];
void add(int u, int v, int w) {
  ++tot;
  e[tot].u = u;
  e[tot].v = v; e[tot].flow = w, e[tot].nxt = last[u];
  last[u] = tot;
}
bool bfs(int S, int T) {
  memset(deep, 0, (tot+2) << 2);
  deep[S] = 1;
  queue <int> q;
  q.push(S);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int i = last[u]; i; i = e[i].nxt) {
      if (e[i].flow && !deep[e[i].v]) {
        deep[e[i].v] = deep[u] + 1;
        q.push(e[i].v);
      }
    }
  }
  return deep[T];
}
int aim;
int dfs(int now, int flow) {
  if (now == aim) return flow;
  int f = 0;
  for (int i = last[now]; i && flow; i = e[i].nxt) {
    int v = e[i].v;
    if (e[i].flow && deep[v] == deep[now] + 1) {
      int x = dfs(v, min(flow, e[i].flow));
      e[i].flow -= x; e[i^1].flow += x; flow -= x; f += x;
    }
  }
  if (!f) deep[now] = -2;
  return f;
}
int maxflow(int S, int T) {
  aim = T; int ret = 0;
  while (bfs(S, T)) ret += dfs(S, 1<<30);
  return ret;
}
Edge e1[20005];
int sz = 1, last1[1005], dis[1005], vis[1005], mark[20005];
void add1(int u, int v, int w) {
  sz++;
  e1[sz].u = u;
  e1[sz].flow = w; e1[sz].v = v; e1[sz].nxt = last1[u]; last1[u] = sz;
}
int main() {
  int T; scanf("%d", &T);
  while (T--) {
    memset(mark, 0, sizeof(mark));
    scanf("%d%d", &n, &m);
    sz = tot = 1;
    memset(last, 0, sizeof(last));
    memset(last1, 0, sizeof(last1));
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= m; i++) {
      int a, b, c; scanf("%d%d%d", &a, &b, &c);
      add1(a, b, c);
      add1(b, a, c);
    }
    queue <int> q;
    while (!q.empty()) q.pop();
    dis[1] = 0;
    q.push(1);
    vis[1] = 1;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (int i = last1[u]; i; i = e1[i].nxt) {
        int v = e1[i].v;
        if (!vis[v]) {
          dis[v] = dis[u] + 1;
          q.push(v);
          vis[v] = 1;
        }
      }
    }
    for (int u = 1; u <= n; u++) {
      for (int i = last1[u]; i; i = e1[i].nxt) {
        int v = e1[i].v;
        if (dis[v] == dis[u] + 1) {
          add(u, v, e1[i].flow);
          add(v, u, 0);
        }
      }
    }
    printf("%d\n", maxflow(1, n));
  }
}