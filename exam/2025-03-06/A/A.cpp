#include<bits/extc++.h>
using namespace std;
typedef long double ld;
const int maxn = 1e6 + 5;
int x,y;
ld dp[maxn],ans[maxn];
signed main()
{
    scanf("%d%d",&x,&y);
    for (int i = 1; i <= x; i++)
        dp[i] = dp[i - 1] + (ld)1 / (i * 2 - 1);
    ans[0] = dp[x];
    for (int i = 1; i <= y; i++)
        ans[i] = ans[i - 1] + (ld)1 / (x * 2 + i);
    printf("%.12Lf",ans[y]);
    return 0;
}