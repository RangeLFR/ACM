#include <stdio.h>
#include <iostream>
using namespace std;
 
int n,m;
int row[1200][1200],col[1200][1200],xie[1200][1200];
 
struct Edge
{
    int num;
    int next;
    int len;
}edge[8000005];
int last[2000005],tot;
bool used[2000005];
long long dist[2000005];
int q[2000000],mod=2000000;
 
void Add(int i,int j,int len)
{
    tot++;
    edge[tot].num=j;
    edge[tot].next=last[i];
    edge[tot].len=len;
    last[i]=tot;
}
 
void spfa()
{
   for (int i=1;i<=2*n*m+2;i++)
        dist[i]=1e18;
    dist[2*n*m+1]=0;
    used[2*n*m+1]=1;
    q[1]=2*n*m+1;
    int start=1,ends=2;
    while (start!=ends)
        {
        int u=q[start];
        for (int k=last[u];k!=0;k=edge[k].next)
            {
            int v=edge[k].num;
            if (dist[u]+edge[k].len<dist[v])
                {
                dist[v]=dist[u]+edge[k].len;
                if (used[v]==0)
                    {
                    q[ends]=v;
                    used[v]=1;
                    ends++;
                    if (ends==mod) ends=0;
                    }
                }
            }
        used[u]=0;
        start++;
        if (start==mod) start=0;
        }
    cout << dist[2*n*m+2];
}
 
int main()
{
    scanf ("%d %d",&n,&m);
    n--, m--;
    for (int i=1;i<=n+1;i++)
        for (int j=1;j<=m;j++)
            scanf ("%d",&row[i][j]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m+1;j++)
            scanf ("%d",&col[i][j]);
 
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf ("%d",&xie[i][j]);
    if (n==0)
        {
        long long ans=1e16;
        for (int j=1;j<=m;j++)
            ans=min(ans,(long long)row[1][j]);
        cout << ans;
         return 0;
        }
 
    if (m==0)
        {
        long long ans=1e16;
        for (int i=1;i<=n;i++)
            ans=min(ans,(long long)col[i][1]);
        cout << ans;
         return 0;
        }
 
    int node=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            for (int k=1;k<=2;k++)
                {
                node++;
                if (k==1 && j==1)
                    {
                    Add(node,2*n*m+1,col[i][1]);
                    Add(2*n*m+1,node,col[i][1]);
                    }
                if (k==2 && i==1)
                    {
                    Add(node,2*n*m+2,row[1][j]);
                    Add(2*n*m+2,node,row[1][j]);
                    }
                if (k==1 && i==n)
                    {
                    Add(node,2*n*m+1,row[n+1][j]);
                    Add(2*n*m+1,node,row[n+1][j]);
                    }
                if (k==2 && j==m)
                    {
                    Add(node,2*n*m+2,col[i][m+1]);
                    Add(2*n*m+2,node,col[i][m+1]);
                    }
                if (k==1)
                    {
                    Add(node,node+1,xie[i][j]);
                    Add(node+1,node,xie[i][j]);
                    }
                if (k==2 && j!=m)
                    {
                    Add(node,node+1,col[i][j+1]);
                    Add(node+1,node,col[i][j+1]);
                    }
                if (k==1 && i!=n)
                    {
                    Add(node,node+m*2+1,row[i+1][j]);
                    Add(node+m*2+1,node,row[i+1][j]);
                    }
                }
    spfa();
}
