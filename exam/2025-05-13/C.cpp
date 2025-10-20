#include<bits/extc++.h>
#define int long long
using namespace std;
using ull = unsigned int;
const int maxn = 1e6 + 5;
const ull base = 97;
int n,m;
ull pw[maxn],hshl[maxn],hshr[maxn],no;
vector<string> a;
void init(int n = 1e6)
{
    pw[0] = 1;
    no = mt19937_64{random_device{}()}();
    for (int i = 1; i <= n; i++)
        pw[i] = pw[i - 1] * base;
}
namespace line
{
    ull s[maxn << 1];
    int pre[maxn],suf[maxn];
    int len[maxn],dp[maxn << 1];
    bool dp1[maxn],dp2[maxn];
    void calc_single_hash()
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                hshl[i] = hshl[i] * base + a[i][j] - 'A';
    }
    void manacher()
    {
        int up = m << 1 | 1;
        for (int i = 1; i <= up; i++)
            s[i] = i & 1 ? no : hshr[i >> 1];
        int mid = 0,r = 0;
        for (int i = 1; i <= up; i++)
        {
            if (i <= r)
                dp[i] = min(r - i + 1,dp[(mid << 1) - i]);
            while (i - dp[i] >= 1 && i + dp[i] <= up && s[i - dp[i]] == s[i + dp[i]])
                dp[i]++;
            if (i + dp[i] - 1 > r)
            {
                mid = i;
                r = i + dp[i] - 1;
            }
            if (i & 1)
                len[i >> 1] = dp[i] >> 1;
        }
    }
    void calc_dp()
    {
        dp1[0] = pre[0] = 1;
        for (int i = 1; i <= m; i++)
        {
            if (len[i])
                dp1[i] = pre[i - 1] - (i - len[i] - 1 >= 0 ? pre[i - len[i] - 1] : 0);
            pre[i] = pre[i - 1] + dp1[i];
        }
        dp2[m + 1] = suf[m + 1] = 1;
        for (int i = m; i >= 1; i--)
        {
            if (len[i - 1])
                dp2[i] = suf[i + len[i - 1] + 1] - suf[i + 1];
            suf[i] = suf[i + 1] + dp2[i];
        }
    }
}
namespace row
{
    ull s[maxn << 1];
    int pre[maxn],suf[maxn];
    int len[maxn],dp[maxn << 1];
    bool dp1[maxn],dp2[maxn];
    void calc_single_hash()
    {
        for (int j = 1; j <= m; j++)
            for (int i = 1; i <= n; i++)
                hshr[j] = hshr[j] * base + a[i][j] - 'A';
    }
    void manacher()
    {
        int up = n << 1 | 1;
        for (int i = 1; i <= up; i++)
            s[i] = i & 1 ? no : hshl[i >> 1];
        int mid = 0,r = 0;
        for (int i = 1; i <= up; i++)
        {
            if (i <= r)
                dp[i] = min(r - i + 1,dp[(mid << 1) - i]);
            while (i - dp[i] >= 1 && i + dp[i] <= up && s[i - dp[i]] == s[i + dp[i]])
                dp[i]++;
            if (i + dp[i] - 1 > r)
            {
                mid = i;
                r = i + dp[i] - 1;
            }
            if (i & 1)
                len[i >> 1] = dp[i] >> 1;
        }
    }
    void calc_dp()
    {
        dp1[0] = pre[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (len[i])
                dp1[i] = pre[i - 1] - (i - len[i] - 1 >= 0 ? pre[i - len[i] - 1] : 0);
            pre[i] = pre[i - 1] + dp1[i];
        }
        dp2[n + 1] = suf[n + 1] = 1;
        for (int i = n; i >= 1; i--)
        {
            if (len[i - 1])
                dp2[i] = suf[i + len[i - 1] + 1] - suf[i + 1];
            suf[i] = suf[i + 1] + dp2[i];
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    cin >> n >> m;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] = "?" + a[i];
    }
    line::calc_single_hash();
    row::calc_single_hash();
    line::manacher();
    row::manacher();
    line::calc_dp();
    row::calc_dp();
    int sum1 = 0,sum2 = 0;
    for (int i = 0; i < m; i++)
        sum1 += line::dp1[i] * line::suf[i + 2];
    for (int i = 0; i < n; i++)
        sum2 += row::dp1[i] * row::suf[i + 2];
    cout << sum1 * sum2;
    return 0;
}
