#include<bits/extc++.h>
#define int long long
using namespace std;
int n;
void solve()
{
    scanf("%lld",&n);
    map<int,int> apr;
    for (int i = 1,x; i <= n; i++)
    {
        scanf("%lld",&x);
        apr[x]++;
    }
    for (auto i = apr.begin(); i != apr.end(); i++)
    {
        if (i->second < 2)
            continue;
        if (i->second >= 4)
            return (void)puts("Yes");
        auto j = i;
        int lst = i->first;
        for (j++; j != apr.end() && j->first == lst + 1; lst = j++->first)
            if (j->second >= 2)
                return (void)puts("Yes");
        i = --j;
    }
    puts("No");
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}