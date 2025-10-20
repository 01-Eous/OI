#include<bits/extc++.h>
using namespace std;
int n,a,b;
char s[1005][1005];
void solve()
{
    scanf("%d%d%d",&n,&a,&b);
    swap(a,b);
    for (int i = 1; i <= n; i++)
        scanf("%s",s[i] + 1);
    int ans = 0;
    if (a == 0 && b == 0)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                ans += (s[i][j] != 'W');
        goto Nahida;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i][j] == 'B')
            {
                int tx = i - a,ty = j - b;
                if (tx < 1 || ty < 1 || s[tx][ty] != 'G')
                    return (void)puts("-1");
                s[tx][ty] = 'W',s[i][j] = 'G';
                ans++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i][j] == 'G')
            {
                ans++;
                s[i][j] = 'W';
                int tx = i + a,ty = j + b;
                if (tx > n || ty > n || s[tx][ty] != 'G')
                    continue;
                s[tx][ty] = 'W';
            }
        }
    }        
    Nahida:printf("%d\n",ans);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}