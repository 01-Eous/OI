#include<bits/extc++.h>
#define sq(x) ((x) * (x))
using namespace std;
typedef pair<int,int> pii;
int n;
int a[20],sum[20],dp[20][20];
vector<pii> op[20][20],ans;
void calc(int l,int r)
{
    if (l == r)
    {
        if (!a[l])
            return;
        ans.push_back({l,r});
        a[l] = 0;
        return;
    }
    for (int i = r - 1; i >= l; i--)
        calc(l,i);
    if (a[r] != r - l)
        ans.push_back({l,r});
    else
        ans.push_back({l,r - 1});
    fill(a + l,a + r + 1,r - l);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int len = j - i + 1;
            dp[i][j] = sum[j] - sum[i - 1];
            if (sq(len) > dp[i][j])
            {
                dp[i][j] = sq(len);
                op[i][j].push_back({i,j});
            }
        }
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1,j; (j = i + len - 1) <= n; i++)
        {
            int pos = 0;
            for (int k = i; k < j; k++)
            {
                if (dp[i][j] < dp[i][k] + dp[k + 1][j])
                {
                    pos = k;
                    dp[i][j] = dp[i][k] + dp[k + 1][j];
                }
            }
            if (pos)
            {
                op[i][j].clear();
                for (auto k : op[i][pos])
                    op[i][j].push_back(k);
                for (auto k : op[pos + 1][j])
                    op[i][j].push_back(k);
            }
        }
    }
    for (auto &[l,r] : op[1][n])
    {
        calc(l,r);
        for (int i = r - 1; i >= l; i--)
            calc(l,i);
        ans.push_back({l,r});
    }
    cout << dp[1][n] << ' ' << ans.size() << '\n';
    for (auto &[l,r] : ans)
        cout << l << ' ' << r << '\n';
    return 0;
}