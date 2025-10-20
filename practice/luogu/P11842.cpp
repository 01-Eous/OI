#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 2e5 + 5;
int n,cnt,top;
bool vis[maxn],instk[maxn],inloop[maxn];
int a[maxn],c[maxn],stk[maxn];
int dp1[maxn][2],dp2[maxn][2];
vector<int> g[maxn],cir[maxn];
void dfs1(int u)
{
    vis[u] = instk[u] = 1;
    stk[++top] = u;
    for (auto v : g[u])
    {
        if (!vis[v])
            dfs1(v);
        else if (instk[v])
        {
            int lst = 0,t = top;
            cnt++;
            while (lst != v)
            {
                lst = stk[t--];
                cir[cnt].push_back(lst);
                instk[lst] = 0;
                inloop[lst] = 1;
            }
        }
    }
    top--,instk[u] = 0;
}
void dfs2(int u)
{
    dp1[u][1] = c[u];
    for (auto v : g[u])
    {
        if (inloop[v])
            continue;
        dfs2(v);
        dp1[u][0] += dp1[v][1];
        dp1[u][1] += min(dp1[v][0],dp1[v][1]);
    }
}
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        g[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        scanf("%lld",c + i);
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs1(i);
    int ans = 0;
    for (int i = 1; i <= cnt; i++)
    {
        for (auto u : cir[i])
            dfs2(u);
        if (cir[i].size() == 1)
        {
            ans += min(dp1[cir[i][0]][0],dp1[cir[i][0]][1] - c[cir[i][0]]);
            continue;
        }
        for (auto u : cir[i])
        {
            dp2[u][0] = dp1[u][0];
            dp2[u][1] = dp1[u][1];
        }
        // 钦定 cir[i][0] 不选
        dp2[cir[i][0]][1] = inf;
        for (int j = 1; j < cir[i].size(); j++)
        {
            dp2[cir[i][j]][0] += dp2[cir[i][j - 1]][1];
            dp2[cir[i][j]][1] += min(dp2[cir[i][j - 1]][0],dp2[cir[i][j - 1]][1]);
        }
        int tmp = dp2[cir[i][cir[i].size() - 1]][1];
        for (auto u : cir[i])
        {
            dp2[u][0] = dp1[u][0];
            dp2[u][1] = dp1[u][1];
        }
        // 钦定 cir[i][0] 选
        dp2[cir[i][0]][0] = inf;
        for (int j = 1; j < cir[i].size(); j++)
        {
            dp2[cir[i][j]][0] += dp2[cir[i][j - 1]][1];
            dp2[cir[i][j]][1] += min(dp2[cir[i][j - 1]][0],dp2[cir[i][j - 1]][1]);
        }
        ans += min({tmp,dp2[cir[i][cir[i].size() - 1]][0],dp2[cir[i][cir[i].size() - 1]][1]});
    }
    printf("%lld",ans);
    return 0;
}