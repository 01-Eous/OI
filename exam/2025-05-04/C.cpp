// 又是 tmd 子任务捆绑
#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
const int maxn = 1e5 + 5;
int n,m,idx;
pii a[maxn];
vector<pii> v1 = {{0,0}},v2 = {{0,0}};
bool cmp(const pii &x,const pii &y)
{return x.second - x.first > y.second - y.first;}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a + 1,a + n + 1,cmp);
    int ans = 0;
    for (int i = 1; i < m; i++)
        ans += a[i].second - a[i].first;
    if (n * m > 5e7)
        return cout << ans,0;
    sort(a + 1,a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        while (v1.size() > 1 && v1.back().second >= a[i].second)
        {
            v2.push_back(v1.back());
            v1.pop_back();
        }
        v1.push_back(a[i]);
    }
    vvi pre(m + 5,vi(v1.size() + 5,0));
    vvi dp(m + 5,vi(v1.size() + 5,-inf));
    dp[0][0] = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j < v1.size(); j++)
        {
            int k = pre[i - 1][j - 1];
            dp[i][j] = dp[i - 1][k] + max(0LL,v1[k + 1].second - v1[j].first);
            pre[i][j] = pre[i][j - 1];
            if (dp[i][j] + v1[j + 1].second > dp[i][pre[i][j]] + v1[pre[i][j] + 1].second)
                pre[i][j] = j;
        }
    }
    sort(v2.begin() + 1,v2.end(),cmp);
    for (int i = 0,sum = 0; i <= min(m,(int)v2.size() - 1); i++)
    {
        sum += v2[i].second - v2[i].first;
        ans = max(ans,dp[m - i][v1.size() - 1] + sum);
    }
    cout << ans;
    return 0;
}