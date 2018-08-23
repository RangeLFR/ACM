#include <bits/stdc++.h>
using namespace std;
const int N=1e6+4;
struct node
{
    friend bool operator< (node x,node y)
    {
        if(x.pos==y.pos)return x.r<y.r;
        return x.l<y.l;
    }
    int l,r,id;
    int pos;
};
node qu[N];
int n,m,k;
int b[N],num[2*N];
long long ans[N];
void solve()
{
    memset(num,0,sizeof(num));
    int le=1,ri=0;
    long long temp=0;
    for(int i=1;i<=m;i++)
    {
        while(ri<qu[i].r)
        {
            ri++;
            temp+=num[b[ri]^k];//num[]数组是当前le到ri内每个b[i](le<=i<=ri)异或一个要添加的数==k的数目;所以num[b[ri]^k]就是在已有的区间上再加一个
            num[b[ri]]++;//ri前能和ri异或==k的数目;后面这些操作一样
        }
        while(ri>qu[i].r)
        {
            num[b[ri]]--;
            temp-=num[b[ri]^k];
            ri--;
        }
        while(le>qu[i].l-1)
        {
            le--;
            temp+=num[b[le]^k];
            num[b[le]]++;
        }
        while(le<qu[i].l-1)
        {
            num[b[le]]--;
            temp-=num[b[le]^k];
            le++;
        }
        ans[qu[i].id]=temp;
    }
}
int main()
{
    b[0]=0;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        b[i]^=b[i-1];
    }
    int s=sqrt(n);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&qu[i].l,&qu[i].r);
        qu[i].id=i;
        qu[i].pos=qu[i].l/s;
    }
    sort(qu+1,qu+m+1);
    solve();
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<"\n";
    }
    return 0;
}
