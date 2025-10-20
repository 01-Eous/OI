#include<bits/extc++.h>
using namespace std;
int n;
void solve()
{
    scanf("%d",&n);
    if (n < 7)
    {
        puts("8");
        return;
    }
    int ans = 7;
    for (int i = 1; pow(10,i) <= n; i++)
    {
        int d = n / (int)pow(10,i) % 10;
        if (d == 9)
            continue;
        else if (d == 8)
        {
            if (n % (int)pow(10,i) == 0)
                ans = min(ans,1);
        }
        else if (d == 7)
        {
            ans = 0;
            break;
        }
        else
        {
            int tmp = n % (int)pow(10,i);
            ans = min(ans,7 - d + (tmp < 7 - d));
        }
    }
    for (int i = 1; pow(10,i) <= n; i++)
    {
        int d = n / (int)pow(10,i) % 10;
        if (d == 8)
            ans = min(ans,1 + n % (int)pow(10,i));
    }
    ans = min(ans,(n % 10 + 3) % 10);
    printf("%d\n",ans);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}