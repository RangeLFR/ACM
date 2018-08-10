#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define maxn 100005
struct point1{
    int x;
    int y;
}point[maxn];
int ans[maxn];
int n;
bool cmp_x(const point1& a, const point1& b)
{
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
int c[maxn];
int lowbit(int a)
{
    return a&(-a);
  }
  int sum(int x)
  {
      int s = 0;
      while(x > 0){
          s += c[x];
          x -= x&-x;
      }
      return s;
  }
  void add(int i, int x)
  {
      while(i<=32005)
    {
        c[i] += x;
        i += i&-i;
    }
}

int main()
{
    //memset(c,0,sizeof(c));
    //memset(ans,0,sizeof(ans));
    scanf("%d", &n);
    for(int i = 1; i<=n; i++)
        {
          scanf("%d%d", &point[i].x, &point[i].y);
          point[i].x ++;
          point[i].y ++;
        }

    sort(point+1, point+n+1, cmp_x);
    for(int i = 1; i<=n; i++)
    {
        int Rank = 0;
        Rank = sum(point[i].y);
        add(point[i].y, 1);
        ans[Rank]++; 
    }
    for(int i = 0; i<n; i++)
        printf("%d\n", ans[i]);
    return 0;
}