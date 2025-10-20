#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 666623333;
int l,r,idx;
bool vis[maxn];
int pr[maxn],phi[maxn],val[maxn];
void init(int n = 1e6)
{
    vis[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
            pr[++idx] = i;
        for (int j = 1; j <= idx && i * pr[j] <= n; j++)
        {
            vis[i * pr[j]] = 1;
            if (i % pr[j] == 0)
                break;
        }
    }
    for (int i = 0; i <= r - l; i++)
        phi[i] = val[i] = l + i;
    for (int i = 1; i <= idx; i++)
    {
        for (int j = (pr[i] - l % pr[i]) % pr[i]; j <= r - l; j += pr[i])
        {
            phi[j] = phi[j] / pr[i] * (pr[i] - 1);
            while (val[j] % pr[i] == 0)
                val[j] /= pr[i];
        }
    }
    for (int i = 0; i <= r - l; i++)
        if (val[i] > 1)
            phi[i] = phi[i] / val[i] * (val[i] - 1);
}
signed main()
{
    scanf("%lld%lld",&l,&r);
    init();
    int ans = 0;
    for (int i = l; i <= r; i++)
        ans = (ans + i - phi[i - l]) % mod;
    printf("%lld",ans);
    return 0;
}