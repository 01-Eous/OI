#include<bits/extc++.h>
using namespace std;
int n,m;
void solve()
{
    scanf("%d%d",&n,&m);
    vector<int>a(n * m + 5),b(n * m + 5),pos(n * m + 5,-1);
    for (int i = 1; i <= n * m; i++)
        scanf("%d",&a[i]);
    map<int,int>mp;
    for (int i = 1; i <= n * m; i++)
    {
        scanf("%d",&b[i]);
        mp[b[i]] = i;
    }
    for (int i = 1; i <= n * m; i++)
    {
        if (mp.find(a[i]) == mp.end())
            break;
        else
            pos[i] = mp[a[i]];
    }
    pos[0] = 0;
    int skp = 0,pre = 0;
    bool fl = 1;
    for (int i = 1; i <= n * m; i++)
    {
        if (pos[i - 1] > pos[i])
            break;
        int tmp = pos[i] - pos[i - 1] - 1;
        if (fl)
            skp += tmp;
        else if (tmp > 0)
            break;
        fl = skp >= m - 1 || (i + skp) % m == 0 || (i - 1) % m > (i + skp - 1) % m;
        if (fl)
            pre = i;
    }
    printf("%d\n",n * m - pre);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}