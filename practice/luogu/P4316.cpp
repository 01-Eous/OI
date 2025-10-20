#include<bits/extc++.h>
using namespace std;
typedef double ld;
typedef pair<int,int> pii;
const int maxn = 1e5 + 5;
int n,m;
ld dp[maxn];
int in[maxn],cnt[maxn];
vector<pii> g[maxn];
void topsort()
{
    queue<int> q;
    dp[n] = 0;
    q.push(n);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto &[v,w] : g[u])
        {
            dp[v] += ld(dp[u] + w) / cnt[v];
            if (!--in[v])
                q.push(v);
        }
    }
}
signed main()
{
    scanf("%d%d",&n,&m);
    int u,v,w;
    while (m--)
    {
        cin >> u >> v >> w;
        in[u]++,cnt[u]++;
        g[v].push_back({u,w});
    }
    topsort();
    printf("%.2lf",dp[1]);
    return 0;
}