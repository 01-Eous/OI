#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
using pii = pair<int,int>;
int n;
int a[45],len[45],arr[45];
int pw[45][45],val[45][45];
vector<pii> dp[45];
pii &operator+=(pii &x,const pii &y)
{
    if (x.first > y.first)
        x = y;
    else if (x.first == y.first)
        x.second += y.second;
    return x;
}
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
            val[i][++len[i]] = a[j];
        val[i][++len[i]] = n + 1;
        sort(val[i] + 1,val[i] + len[i] + 1);
        int tmp = 1;
        for (int j = 1; j <= len[i]; j++)
        {
            pw[i][j] = tmp;
            tmp *= val[i][j] - val[i][j - 1];
        }
        dp[i].resize(tmp,{inf,0});
    }
    dp[0][0] = {0,1};
    for (int i = 0; i < n; i++)
    {
        int pos = 0;
        for (int j = 1; j <= len[i]; j++)
        {
            if (val[i][j] == a[i + 1])
            {
                pos = j;
                break;
            }
        }
        for (int j = 0; j < dp[i].size(); j++)
        {
            int tmp = j,cnt = 0;
            for (int k = len[i]; k >= 1; k--)
            {
                arr[k] = tmp / pw[i][k];
                tmp %= pw[i][k];// 求得这个数的每一位
            }
            for (int k = pos + 1; k <= len[i]; k++)
                cnt += arr[k];
            int nxt0 = 0,nxt1;
            for (int k = 1; k < pos; k++)
                nxt0 += arr[k] * pw[i + 1][k];
            for (int k = pos + 2; k <= len[i]; k++)
                nxt0 += arr[k] * pw[i + 1][k - 1];// 把 pos 的位置让出来
            nxt0 += (arr[pos] + arr[pos + 1]) * pw[i + 1][pos];
            nxt1 = nxt0 + pw[i + 1][pos];
            dp[i + 1][nxt0] += dp[i][j];
            dp[i + 1][nxt1] += {dp[i][j].first + cnt,dp[i][j].second};
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%lld %lld\n",dp[n][i].first,dp[n][i].second);
    return 0;
}