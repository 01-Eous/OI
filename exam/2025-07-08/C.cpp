#include<bits/extc++.h>
using namespace std;
using pii = pair<int,int>;
const int maxn = 4e4 + 5;
const int dir[4][2] = {1,0,-1,0,0,1,0,-1};
int n,m,idx;
int mp[maxn],in[maxn],head[maxn],dp[maxn];
vector<pii> g[maxn];
unordered_set<int> st;
struct edge{int v,nxt;}e[maxn << 2];
bool bound(int x,int y){return 1 <= x && x <= n && 1 <= y && y <= m;}
int id(int x,int y){return (x - 1) * m + y;}
void adde(int u,int v)
{
    st.insert(u),st.insert(v);
    e[++idx] = {v,head[u]};
    head[u] = idx,in[v]++;
}
void clear()
{
    while (!st.empty())
    {
        auto it = st.begin();
        in[*it] = head[*it] = 0;
        dp[*it] = 1;
        st.erase(it);
    }
}
int topsort()
{
    queue<int> q;
    for (auto i : st)
        if (!in[i])
            q.push(i),dp[i] = 1;
    int res = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        res = max(res,dp[u]);
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].v;
            dp[v] = max(dp[v],dp[u] + 1);
            if (!--in[v])
                q.push(v);
        }
    }
    return res;
}
signed main()
{
    freopen("matrix.in","r",stdin);
    freopen("matrix.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d",mp + id(i,j));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int p = 0; p < 4; p++)
            {
                int x = i + dir[p][0],y = j + dir[p][1];
                if (!bound(x,y))
                    continue;
                int u = id(i,j),v = id(x,y);
                if (mp[u] == mp[v])
                    return printf("-1"),0;
                if (mp[v] % mp[u] == 0)
                    g[mp[v] / mp[u]].push_back({u,v});
            }
        }
    }
    int ans = 1;
    for (int i = 2; i <= 4e4; i++)
    {
        for (auto [u,v] : g[i])
            adde(u,v);
        ans = max(ans,topsort());
        clear();
    }
    printf("%d\n",ans);
    return 0;
}