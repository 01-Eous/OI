#include<bits/extc++.h>
#define int long long
using namespace std;
int n,res,cnt;
int ans[605];
bool vis[605];
void solve()
{
    scanf("%lld",&n);
    n <<= 1;
    memset(ans,0,sizeof(int) * (n + 5));
    cnt = 0;
    memset(vis,0,sizeof(bool) * (n + 5));
    for (int i = 2; i <= n; i++)
    {
        printf("? %lld",i - cnt);
        for (int j = 1; j <= i; j++)
            if (!vis[j])
                printf(" %lld",j);
        putchar('\n'),fflush(stdout);
        scanf("%lld",&res);
        if (res)
        {
            ans[i] = res;
            vis[i] = 1;
            cnt++;
        }
    }
    cnt = 0;
    memset(vis,0,sizeof(bool) * (n + 5));
    for (int i = n - 1; i >= 1; i--)
    {
        if (ans[i])
            continue;
        printf("? %lld",(n - i + 1) - cnt);
        for (int j = n; j >= i; j--)
            if (!vis[j])
                printf(" %lld",j);
        putchar('\n'),fflush(stdout);
        scanf("%lld",&res);
        if (res)
        {
            ans[i] = res;
            vis[i] = 1;
            cnt++;
        }
    }
    putchar('!');
    for (int i = 1; i <= n; i++)
        printf(" %lld",ans[i]);
    putchar('\n'),fflush(stdout);
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}