#include<bits/extc++.h>
#define int long long
#define ls tree[rt].lson
#define rs tree[rt].rson
using namespace std;
using pii = pair<int,int>;
const int maxn = 4e5 + 5;
int n,m,k,cnt1,cnt2;
bool vis[maxn << 1];
int root[maxn],s[maxn],pos[maxn],dis[maxn << 1];
unordered_map<int,int> g[maxn];
priority_queue<pii,vector<pii>,greater<>> q;
struct Nahida
{
    bool ban;
    int v,w,lson,rson;
}tree[maxn << 6];
struct Klee
{
    bool ban;
    int id,fail;
    unordered_map<int,int> ch;
}ac[maxn << 2];
void ins(int len)
{
    int rt = 0;
    for (int i = 1; i <= len; i++)
    {
        int dig = s[i];
        if (ac[rt].ch.find(dig) == ac[rt].ch.end())
        {
            ac[rt].ch[dig] = ++cnt1;
            ac[cnt1].id = s[i];
        }
        rt = ac[rt].ch[dig];
    }
    ac[rt].ban = 1;
}
int clone(int rt)
{
    tree[++cnt2] = tree[rt];
    return cnt2;
}
int upd(int x,int v,int w,int l,int r,int rt)
{
    rt = clone(rt);
    if (l == r)
    {
        tree[rt].v = v;
        tree[rt].w = w;
        return rt;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        ls = upd(x,v,w,l,mid,ls);
    else
        rs = upd(x,v,w,mid + 1,r,rs);
    return rt;
}
int que(int x,int l,int r,int rt)
{
    if (l == r)
        return tree[rt].v;
    int mid = (l + r) >> 1;
    if (x <= mid)
        return que(x,l,mid,ls);
    else
        return que(x,mid + 1,r,rs);
}
void get_fail()
{
    queue<int> q;
    for (auto [x,y] : ac[0].ch)
        q.push(y);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        ac[u].ban |= ac[ac[u].fail].ban;
        root[u] = root[ac[u].fail];
        if (!ac[u].fail)
            for (auto [v,w] : g[ac[u].id])
                root[u] = upd(v,pos[v],w,1,n,root[u]);
        for (auto [x,y] : ac[u].ch)
            if (g[ac[u].id].find(x) != g[ac[u].id].end())
                root[u] = upd(x,y,g[ac[u].id][x],1,n,root[u]);
        for (auto [x,y] : ac[u].ch)
        {
            ac[y].fail = que(x,1,n,root[ac[u].fail]);
            if (!ac[y].fail)
                ac[y].fail = pos[x];
            q.push(y);
        }
    }
}
void solve(int u,int l,int r,int rt)
{
    if (tree[rt].ban)
        return;
    tree[rt].ban = 1;   
    if (l == r)
    {
        int v = tree[rt].v;
        if (!ac[v].ban && !vis[v])
        {
            if (dis[v] > dis[u] + tree[rt].w)
            {
                dis[v] = dis[u] + tree[rt].w;
                q.push({dis[v],v});
            }
        }
        return;
    }
    int mid = (l + r) >> 1;
    if (ls)
        solve(u,l,mid,ls);
    if (rs)
        solve(u,mid + 1,r,rs);
}
void dij()
{
    memset(dis,0x3f,sizeof(dis));
    if (ac[pos[1]].ban)
        return ;
    dis[pos[1]] = 0;
    q.push({0,pos[1]});
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if (ac[u].id == n)
        {
            printf("%lld",dis[u]);
            exit(0);
        }
        if (vis[u])
            continue;
        vis[u] = 1;
        solve(u,1,n,root[u]);
    }
}
signed main()
{
    scanf("%lld%lld%lld",&n,&m,&k);
    int u,v,w,p;
    while (m--)
    {
        scanf("%lld%lld%lld",&u,&v,&w);
        g[u][v] = w;
    }
    while (k--)
    {
        scanf("%lld",&p);
        for (int i = 1; i <= p; i++)
            scanf("%lld",s + i);
        ins(p);
    }
    for (int i = 1; i <= n; i++)
    {
        if (ac[0].ch.find(i) == ac[0].ch.end())
        {
            ac[0].ch[i] = ++cnt1;
            ac[cnt1].id = i;
        }
        pos[i] = ac[0].ch[i];
    }
    get_fail(),dij();
    printf("-1");
    return 0;
}