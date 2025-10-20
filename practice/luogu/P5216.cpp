#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
const int maxn = 1e5 + 5;
int n;
int fac[maxn],ifa[maxn];
int apr[maxn],cnt[maxn];
void init()
{
    fac[0] = 1;
    for (int i = 0; i < n; i++)
        fac[i + 1] = fac[i] * (i + 1) % mod;
    ifa[n + 1] = 1;
    for (int i = n; i > 0; i--)
        ifa[i] = ifa[i + 1] * i % mod;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    init();
    int ans = 0;
    for (int i = 1,x; i <= n; i++)
        cin >> x,apr[x]++;
    for (int i = 1; i <= 1e5; i++)
    {
        if (!apr[i])
            continue;
        for (int j = i; j <= 1e5; j += i)
            cnt[j] += apr[i];
        ans = (ans + i * apr[i] % mod * fac[cnt[i] - 1] % mod * ifa[cnt[i] + 1]) % mod;
    }
    cout << ans;
    return 0;
}