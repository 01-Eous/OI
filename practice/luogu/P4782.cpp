#include<bits/extc++.h>
using namespace std;
const int maxn = 2e6 + 5;
int n,m,idx,cnt,tim;
bool vis[maxn];
int head[maxn],dfn[maxn],low[maxn],bel[maxn];
stack<int,vector<int>> stk;
struct edge{int v,nxt;}e[maxn << 1];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void dfs(int u)
{
    vis[u] = 1,stk.push(u);
    dfn[u] = low[u] = ++tim;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (!dfn[v])
        {
            dfs(v);
            low[u] = min(low[u],low[v]);
        }
        else if (vis[v])
            low[u] = min(low[u],dfn[v]);
    }
    if (low[u] == dfn[u])
    {
        ++cnt;
        do {
            bel[u] = cnt;
            u = stk.top();
            stk.pop();
            vis[u] = 0;
        } while (low[u] != dfn[u]);
    }
}
signed main()
{
    scanf("%d%d",&n,&m);
    while (m--)
    {
        int i,j,a,b;
        scanf("%d%d%d%d",&i,&a,&j,&b);
        adde(i + a * n,j + (b ^ 1) * n);
        adde(j + b * n,i + (a ^ 1) * n);
    }
    for (int i = 1; i <= n << 1; i++)
        if (!dfn[i])
            dfs(i);
    for (int i = 1; i <= n; i++)
        if (bel[i] == bel[i + n])
            return puts("IMPOSSIBLE"),0;
    puts("POSSIBLE");
    for (int i = 1; i <= n; i++)
        printf("%d ",(int)(bel[i] < bel[i + n]));
    return 0;
}