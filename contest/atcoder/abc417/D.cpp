#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e4 + 5;
int n,m;
int dp[maxn][1005];
int p[maxn],a[maxn],b[maxn],sum[maxn];
int dfs(int i,int j)
{
    int &res = dp[i][j];
    if (~res)
        return res;
    if (j <= p[i])
        res = dfs(i + 1,j + a[i]);
    else
        res = dfs(i + 1,max(0LL,j - b[i]));
    return res;
}
int bin(int x)
{
    int l = 0,r = n,mid,res = -1;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (x - sum[mid] <= 1000)
        {
            res = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i] >> a[i] >> b[i];
        sum[i] = sum[i - 1] + b[i];        
    }
    memset(dp,0xff,sizeof(dp));
    // dp[i][j] 表示第i个还没取的答案
    for (int i = 0; i <= 1000; i++)
        dp[n + 1][i] = i;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= 1000; j++)
            dfs(i,j);
    cin >> m;
    int x,pos;
    while (m--)
    {
        cin >> x,pos = bin(x);
        if (~pos)
            cout << dp[pos + 1][x - sum[pos]] << '\n';
        else
            cout << x - sum[n] << '\n';
    }
    return 0;
}