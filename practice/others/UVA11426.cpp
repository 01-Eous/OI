#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 4e6 + 5;
int n;
bool ipr[maxn];
int pr[maxn],phi[maxn],sum[maxn];
void init(int n = 4e6)
{
    for (int i = 2; i <= n; i++)
    {
        if (!ipr[i])
        {
            pr[++pr[0]] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= pr[0] && i * pr[j] <= n; j++)
        {
            ipr[i * pr[j]] = 1;
            if (i % pr[j] == 0)
            {
                phi[i * pr[j]] = phi[i] * pr[j];
                break;
            }
            phi[i * pr[j]] = phi[i] * (pr[j] - 1);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        phi[i] += phi[i - 1];
        sum[i] = sum[i - 1] + i;
    }
}
void solve()
{
    int ans = 0;
    for (int l = 1,r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        ans += phi[n / l] * (sum[r] - sum[l - 1]);
    }
    printf("%lld\n",ans);
}
signed main()
{
    init();
    scanf("%lld",&n);
    while (n)
    {
        solve();
        scanf("%lld",&n);
    }
    return 0;
}