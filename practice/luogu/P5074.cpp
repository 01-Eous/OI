#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1 << 12 | 5;
int n,m;
bool mp;
void solve()
{
    cin >> n >> m;
    int up = 1 << (m + 1);
    vector<int>dp0(up,0),dp1(up,0);
    dp1[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mp;
            dp0 = dp1;
            fill(dp1.begin(),dp1.end(),0);
            for (int s = 0; s < up; s++)
            {
                if (dp0[s])
                {
                    int x = (s >> j) & 1,y = (s >> (j + 1)) & 1;
                    if (mp)
                    {
                        if (x == y)
                            dp1[s ^ (0b11 << j)] += dp0[s];
                        else
                        {
                            dp1[s] += dp0[s];
                            dp1[s ^ (0b11 << j)] += dp0[s];
                        }
                    }
                    else if (!x && !y)
                        dp1[s] += dp0[s];
                }
            }
        }
        dp0 = dp1;
        fill(dp1.begin(),dp1.end(),0);
        for (int s = 0; s < (1 << m); s++)
            dp1[s << 1] = dp0[s];
    }
    cout << dp1[0] << '\n';
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