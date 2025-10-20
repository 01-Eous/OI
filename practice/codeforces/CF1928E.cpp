#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,x,y,s;
int cost(int x){return x * (x + 1) >> 1;}
void solve()
{
    cin >> n >> x >> y >> s;
    int t = x % y,st = (x - t) / y;
    if (t * n % y != s % y || t * n > s)
        return cout << "NO\n",void();
    s = (s - t * n) / y;
    vector<int> dp(s + 5,inf);
    dp[0] = 0;
    for (int i = 1; i <= s; i++)
        for (int j = 1; cost(j) <= i; j++)
            dp[i] = min(dp[i],dp[i - cost(j)] + j + 1);
    int tmp = st;
    for (int i = 1; i <= n && tmp <= s; tmp += st + i++)
    {
        if (dp[s - tmp] <= n - i)
        {
            cout << "YES\n";
            for (int j = 1; j <= i; j++)
                cout << t + y * (st + j - 1) << ' ';
            int lft = n - i;
            s -= tmp;
            while (s)
            {
                for (int j = 1; cost(j) <= s; j++)
                {
                    if (dp[s - cost(j)] + j + 1 == dp[s])
                    {
                        lft -= j + 1;
                        for (int k = 0; k <= j; k++)
                            cout << t + y * k << ' ';
                        s -= cost(j);
                        break;
                    }                
                }
            }
            while (lft--)
                cout << t << (lft ? ' ' : '\n');
            return;
        }
    }
    cout << "NO\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}