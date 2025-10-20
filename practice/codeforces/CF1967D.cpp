#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 1e6 + 5;
int n,m,tim,cnt;
int a[maxn],b[maxn];
int dep[maxn],bel[maxn],dfn[maxn],ed[maxn];
int in[maxn],rnk[maxn],id[maxn],cir[maxn],len[maxn];
vector<int> g1[maxn],g2[maxn];// g1 是内向，g2 是外向
void init()
{
    for (int i = 1; i <= m; i++)
        g1[i].clear(),g2[i].clear();
    cnt = 0;
    memset(in,0,sizeof(int) * (m + 5));
    memset(id,0,sizeof(int) * (m + 5));
    memset(dep,0,sizeof(int) * (m + 5));
    memset(bel,0,sizeof(int) * (m + 5));
    memset(rnk,0,sizeof(int) * (m + 5));
    memset(len,0,sizeof(int) * (m + 5));
}
void topsort()
{
    queue<int> q;
    for (int i = 1; i <= m; i++)
        if (!in[i])
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : g1[u])
            if (!--in[v])
                q.push(v);
    }
}
void find(int u)
{
    id[u] = cnt;
    cir[len[cnt]++] = u;
    for (auto v : g1[u])
    {
        if (!in[v] || id[v])
            continue;
        rnk[v] = rnk[u] + 1;
        find(v);
    }
}
void dfs(int u,int fa,int root)
{
    bel[u] = root,dep[u] = dep[fa] + 1;
    dfn[u] = ++tim;
    for (auto v : g2[u])
        if (v != fa && !id[v])
            dfs(v,u,root);
    ed[u] = tim;
}
int dis(int s,int t)
{
    if (id[bel[s]] == id[bel[t]])// 必须在同一联通块内
    {
        if (id[t])// t 在环上
            return dep[s] - 1 + (rnk[t] - rnk[bel[s]] + len[id[t]]) % len[id[t]];
        else if (bel[s] == bel[t] && dfn[t] <= dfn[s] && dfn[s] <= ed[t])// t 是 s 的祖先
            return dep[s] - dep[t];
        else
            return inf;
    }
    else
        return inf;
}
bool chk(int mid)
{
    int lst = 1;
    for (int i = 1; i <= n; i++)
    {
        while (lst <= m && dis(a[i],lst) > mid)
            lst++;
        if (lst > m)
            return 0;
    }
    return 1;
}
void solve()
{
    scanf("%d%d",&n,&m),init();
    for (int i = 1; i <= n; i++)
        scanf("%d",a + i);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d",b + i),in[b[i]]++;
        g1[i].push_back(b[i]);
        g2[b[i]].push_back(i);
    }
    topsort();
    for (int i = 1; i <= m; i++)
    {
        if (!in[i] || id[i])
            continue;
        cnt++,find(i);
        for (int j = 0; j < len[cnt]; j++)
            tim = 0,dfs(cir[j],0,cir[j]);
    }
    int l = 0,r = m,mid,ans = -1;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (chk(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    printf("%d\n",ans);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}