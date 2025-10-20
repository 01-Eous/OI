#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 376544743;
const int maxn = 1e7 + 5;
int n,m;
int pr[maxn];
int calc(int x)
{
    int k = m / x;
    return (k * (k + 1) >> 1) % mod * x % mod;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> pr[i];
    int ans = 0;
    if (n * m <= 10000000)
    {
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i % pr[j] == 0)
                {
                    ans = (ans + i) % mod;
                    break;
                }
            }
        }
        goto Hoshino;
    }
    for (int s = 1; s < 1 << n; s++)
    {
        int cnt = 0,val = 1;
        bool fl = 0;
        for (int i = 0; i < n; i++)
        {
            if (s >> i & 1)
            {
                cnt++,val *= pr[i];
                if (val > m)
                {
                    fl = 1;
                    break;
                }
            }
        }
        if (fl)
            continue;
        ans = (ans + (cnt & 1 ? 1 : -1) * calc(val) + mod) % mod;
    }
    Hoshino:
    cout << ans << '\n';
    return 0;
}