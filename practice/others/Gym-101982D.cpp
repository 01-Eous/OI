#include<bits/extc++.h>
#pragma GCC optimize(2)
#pragma GCC target("avx")
using namespace std;
typedef long long ll;
const ll mod = 1000000009;
int k,b;
ll dp[130][130][1005];
ll dfs(int pos,int cnt,int p)
{
    if (~dp[pos][cnt][p])
        return dp[pos][cnt][p];
    if (pos == b)
        return p == 0 ? cnt : 0;
    ll ret = 0;
    for (int i = 0; i < 2; i++)
        ret = (ret + dfs(pos + 1,cnt + i,(p << 1 | i) % k)) % mod;
    return dp[pos][cnt][p] = ret;
}
signed main()
{
    scanf("%d%d",&k,&b);
    memset(dp,0xff,sizeof dp);
    printf("%lld",dfs(0,0,0));
    return 0;
}