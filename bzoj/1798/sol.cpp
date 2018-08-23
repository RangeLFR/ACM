#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define _for(i, a, b) for(int i=(a);i<=(b);++i)
#define LL long long
using namespace std;
 
const int maxn = 100005;
int n, p, m;
int a[maxn];
struct SegTree
{
    long long ans;
    long long cp, ct;// first times, then plus.
}node[4*maxn];
 
void pushup(int o)
{
    node[o].ans = (node[o<<1].ans + node[o<<1|1].ans)%p;
}
 
void build(int o, int l, int r)
{
    node[o].cp = 0;
    node[o].ct = 1;
    if (l == r)
    {
        node[o].ans = a[l];
        return ;
    }
    int mid = (l+r)/2;
    build(o<<1, l, mid);
    build(o<<1|1, mid + 1, r);
    pushup(o);
}
 
void pushdown(int o, int l, int r)
{
    if (node[o].cp == 0 && node[o].ct == 1)
        return ;
    int mid = (l+r)/2;
    node[o<<1].ans = ((node[o<<1].ans * node[o].ct)%p + (node[o].cp)*(mid-l+1)%p)%p;
    node[o<<1|1].ans = ((node[o<<1|1].ans * node[o].ct)%p + (node[o].cp)*(r-mid)%p)%p;
    node[o<<1].ct = (node[o<<1].ct * node[o].ct)%p;
    node[o<<1].cp = ((node[o].ct*node[o<<1].cp)%p + node[o].cp)%p;
    node[o<<1|1].ct = (node[o<<1|1].ct * node[o].ct)%p;
    node[o<<1|1].cp = ((node[o].ct*node[o<<1|1].cp)%p + node[o].cp)%p;
    node[o].cp = 0;
    node[o].ct = 1;
}
 
void update(int o, int L, int R, int ct, int cp, int l, int r)
{
    if (L <= l && r <= R)
    {
        node[o].ct = (node[o].ct*ct)%p;
        node[o].cp = (node[o].cp*ct + cp)%p;
        node[o].ans = (node[o].ans * ct + (LL)(r-l+1)*cp)%p;
        return ;
    }
    pushdown(o, l, r);
    int mid = (l+r)/2;
    if (L <= mid) update(o<<1, L, R, ct, cp, l, mid);
    if (R > mid) update(o<<1|1, L, R, ct, cp, mid+1, r);
    pushup(o);
}
 
LL query(int o, int L, int R, int l, int r)
{
    LL res = 0;
    if (L <= l && r <= R)
    {
        return node[o].ans;
    }
    pushdown(o, l, r);
    int mid = (l+r)/2;
    if (L <= mid) res = (res+query(o<<1, L, R, l, mid))%p;
    if (mid < R) res = (res+query(o<<1|1, L, R, mid+1, r))%p;
    pushup(o);
    return res;
}
 
int main()
{
    scanf("%d%d", &n, &p);
    _for(i, 1, n) scanf("%d", &a[i]);
    scanf("%d", &m);
    build(1, 1, n);
    while (m--)
    {
        int L, R, c;
        int judge = 0;
        scanf("%d", &judge);
        if (judge == 1)
        {
            scanf("%d%d%d", &L, &R, &c);
            update(1, L, R, c, 0, 1, n);
        }
        if (judge == 2)
        {
            scanf("%d%d%d", &L, &R, &c);
            update(1, L, R, 1, c, 1, n);
        }
        if (judge == 3)
        {
            scanf("%d%d", &L, &R);
            printf("%lld\n", query(1, L, R, 1, n));
        }
    }
    return 0;
}
