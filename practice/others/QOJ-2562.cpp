#include<bits/extc++.h>
#define int long long
using namespace std;
int n,m,L,R,idx;
int a[1005],head[5005];
vector<int> dp[5005][55],tmp[55];
struct edge{int v,nxt;}e[10005];
void init()
{
    memset(head,0,sizeof(int) * (n + 5));
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j].clear();
}
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
vector<int> process(vector<int> vec)
{
    sort(vec.begin(),vec.end());
    vector<int> res;
    for (auto i : vec)
    {
        while (res.size() >= 2 && i - res[res.size() - 2] <= R - L + 1)
            res.pop_back();
        res.push_back(i);
    }
    return res;

}
void dfs(int u,int fa)
{
    dp[u][0].push_back(a[u]);
    for (int _ = head[u]; _; _ = e[_].nxt)
    {
        int v = e[_].v;
        if (v == fa)
            continue;
        dfs(v,u);
        for (int i = 0; i <= m; i++)
            tmp[i].clear();
        for (int i = 0; i <= m; i++)
            for (auto x : dp[u][i])
                for (int j = 0; i + j + 1 <= m; j++)
                    for (auto y : dp[v][j])
                        if (L <= y && y <= R)
                            {tmp[i + j + 1].push_back(x);break;}
        for (int i = 0; i <= m; i++)
            for (auto x : dp[u][i])
                for (int j = 0; i + j <= m; j++)
                    for (auto y : dp[v][j])
                        if (x + y <= R)
                            tmp[i + j].push_back(x + y);
        for (int i = 0; i <= m; i++)
            dp[u][i] = process(tmp[i]);
    }
}
void solve()
{
    cin >> n >> m >> L >> R,init();
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1,u,v; i < n; i++)
    {
        cin >> u >> v;
        adde(u,v),adde(v,u);
    }
    dfs(1,0);
    for (int i = 0; i <= m; i++)
    {
        bool ans = 0;
        for (auto j : dp[1][i])
        {
            if (L <= j && j <= R)
            {
                ans = 1;
                break;
            }
        }
        cout << ans;
    }
    cout << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}