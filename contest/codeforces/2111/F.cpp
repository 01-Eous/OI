#include<bits/extc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;
int p,s,n,m;
vector<pii> ans;
bool calc(int p,int s)
{
    ans.clear();
    int cnt = (p - 2) >> 1;
    if (s < cnt || cnt < 3)
        return 0;
    for (int i = 1; i <= cnt >> 1; i++)
        ans.push_back({i,1});
    n = ans.back().first;
    for (int i = 1; i + (cnt >> 1) <= cnt; i++)
        ans.push_back({1,i + 1});
    m = ans.back().second;
    if (n * m < s)
        return 0;
    s -= cnt;
    int x = 2,y = 2;
    while (s--)
    {
        ans.push_back({x,y});
        if (++y > m)
            x++,y = 2;
    }
    return 1;
}
void solve()
{
    scanf("%lld%lld",&p,&s);
    int g = __gcd(p,s);
    p /= g,s /= g;
    if (p == 4 && s == 1)
        return (void)printf("1\n1 1\n");
    else if (p == 3 && s == 1)
        return (void)printf("2\n1 1\n1 2\n");
    if (p & 1)
        p <<= 1,s <<= 1;
    bool fl = 0;
    for (int i = p,j = s; j <= 5e4; i += p,j += s)
    {
        if (calc(i,j))
        {
            fl = 1;
            break;
        }
    }
    if (!fl)
        return (void)puts("-1");
    printf("%llu\n",ans.size());
    for (auto [x,y] : ans)
        printf("%lld %lld\n",x,y);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}