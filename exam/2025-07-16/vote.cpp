#include<bits/extc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
bool st;
int n,m;
int fac[5005],inv[5005];
int dp[5005][5005],f[5005][5005],a[5005][5005];
int c[5005],t[5005],num[5005],len[5005],sum[5005];
bool ed;
int binpow(int x,int y)
{
    int res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1)
            res = (ll)res * x % mod;
        x = (ll)x * x % mod;
    }
    return res;
}
void init()
{
    fac[0] = 1;
    for (int i = 0; i < n; i++)
        fac[i + 1] = (ll)fac[i] * (i + 1) % mod;
    inv[n] = binpow(fac[n],mod - 2);
    for (int i = n; i > 0; i--)
        inv[i - 1] = (ll)inv[i] * i % mod;
}
int C(int n,int m){return n < 0 || m < 0 || n < m ? 0 : (ll)fac[n] * inv[m] % mod * inv[n - m] % mod;}
void calc(int id)
{
    f[0][0] = 1;
    for (int i = 1; i <= len[id]; i++)
        memset(f[i],0,sizeof(int) * (len[id] + 5));
    for (int i = 1; i <= len[id]; i++)
        for (int j = 0; j <= len[id]; j++)
            for (int k = 0; k <= min(j,a[id][i]); k++)
                f[i][j] = (f[i][j] + (ll)f[i - 1][j - k] * inv[a[id][i] - k] % mod * C(len[id] - j + k,k)) % mod;
}
signed main()
{
    freopen("vote.in","r",stdin);
    freopen("vote.out","w",stdout);
    scanf("%d",&n);
    init();
    for (int i = 1; i <= n; i++)
        scanf("%d",c + i);
    for (int i = 1; i <= n; i++)
        scanf("%d",t + i),num[i] = t[i];
    sort(num + 1,num + n + 1);
    m = unique(num + 1,num + n + 1) - num - 1;
    for (int i = 1; i <= n; i++)
    {
        t[i] = lower_bound(num + 1,num + m + 1,t[i]) - num;
        a[t[i]][++len[t[i]]] = c[i];
        sum[t[i]] += c[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++)
    {
        calc(i);
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= min(j,len[i]); k++)
                dp[i][j] = (dp[i][j] + (ll)dp[i - 1][j - k] * f[len[i]][k]) % mod;
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
        ans = (ans + (ll)(i & 1 ? -1 : 1) * fac[n - i] * dp[m][i] % mod + mod) % mod;
    printf("%d",ans);
    return 0;
}