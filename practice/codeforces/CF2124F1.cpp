#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n,m;
bool mp[105][105];
int dp1[105],dp2[105][105];
int read()
{
    int x = 0,f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = x * 10 + (ch ^ 48); ch = getchar();}
    return x * f;
}
bool chk(int st,int len,int val)
{
    for (int i = 1; i <= len; i++)
    {
        if (mp[st + i][val])
            return 0;
        val = val % len + 1;
    }
    return 1;
}
void solve()
{
    n = read(),m = read();
    memset(dp1,0,sizeof(int) * (n + 5));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            mp[i][j] = 0,dp2[i][j] = 0;
    while (m--)
        mp[read()][read()] = 1;
    dp1[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int s = 1; s <= i; s++)
        {
            for (int r = 1; r <= s; r++)
            {
                if (!chk(i - s,s,r))
                    continue;
                dp1[i] = (dp1[i] + dp1[i - s]) % mod;
                if (r == 1)
                {
                    dp2[i][s] = (dp2[i][s] + dp1[i - s]) % mod;
                    dp1[i] = (dp1[i] - dp2[i - s][s + 1] + mod) % mod;
                }
            }
        }
        for (int j = i; j >= 1; j--)
            dp2[i][j] = (dp2[i][j] + dp2[i][j + 1]) % mod;
    }
    printf("%lld\n",dp1[n]);
}
signed main()
{
    int t = read();
    while (t--)
        solve();
    return 0;
}