#include<bits/extc++.h>
#define int long long
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
using namespace std;
const int mod = 1e9 + 7;
int n,k,inv2 = 500000004;
int fac[5005],inv[5005],siz[5005];
int dp1[5005][5005][2],dp2[5005][5005][2],tmp[5005][2];
vector<int> g[5005];
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
void init(int n = 5000)
{
    fac[0] = 1;
    for (int i = 1;i <= n; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv[n] = binpow(fac[n],mod - 2);
    for (int i = n - 1; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}
int c(int n,int m){return n < 0 || m < 0 || n < m ? 0 : fac[n] * inv[m] % mod * inv[n - m] % mod;}
void dfs(int u)
{
    dp2[u][0][0] = 1;
    for (auto v : g[u])
    {
        dfs(v);
        memset(tmp,0,sizeof tmp);
        for (int i = 0; i <= siz[u]; i++)
            for (int j = 0; j <= siz[v]; j++)
                for (int k = 0; k < 2; k++)
                    for (int x = 0; x < 2; x++)
                        tmp[i + j][k | x] = (tmp[i + j][k | x] + dp2[u][i][k] * dp1[v][j][x] % mod * c(i + j,j) % mod) % mod;
        siz[u] += siz[v];
        for (int i = 0; i <= siz[u]; i++)
        {
            dp2[u][i][0] = tmp[i][0];
            dp2[u][i][1] = tmp[i][1];
        }
    }
    for (int i = 0; i <= siz[u]; i++)
    {
        dp1[u][i][0] = (dp1[u][i][0] + dp2[u][i][0] + dp2[u][i][1]) % mod;
        dp1[u][i + 1][0] = dp2[u][i][0] * inv2 % mod;
        dp1[u][i + 1][1] = (dp2[u][i][0] * inv2 % mod + dp2[u][i][1]) % mod;
    }
    siz[u]++;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    init();
    for (int i = 2,x; i <= n; i++)
    {
        cin >> x;
        g[x].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= k; i++)
        cout << dp1[1][i][1] << '\n';
    return 0;
}