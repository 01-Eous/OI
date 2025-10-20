#include<bits/extc++.h>
using namespace std;
int n,x,y;
map<int,int> mp1,mp2;
void solve()
{
    scanf("%d",&n);
    mp1.clear(),mp2.clear();
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d",&x,&y);
        mp1[x]++;
        mp2[x + y]++;
    }
    for (auto [v,cnt] : mp1)
    {
        if (cnt & 1)
        {
            x = v;
            break;
        }
    }
    for (auto [v,cnt] : mp2)
    {
        if (cnt & 1)
        {
            y = v - x;
            break;
        }
    }
    printf("%d %d\n",x,y);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}