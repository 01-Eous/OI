#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n,ans;
int num[55],len;
char s[55];
vector<int>cnt(10,0);
map<vector<int>,int>dp[55][2];
void solveA()
{
    for (int i = 1; i <= len; i++)
        n = n * 10 + num[i];
    for (int i = 1; i <= n; i++)
    {
        int cnt[10] = {},tmp = i;
        while (tmp)
        {
            cnt[tmp % 10]++;
            tmp /= 10;
        }
        int _max = 0;
        for (int j = 0; j < 10; j++)
        {
            if (cnt[j] >= _max)
            {
                _max = cnt[j];
                tmp = j;
            }
        }
        ans += tmp;
    }
    printf("%lld",ans);
}
int dfs(int pos,bool lim,bool zero)
{
    if (pos == len + 1)
    {
        int _max = 1,ret = 0;
        for (int i = 0; i < 10; i++)
        {
            if (cnt[i] >= _max)
            {
                _max = cnt[i];
                ret = i;
            }
        }
        return ret;
    }
    if (!lim && dp[pos][zero][cnt])
        return dp[pos][zero][cnt];
    int up = lim ? num[pos] : 9,ret = 0;
    for (int i = 0; i <= up; i++)
    {
        if ((zero && i != 0) || !zero)
            cnt[i]++;
        ret = (ret + dfs(pos + 1,lim && i == up,zero && i == 0)) % mod;
        if ((zero && i != 0) || !zero)
            cnt[i]--;
    }
    if (!lim)
        dp[pos][zero][cnt] = ret;
    return ret;
}
signed main()
{
    scanf("%s",s + 1);
    len = strlen(s + 1);
    for (int i = 1; i <= len; i++)
        num[i] = s[i] - '0';
    if (len <= 6)
        solveA();
    else
        printf("%lld",dfs(1,1,1));
    return 0;
}