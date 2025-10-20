#include<bits/extc++.h>
#define int long long
using namespace std;
using ull = unsigned int;
const int maxn = 2e5 + 5;
mt19937 rnd(random_device{}());
int n,idx;
ull hsh[maxn],base,tot;
int head[maxn],a[maxn],buc[maxn],cnt[maxn];
set<ull> st;
vector<int> ans;
struct edge{int v,nxt;}e[maxn << 1];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void dfs1(int u,int fa)
{
    hsh[u] = 0;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa)
            continue;
        dfs1(v,u);
        hsh[u] += hsh[v] * base;
    }
    hsh[u]++;
}
void dfs2(int u,int fa)
{
    hsh[u] += hsh[fa] * base;
    if (st.find(hsh[u] - tot) != st.end())
        cnt[u]++;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa)
            continue;
        hsh[u] -= hsh[v] * base;
        dfs2(v,u);
        hsh[u] += hsh[v] * base;
    }
    hsh[u] -= hsh[fa] * base;
}
void solve()
{
    base = (ull)n + rnd();
    memset(buc,0,sizeof(int) * (n + 5));
    for (int i = 1; i < n; i++)
        buc[a[i]]++;
    st.clear(),tot = 0;
    ull val = 1;
    for (int i = 0; i < n; i++)
    {
        st.insert(val);
        tot += buc[i] * val;
        val *= base;
    }
    dfs1(1,0),dfs2(1,0);
}
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i < n; i++)
        scanf("%lld",a + i);
    for (int i = 1,u,v; i < n; i++)
    {
        scanf("%lld%lld",&u,&v);
        adde(u,v),adde(v,u);
    }
    #pragma GCC unroll 10
    for (int i = 1; i <= 10; i++)
        solve();
    for (int i = 1; i <= n; i++)
        if (cnt[i] == 10)
            ans.push_back(i);
    printf("%llu\n",ans.size());
    for (auto i : ans)
        printf("%lld ",i);
    return 0;
}