#include<bits/extc++.h>
using namespace std;
typedef double ld;
const int maxn = 2.5e5 + 5;
int n,m;
int u[maxn],v[maxn],deg[505];
ld val[505][505],ans[505],dp[maxn];
vector<int>g[505];
void gauss(int n)
{
    for (int i = 1; i <= n; i++)
    {
        int pos = i;
        for (int j = i + 1; j <= n; j++)
            if (abs(val[pos][i]) < abs(val[j][i]))
                pos = j;
        swap(val[pos],val[i]);
        ld tmp = val[i][i];
        for (int j = i; j <= n + 1; j++)
            val[i][j] /= tmp;
        for (int j = i + 1; j <= n; j++)
        {
            tmp = val[j][i];
            for (int k = i; k <= n + 1; k++)
                val[j][k] -= tmp * val[i][k];
        }
    }
    ans[n] = val[n][n + 1];
    for (int i = n - 1; i >= 1; i--)
    {
        ans[i] = val[i][n + 1];
        for (int j = i + 1; j <= n; j++)
            ans[i] -= val[i][j] * ans[j];
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i];
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
        deg[u[i]]++,deg[v[i]]++;
    }
    val[1][n] = 1;// 1 的初始答案耀嘉音
    for (int u = 1; u < n; u++)
    {
        val[u][u] = 1;
        for (auto v : g[u])
            if (v != n)
                val[u][v] = (ld)-1 / deg[v];
    }
    gauss(n - 1);
    for (int i = 1; i <= m; i++)
        dp[i] = ans[u[i]] / deg[u[i]] + ans[v[i]] / deg[v[i]];
    sort(dp + 1,dp + m + 1,greater<ld>());
    ld ans = 0;
    for (int i = 1; i <= m; i++)
        ans += i * dp[i];
    cout << fixed << setprecision(3) << ans;
    return 0;
}