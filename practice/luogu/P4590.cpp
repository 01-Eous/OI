#include<bits/extc++.h>
#define int long long
#define add(x,y) x = (x + y) % mod
using namespace std;
const int maxn = 1 << 15 | 5;
const int mod = 1e9 + 7;
int n,k;
char str[20];
int a1[20],a2[20];
int dp[2][maxn][3],ans[20];
int en(int *arr)
{
    int res = 0;
    for (int i = 1; i <= k; i++)
        res |= (arr[i] - arr[i - 1]) << (i - 1);
    return res;
}
void de(int *arr,int val)
{
    for (int i = 1; i <= k; i++)    
        arr[i] = (val >> (i - 1)) & 1;
    for (int i = 1; i <= k; i++)
        arr[i] += arr[i - 1];
}
void 转移(int x,int sta,int y,char ch,int val)
{
    de(a1,sta);
    for (int i = 1; i <= k; i++)
        a2[i] = max({a1[i],a2[i - 1],a1[i - 1] + (ch == str[i])});
    int tmp = en(a2);
    add(dp[x][tmp][y],val);
}
signed main()
{
    scanf("%lld%lld%s",&n,&k,str + 1);
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        int cur = i & 1,nxt = !cur;
        for (int s = 0; s < (1 << k); s++)
            for (int j = 0; j < 3; j++)
                dp[nxt][s][j] = 0;
        for (int s = 0; s < (1 << k); s++)
        {
            if (dp[cur][s][0])
            {
                int tmp = dp[cur][s][0];
                转移(nxt,s,1,'N',tmp);
                转移(nxt,s,0,'O',tmp);
                转移(nxt,s,0,'I',tmp);
            }
            if (dp[cur][s][1])
            {
                int tmp = dp[cur][s][1];
                转移(nxt,s,1,'N',tmp);
                转移(nxt,s,2,'O',tmp);
                转移(nxt,s,0,'I',tmp);
            }
            if (dp[cur][s][2])
            {
                int tmp = dp[cur][s][2];
                转移(nxt,s,1,'N',tmp);
                转移(nxt,s,0,'O',tmp);
            }
        }
    }
    for (int s = 0; s < (1 << k); s++)
        for (int j = 0; j < 3; j++)
            add(ans[__builtin_popcount(s)],dp[n & 1][s][j]);
    for (int i = 0; i <= k; i++)
        printf("%lld\n",ans[i]);
    return 0;
}