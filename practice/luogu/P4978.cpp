#include<bits/extc++.h>
#define int long long
#define inv(x) binpow(x,mod - 2)
using namespace std;
const int mod = 998244353;
int n,m;
int a[2005],b[2005];
int binpow(int x,int y)
{
    int res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        b[i] += b[i - 1];
    }
    vector<int>sa,sb;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            sa.push_back(a[i] - a[j - 1]);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= i; j++)
            sb.push_back(b[i] - b[j - 1]);
    sort(sa.begin(),sa.end());
    sort(sb.begin(),sb.end());
    int p = 0,ans = 0;
    for (auto i : sa)
    {
        while (p < sb.size() && sb[p] < i)
            p++;
        ans = (ans + p) % mod;
    }
    cout << ans * inv(sa.size()) % mod * inv(sb.size()) % mod;
    return 0;
}