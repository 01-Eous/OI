#include<bits/extc++.h>
#define int long long
using namespace std;
using vi = vector<int>;
const int maxn = 2e5 + 5,mod = 998244353;
int n,m,q,idx,cnt;
int dp[20][maxn],tag[20],sum[20];
int head[maxn],c[maxn],siz[maxn],son[maxn];
struct{int v,nxt;}e[maxn << 1];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
int binpow(int x,int y)
{
    int res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}
void dfs1(int u,int fa)
{
    siz[u] = 1;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa)
           continue;
        dfs1(v,u);
        siz[u] += siz[v];
        if (siz[v] > siz[son[u]])
            son[u] = v;
    }
}
vi dfs2(int u,int fa)
{
    vi res;
    if (!son[u])
    {
        dp[cnt][0] = dp[cnt][c[u]] = sum[cnt] = 1;
        res.push_back(c[u]);
        return res;
    }
    res = dfs2(son[u],u);
    int cur = cnt,nxt = ++cnt;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa || v == son[u])
            continue;
        vi vec = dfs2(v,u);
        int inv0 = binpow(dp[nxt][0],mod - 2);
        for (auto x : vec)
        {
            sum[cur] = (sum[cur] - dp[cur][x] + mod) % mod;
            dp[cur][x] = (dp[cur][x] * (dp[nxt][0] + dp[nxt][x]) % mod + dp[cur][0] * dp[nxt][x] % mod) * inv0 % mod;
            sum[cur] = (sum[cur] + dp[cur][x]) % mod;
        }
        tag[cur] = tag[cur] * dp[nxt][0] % mod * tag[nxt] % mod;
        for (auto x : vec)
            res.push_back(x),dp[nxt][x] = 0;
        dp[nxt][0] = sum[nxt] = 0,tag[nxt] = 1;
    }
    cnt--;
    dp[cur][0] = (dp[cur][0] * (m + 1) + sum[cur]) % mod;
    sort(res.begin(),res.end());
    res.erase(unique(res.begin(),res.end()),res.end());
    return res;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 2; i <= q + 1; i++)
        cin >> c[i];
    for (int i = 1,u,v; i < n; i++)
    {
        cin >> u >> v;
        adde(u,v),adde(v,u);
    }
    fill(tag,tag + 20,1);
    dfs1(1,0),dfs2(1,0);
    cout << dp[0][0] * tag[0] % mod << '\n';
    return 0;
}