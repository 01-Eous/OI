#include<bits/extc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int n,k;
int a[maxn],dp[maxn];
signed main()
{
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",a + i);
        int _max = 0;
        for (int j = i; j && i - j + 1 <= k; j--)
        {
            _max = max(_max,a[j]);
            dp[i] = max(dp[i],dp[j - 1] + _max * (i - j + 1));
        }
    }
    printf("%d",dp[n]);
    return 0;
}