#include<bits/extc++.h>
using namespace std;
const int maxn = 7505;
int n,a[maxn],b[maxn],tot,ans[maxn];
void calc(int l,int r)
{
    int tmp = tot;
    while (l >= 1 && r <= n)
    {
        if (a[l] == b[l] && a[l] != b[r])
            tmp--;
        if (a[r] == b[r] && a[r] != b[l])
            tmp--;
        if (a[l] != b[l] && a[l] == b[r])
            tmp++;
        if (a[r] != b[r] && a[r] == b[l])
            tmp++;
        ans[tmp]++;
        l--,r++;
    }
}
signed main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%d",a + i);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",b + i);
        tot += a[i] == b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        calc(i,i);
        if (i == 1)
            continue;
        calc(i - 1,i);
    }
    for (int i = 0; i <= n; i++)
        printf("%d\n",ans[i]);
    return 0;
}