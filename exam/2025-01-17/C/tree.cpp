#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
int n,ed,tot;
bool vis[maxn];
vector<int>g[maxn];
void dfs(int u,int len)
{
    if (u == ed)
    {
        fill(vis + 1,vis + n + 1,1);
        tot = len;
        return;
    }
    for (auto v : g[u])
    {
        if (vis[v])
            continue;
        vis[v] = 1;
        dfs(v,len + 1);
    }
}
inline int binpow(int x,int y)
{
    int ret = 1;
    while (y)
    {
        if (y & 1)
            ret = ret * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ret;
}
signed main()
{
    // freopen("ex_tree3.in","r",stdin);
    // freopen("ex_tree3.out","w",stdout);
    scanf("%lld",&n);
    for (int i = 1,u,v; i < n; i++)
    {
        scanf("%lld%lld",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (n <= 10)
    {
        int ans = 0;
        for (int k = 0; k < (1 << n); k++)
        {
            int _max = 0;
            for (int i = 1; i <= n; i++)
            {
                for (int j = i + 1; j <= n; j++)
                {
                    if (((k >> (i - 1)) & 1) != ((k >> (j - 1)) & 1))
                        continue;
                    fill(vis + 1,vis + n + 1,0);
                    vis[i] = 1;
                    ed = j;
                    dfs(i,0);
                    _max = max(_max,tot);
                }
            }
            ans = (ans + _max) % mod;
        }
        printf("%lld",ans);
    }
    else if (g[1].size() == n - 1)
        printf("%lld",binpow(2,n + 1));
    else
        printf("40pts足矣");
    return 0;
}