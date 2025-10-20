#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
using pii = pair<int,int>;
const int maxn = 2e5 + 5;
int n,nn,idx,rt,ssiz,top,cnt;
pii vec[maxn];
bool vis[maxn];
int a[maxn],num[maxn],head[maxn],stk[maxn];
int siz[maxn],wei[maxn],tree[maxn],ans[maxn];
vector<int> son;
struct edge{int v,nxt;}e[maxn << 1];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
int lowbit(int x){return x & -x;}
void upd(int i,int x)
{
    for (; i; i -= lowbit(i))
        tree[i] = max(tree[i],x);
}
int que(int i)
{
    int res = ~inf;
    for (; i <= nn; i += lowbit(i))
        res = max(res,tree[i]);
    return res;
}
void clear(int i)
{
    for (; i; i -= lowbit(i))
        tree[i] = ~inf;
}
void dfs1(int u,int fa)
{
    wei[u] = 0,siz[u] = 1;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa || vis[v])
            continue;
        dfs1(v,u);
        siz[u] += siz[v];
        wei[u] = max(wei[u],siz[v]);
    }
    wei[u] = max(wei[u],ssiz - siz[u]);
    if (wei[u] < wei[rt])
        rt = u;
}
void dfs2(int u,int fa,int dis)
{
    vec[++cnt] = {u,dis};
    for (int i = head[u]; i; i = e[i].nxt)
        if (int v = e[i].v; v != fa && !vis[v])
            dfs2(v,u,dis + 1);
}
void calc(int u)
{
    upd(a[u],0),stk[++top] = a[u];
    for (auto v : son)
    {
        cnt = 0;
        dfs2(v,u,1);
        for (int j = 1; j <= cnt; j++)
        {
            int x = vec[j].first,dis = vec[j].second;
            ans[x] = max(ans[x],que(a[x]) + dis);
        }
        for (int j = 1; j <= cnt; j++)
        {
            stk[++top] = a[vec[j].first];
            upd(a[vec[j].first],vec[j].second);
        }
    }
    ans[u] = max(ans[u],que(a[u]));
    while (top)
        clear(stk[top--]);
}
void dfs(int u)
{
    vis[u] = 1;
    son.clear();
    for (int i = head[u]; i; i = e[i].nxt)
        if (int v = e[i].v; !vis[v])
            son.push_back(v);
    calc(u);
    reverse(son.begin(),son.end());
    calc(u);
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (vis[v])
            continue;
        rt = 0,ssiz = siz[v];
        dfs1(v,u),dfs(rt);
    }
}
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i),num[i] = a[i];
    sort(num + 1,num + n + 1);
    nn = unique(num + 1,num + n + 1) - num - 1;
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(num + 1,num + nn + 1,a[i]) - num;
    for (int i = 1,u,v; i < n; i++)
    {
        scanf("%lld%lld",&u,&v);
        adde(u,v),adde(v,u);
    }
    memset(tree,~0x3f,sizeof(int) * (nn + 5));
    wei[0] = inf;
    ssiz = n,rt = 0;
    dfs1(1,0),dfs(rt);
    for (int i = 1; i <= n; i++)
        printf("%lld ",ans[i]);
    return 0;
}