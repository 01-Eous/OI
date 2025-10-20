#include<bits/extc++.h>
#define int long long
#define chk() (((n & 1) && (lft == rht)) || (!(n & 1) && (lft + 1 == rht)))
using namespace std;
const int maxn = 1e5 + 5;
int n;
int a[maxn];
bool calc()
{
    int lft = 0,rht = 0;
    for (int i = 2; i <= n; i++)
    {
        lft += a[i] < a[1];
        rht += a[i] > a[1];
    }
    if (chk())
        return 1;
    if (lft > rht)
    {
        for (int i = 2; i <= n; i++)
        {
            if (a[i] < a[1] && -a[i] > a[1])
                lft--,rht++;
            if (chk())
                return 1;
        }
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            if (a[i] > a[1] && -a[i] < a[1])
                lft++,rht--;
            if (chk())
                return 1;
        }
    }
    return 0;
}
void solve()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    bool ans = calc();
    a[1] = -a[1];
    ans |= calc();
    puts(ans ? "YES" : "NO");
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}