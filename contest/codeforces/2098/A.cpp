#include<bits/extc++.h>
using namespace std;
char s[15];
int n,buc[15];
void solve()
{
    scanf("%s",s + 1);
    n = strlen(s + 1);
    memset(buc,0,sizeof buc);
    for (int i = 1; i <= n; i++)
        buc[s[i] - '0']++;
    for (int i = 1; i <= n; i++)
    {
        int tmp = 10;
        for (int j = 10 - i; j < 10; j++)
        {
            if (buc[j])
            {
                tmp = j;
                break;
            }
        }
        putchar(tmp + '0');
        buc[tmp]--;
    }
    putchar('\n');
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}