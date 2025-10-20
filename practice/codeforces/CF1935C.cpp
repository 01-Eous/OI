#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,l;
int dp[2005][2005],pre[2005][2005];
struct Nahida{int a,b;}a[2005];
bool operator<(const Nahida &x,const Nahida &y){return x.b < y.b;}
void solve()
{
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
        cin >> a[i].a >> a[i].b;
    sort(a + 1,a + n + 1);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = pre[i][j] = inf;
    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = a[i].a;
        pre[i][1] = min(pre[i - 1][1],dp[i][1] - a[i].b);
    }
    for (int j = 2; j <= n; j++)
    {
        for (int i = j; i <= n; i++)
        {
            dp[i][j] = min(dp[i][j],pre[i - 1][j - 1] + a[i].b + a[i].a);
            pre[i][j] = min(pre[i - 1][j],dp[i][j] - a[i].b); 
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            if (dp[i][j] <= l)
                ans = max(ans,j);
    cout << ans << '\n';
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