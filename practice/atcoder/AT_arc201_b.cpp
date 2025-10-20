#include<bits/extc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;
const int maxn = 2e5 + 5;
int n,w;
void solve()
{
    scanf("%lld%lld",&n,&w);
    multiset<int,greater<>> st[65];
    for (int i = 1,x,y; i <= n; i++)
    {
        scanf("%lld%lld",&x,&y);
        st[x].insert(y);
    }
    int ans = 0,i;
    set<int>::iterator p1,p2;
    for (i = 0; 1LL << i <= w; i++)
    {
        if (st[i].empty())
            continue;
        if ((w >> i) & 1)
        {
            ans += *st[i].begin();
            st[i].erase(st[i].begin());
        }
        if (st[i].size() & 1)
            st[i].insert(0);
        for (p1 = st[i].begin(); p1 != st[i].end(); p1 = ++p2)
            p2 = p1,st[i + 1].insert(*p1 + *++p2);
        st[i].clear();
    }
    printf("%lld\n",ans);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while(t--)
        solve();
    return 0;
}
