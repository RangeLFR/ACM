#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <vector>
#define ll long long
using namespace std;
struct Voter {
  int p, c, id;
  bool operator < (const Voter& rhs) const {
    return c < rhs.c;
  }
}v[3005];
vector <Voter> vc[3005];
ll ans = (ll)1e17;
int n, m, cnt[3005], sign[3005];
ll solve(int now, int last) {
  ll res = 0ll;
  for (int i = 1; i <= n; i++) sign[i] = 0;
  for (int i = 2; i <= m; i++) {
    if (cnt[i] < last) continue;
    int j = 0;
    while (j < min(cnt[i], cnt[i] - last + 1)) {
      res += (ll)vc[i][j].c;
      sign[vc[i][j].id] = 1;
      j++;
      now++;
    }
  }
  if (now >= last) return res;
  else {
    for (int i = 1; i <= n; i++) {
      if (sign[v[i].id] || v[i].p == 1) continue;
      if (now == last) break;
      res += v[i].c;
      sign[v[i].id] = 1;
      now++;
    }
  }
  return res;
}
int main() {
  scanf("%d %d", &n, &m);
  int mx_vote = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &v[i].p, &v[i].c);
    v[i].id = i;
    vc[v[i].p].push_back(v[i]);
    cnt[v[i].p]++;
    mx_vote = max(mx_vote, cnt[v[i].p]);
  }
  //printf("%d\n", mx_vote);
  for (int i = 1; i <= m; i++) if (vc[i].size() > 0) sort(vc[i].begin(), vc[i].end());
  sort(v+1, v+n+1);
  for (int last = cnt[1]; last <= mx_vote + 1; last++) {
    ans = min(ans, solve(cnt[1], last));
  }
  cout << ans << endl;
}
