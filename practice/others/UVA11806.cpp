#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e6 + 7;
int n,m,k;
int c[505][505];
void init(int n = 500)
{
    c[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
}
void solve(int t)
{
    scanf("%lld%lld%lld",&n,&m,&k);
    int ans = 0;
    for (int i = 0; i < 16; i++)
    {
        int x = n,y = m,cnt = 0;
        if (i & 1)
            x--,cnt++;
        if (i & 2)
            x--,cnt++;
        if (i & 4)
            y--,cnt++;
        if (i & 8)
            y--,cnt++;
        ans = (ans + (cnt & 1 ? -1 : 1) * c[x * y][k] % mod + mod) % mod;
    }
    printf("Case %lld: %lld\n",t,ans);
}
signed main()
{
    init();
    int t;
    scanf("%lld",&t);
    for (int i = 1; i <= t; i++)
        solve(i);
    return 0;
}