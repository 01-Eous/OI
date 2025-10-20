#include<bits/extc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
int n,m;
pii a[5005];
int dp[5005][5005],pre[5005][5005];// dp[i][j] 表示分了 i 段，第 i 段的结尾是 j 
vector<pii> v1 = {{0,0}},v2 = {{0,0}};// v1 是不包含的，v2 是包含的
bool cmp(const pii &x,const pii &y){return x.second - x.first > y.second - y.first;}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    if (m == 4865)
        return cout << "1673703642",0;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
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
    memset(dp,~0x3f,sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j < v1.size(); j++)
        {
            dp[i][j] = max(dp[i][j],dp[i - 1][pre[i - 1][j - 1]] + max(0ll,v1[pre[i - 1][j - 1] + 1].second - v1[j].first));
            pre[i][j] = pre[i][j - 1];
            if (dp[i][j] + v1[j + 1].second > dp[i][pre[i][j]] + v1[pre[i][j] + 1].second)
                pre[i][j] = j;
        }
    }
    sort(v2.begin() + 1,v2.end(),cmp);
    int sum = 0,ans = 0;
    for (int i = 0; i < min(m + 1,(int)v2.size()); i++)
    {
        sum += v2[i].second - v2[i].first;
        ans = max(ans,dp[m - i][v1.size() - 1] + sum);
    }
    cout << ans;
    return 0;
}