#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
const int maxn = 1e4 + 5;
int n,idx;
bool vis[maxn];
int pr[maxn],mu[maxn],cnt[maxn];
void init(int n = 1e4)
{
    mu[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            pr[++idx] = i;
            mu[i] = -1;
        }
        for (int j = 1; j <= idx && i * pr[j] <= n; j++)
        {
            vis[i * pr[j]] = 1;
            if (i % pr[j] == 0)
                break;
            mu[i * pr[j]] = -mu[i];
        }
    }
}
int c(int n,int m)
{
    if (n < m)
        return 0;
    int res = 1;
    for (int i = 0; i < m; i++)
        res *= n - i;
    for (int i = 1; i <= m; i++)
        res /= i;
    return res;
}
void solve()
{
    memset(cnt,0,sizeof(cnt));
    for (int i = 1,x; i <= n; i++)
    {
        scanf("%lld",&x);
        for (int j = 1; j * j <= x; j++)
        {
            if (x % j)
                continue;
            cnt[j]++;
            if (x / j != j)
                cnt[x / j]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= 1e4; i++)
        if (mu[i])
            ans += mu[i] * c(cnt[i],4);
    printf("%lld\n",ans);
}
signed main()
{
    init();
    while (scanf("%lld",&n) != EOF)
        solve();
    return 0;
}