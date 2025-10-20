#include<bits/extc++.h>
#define int long long
using namespace std;
int n,m;
int a[355],cnt[6];
int dp[45][45][45][45];
int calc(int c1,int c2,int c3,int c4){return 1 + c1 * 1 + c2 * 2 + c3 * 3 + c4 * 4;}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1,x; i <= m; i++)
    {
        cin >> x;
        cnt[x]++;
    }
    dp[0][0][0][0] = a[1];
    for (int c1 = 0; c1 <= cnt[1]; c1++)
    {
        for (int c2 = 0; c2 <= cnt[2]; c2++)
        {
            for (int c3 = 0; c3 <= cnt[3]; c3++)
            {
                for (int c4 = 0; c4 <= cnt[4]; c4++)
                {
                    int pos = calc(c1,c2,c3,c4);
                    if (c1)
                        dp[c1][c2][c3][c4] = max(dp[c1][c2][c3][c4],dp[c1 - 1][c2][c3][c4] + a[pos]);
                    if (c2)
                        dp[c1][c2][c3][c4] = max(dp[c1][c2][c3][c4],dp[c1][c2 - 1][c3][c4] + a[pos]);
                    if (c3)
                        dp[c1][c2][c3][c4] = max(dp[c1][c2][c3][c4],dp[c1][c2][c3 - 1][c4] + a[pos]);
                    if (c4)
                        dp[c1][c2][c3][c4] = max(dp[c1][c2][c3][c4],dp[c1][c2][c3][c4 - 1] + a[pos]);
                }
            }
        }
    }
    cout << dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]];
    return 0;
}