#include<bits/extc++.h>
using namespace std;
int n,m;
int cnt[1005];
signed main()
{
    scanf("%d",&n);
    for (int i = 1,x; i <= n; i++)
    {
        scanf("%d",&x);
        m = max(m,x);
        cnt[x]++;
    }
    int sum = 0;
    double ans = n;
    for (int i = 1; i <= m; i++)
    {
        ans += (sum * cnt[i]) / (n - sum + 1.0);
        sum += cnt[i];
    }
    printf("%.2lf",ans);
    return 0;
}