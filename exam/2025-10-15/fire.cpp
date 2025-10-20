#include<bits/extc++.h>
#define int long long
#define inv(x) binpow(x,mod - 2)
using namespace std;
const int mod = 1e9 + 7,inv100 = 570000004;
const int maxn = 2e5 + 5;
int n,m;
int a[maxn];
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
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] = a[i] * inv100 % mod;
    }
    int l = 1,r = 0,val = 1,cnt1 = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        while (r < n && r + 1 <= i + m)
        {
            r++;
            if (a[r] != 1)
                val = val * (1 - a[r] + mod) % mod;
            else
                cnt1++;
        }
        while (l < i - m)
        {
            if (a[l] != 1)
                val = val * inv(1 - a[l] + mod) % mod;
            else
                cnt1--;
            l++;
        }
        ans = (ans + (cnt1 ? 1 : (1 - val + mod))) % mod;
    }
    cout << ans << '\n';
    return 0;
}