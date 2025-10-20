#include<bits/extc++.h>
#define int long long
using namespace std;
typedef unsigned long long ull;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int base = 97;
int n;
int cnt[55],cnt0,_max;
int a[maxn];
int fac[maxn];
__gnu_pbds::gp_hash_table<ull,int>dp;
void init(int up = 1e5)
{
    fac[0] = 1;
    for (int i = 1; i <= up; i++)
        fac[i] = fac[i - 1] * i % mod;
}
inline ull hsh()
{
    ull ret = 0;
    for (int i = 50; i >= 0; i--)
        ret = ret * base + cnt[i];
    return ret;
}
int dfs(int sum,int stp)
{
    if (!stp)   
        return 1;
    if (sum >= _max)
        return fac[stp];
    ull hs = hsh();
    int ret = 0;
    if (dp.find(hs) != dp.end())
        return dp[hs];
    for (int i = 1; i <= sum; i++)
    {
        if (cnt[i])
        {
            cnt[i]--;
            ret = (ret + (cnt[i] + 1) * dfs(min(_max,sum + i),stp - 1) % mod) % mod;
            cnt[i]++;
        }
    }
    return dp[hs] = ret;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    cin >> n >> a[0];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
        cnt0 += (a[i] == 0);
        _max = max(_max,a[i]);
    }
    int ans = dfs(a[0],n - cnt0);
    for (int i = n; i > n - cnt0; i--)
        ans = ans * i % mod;
    cout << ans;
    return 0;
}