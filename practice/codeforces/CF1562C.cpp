#include<bits/extc++.h>
const int maxn = 2e4 + 5;
int n;
char s[maxn];
void solve()
{
    scanf("%d%s",&n,s + 1);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '0')
        {
            if (i - 1 >= n >> 1)
                printf("%d %d %d %d\n",1,i,1,i - 1);
            else
                printf("%d %d %d %d\n",i,n,i + 1,n);
            return;
        }   
    }
    printf("%d %d %d %d\n",1,n - 1,2,n);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}