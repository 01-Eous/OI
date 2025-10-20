#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 1e5 + 5;
const int lst[5] = {0,3,1,2,0};
int n;
int dp[maxn],pre[maxn][5];
signed main()
{
    scanf("%d",&n);
    int ans = 0;
    pre[0][1] = pre[0][2] = -inf; 
    for (int i = 1,x; i <= n; i++)
    {
        scanf("%d",&x);
        dp[i] = pre[i - 1][lst[x]] + 1;
        memcpy(pre[i],pre[i - 1],sizeof(pre[i]));
        pre[i][x] = max(pre[i][x],dp[i]);
        ans = max(ans,dp[i]);
    }
    printf("%d",ans);
    return 0;
}