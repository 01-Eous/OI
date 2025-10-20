#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 4e4 + 5;
const int maxm = 2e5 + 5;
int n,m,idx,top;
int dp[maxn][205];
int h[maxn],w[maxn];
int ans[maxm],que[maxm],tmp[maxm];
struct{int l,r,t;}a[maxm];
void solve(int l,int r,int ql,int qr)
{
    if (ql > qr)
        return;
    int mid = (l + r) >> 1,qmid = ql - 1;
    for (int i = 0; i <= 200; i++)
        dp[mid][i] = 0;
    for (int i = mid + 1; i <= r; i++)
    {
        for (int j = 0; j < h[i]; j++)
            dp[i][j] = dp[i - 1][j];
        for (int j = h[i]; j <= 200; j++)
            dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - h[i]] + w[i]);
    }
    for (int i = h[mid]; i <= 200; i++)
        dp[mid][i] = w[mid];
    for (int i = mid - 1; i >= l; i--)
    {
        for (int j = 0; j < h[i]; j++)
            dp[i][j] = dp[i + 1][j];
        for (int j = h[i]; j <= 200; j++)
            dp[i][j] = max(dp[i + 1][j],dp[i + 1][j - h[i]] + w[i]);
    }
    top = 0;
    for (int i = ql; i <= qr; i++)
    {
        int x = que[i];
        if (a[x].r <= mid)
            que[++qmid] = x;
        else if (a[x].l > mid) 
            tmp[++top] = x;
        else
        {
            int res = 0;
            for (int j = 0; j <= a[x].t; j++)
                res = max(res,dp[a[x].l][j] + dp[a[x].r][a[x].t - j]);
            ans[x] = res;
        }
    }
    for (int i = 1; i <= top; i++)
        que[i + qmid] = tmp[i];
    qr = top + qmid;
    solve(l,mid,ql,qmid);
    solve(mid + 1,r,qmid + 1,qr);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].l >> a[i].r >> a[i].t;
        if (a[i].l == a[i].r)
            ans[i] = a[i].t >= h[a[i].l] ? w[a[i].l] : 0;
        else
            que[++idx] = i;
    }
    solve(1,n,1,idx);
    for (int i = 1; i <= m; i++)
        cout << ans[i] << '\n';
    return 0;
}