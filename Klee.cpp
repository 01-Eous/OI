#include <bits/extc++.h>
using namespace std;
#define int long long

constexpr int MAXN = 4e4 + 5, MAXM = 2e5 + 5;
int n, m, h[MAXN], w[MAXN], dp[MAXN][205], que[MAXM], tmp[MAXM], top, ans[MAXM];
struct Query
{
    int l, r, t;
    void init()
    {
        cin >> l >> r >> t;
    }
} b[MAXM];
inline void solve(int l, int r, int L, int R)
{
    if (L > R)
        return;
    int mid = (l + r) >> 1, M = L - 1;
    for (int i = 0; i <= 200; i++)
        dp[mid][i] = 0;
    for (int i = mid + 1; i <= r; i++)
    {
        for (int j = 0; j < h[i]; j++)
            dp[i][j] = dp[i - 1][j];
        for (int j = h[i]; j <= 200; j++)
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - h[i]] + w[i]);
    }
    for (int i = h[mid]; i <= 200; i++)
        dp[mid][i] = w[mid];
    for (int i = mid - 1; i >= l; i--)
    {
        for (int j = 0; j < h[i]; j++)
            dp[i][j] = dp[i + 1][j];
        for (int j = h[i]; j <= 200; j++)
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - h[i]] + w[i]);
    }
    top = 0;
    for (int i = L, x; i <= R; i++)
    {
        x = que[i];
        if (b[x].r <= mid)
            que[++M] = x;
        else if (b[x].l > mid)
            tmp[++top] = x;
        else
        {
            int res = 0;
            for (int i = 0; i <= b[x].t; i++)
                res = max(res, dp[b[x].l][i] + dp[b[x].r][b[x].t - i]);
            ans[x] = res;
        }
    }
    for (int i = 1; i <= top; i++)
        que[M + i] = tmp[i];
    R = M + top;
    solve(l, mid, L, M), solve(mid + 1, r, M + 1, R);
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= m; i++)
    {
        b[i].init();
        if (b[i].l == b[i].r)
            ans[i] = (b[i].t >= h[b[i].l]) ? w[b[i].l] : 0;
        else
            que[++top] = i;
    }
    solve(1, n, 1, top);
    for (int i = 1; i <= m; i++)
        cout << ans[i] << '\n';
}