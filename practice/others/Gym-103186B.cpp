#include<bits/extc++.h>
#define int long long
#define chkmax(x,y) (x = max(x,y))
using namespace std;
int n,num[3];
int dp[5005][5005];
struct Nahida
{
    int a,b,c;
    friend bool operator<(const Nahida &x,const Nahida &y){return x.b - x.a > y.b - y.a;}
}a[5005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> num[0] >> num[1] >> num[2];
    for (int i = 1; i <= n; i++)
        cin >> a[i].a >> a[i].b >> a[i].c;
    sort(a + 1,a + n + 1);
    memset(dp,~0x3f,sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= min(i,num[2]); j++)
        {
            if (j)
                chkmax(dp[i][j],dp[i - 1][j - 1] + a[i].c);
            if (i - j <= num[1])
                chkmax(dp[i][j],dp[i - 1][j] + a[i].b);
            else
                chkmax(dp[i][j],dp[i - 1][j] + a[i].a);
        }
    }
    cout << dp[n][num[2]];
    return 0;
}