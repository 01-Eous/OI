#include<bits/extc++.h>
#define int long long
using namespace std;
int n,m,x;
vector<int> a;
void solve()
{
    a.clear();
    while (m--)
    {
        scanf("%lld",&x);
        if (x)
            a.push_back(x);
    }
    m = a.size();
    int ans = --n;
    for (int s = 0; s < 1 << m; s++)
    {
        int x = 0,y = 1;
        for (int i = 0; i < m; i++)
            if (s & (1 << i))
                x++,y = y * a[i] / __gcd(y,a[i]);
        ans -= (x & 1 ? -1 : 1) * (n / y);
    }
    printf("%lld\n",ans);
}
signed main()
{
    while (scanf("%lld%lld",&n,&m) != EOF)
        solve();
    return 0;
}