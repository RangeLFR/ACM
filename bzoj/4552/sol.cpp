#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int N = 100005;
int n, m, k, a[N], ask[N][3];
struct seg{
    int l, r, val, lazy;
}t[4*N];
bool bz[4*N];
 
void mark(int o, int l, int r, int val) {
    t[o].val = val?0:(r-l+1);
    t[o].lazy = val;
    bz[o] = 1;
}
 
void pushdown(int o, int l, int r) {
    int mid = (l+r)/2;
    if (bz[o]) {
        mark(o*2, l, mid, t[o].lazy);
        mark(o*2+1, mid+1, r, t[o].lazy);
        bz[o] = 0;
    }
}
 
void update(int o, int l, int r, int L, int R, int val) {
    int mid = (l+r)/2;
    if (L > R)return ;
    if (l == L && r == R) {
        mark(o, l, r, val);
        return ;
    }
    pushdown(o, l, r);
    if (R <= mid) update(o*2, l, mid, L, R, val);
    else if (L > mid) update(o*2+1, mid+1, r, L, R,val);
    else update(o*2, l, mid, L, mid, val), update(o*2+1, mid+1, r, mid+1, R, val);
    t[o].val = t[o*2].val+t[o*2+1].val;
}
 
int query(int o, int l, int r, int L, int R) {
    if (l == L && r == R) return t[o].val;
    pushdown(o, l, r);
    int mid = (l+r)/2;
    if (R <= mid) return query(o*2, l, mid, L, R);
    else if (L > mid) return query(o*2+1, mid+1, r, L, R);
    else return query(o*2, l, mid, L, mid)+query(o*2+1, mid+1, r, mid+1, R);
}
 
bool check(int x) {
    for (int i = 1; i <= n; i++) 
        if (a[i] < x) update(1, 1, n, i, i, 0); 
        else update(1, 1, n, i, i, 1);
    for (int i = 1; i <= m; i++) {
        int o = ask[i][0], l = ask[i][1], r = ask[i][2];
        int tmp = query(1, 1, n, l, r);
        if (o == 0) {
            update(1, 1, n, l, l+tmp-1, 0);
            update(1, 1, n, l+tmp, r, 1);
        } else {
            update(1, 1, n, l, r-tmp, 1);
            update(1, 1, n, r-tmp+1, r, 0);
        }
    }
    return !query(1, 1, n, k, k);
}
 
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a+i);
    for (int i = 1; i <= m; i++) scanf("%d%d%d", &ask[i][0], &ask[i][1], &ask[i][2]);
    scanf("%d", &k);
    int l = 1, r = n;
    while (l < r) {
        int mid = (l+r+1)/2;
        if (check(mid)) l = mid;
        else r = mid-1;
    }
    printf("%d\n", l);
    return 0;
}
