#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int n;
int a[maxn];
void solve()
{
    scanf("%lld",&n);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        sum ^= a[i];
    }
    if (!sum)
        return (void)puts("Draw");
    int pos = 63;
    while (!(sum & (1LL << pos)))
        pos--;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += (a[i] >> pos) & 1LL;
    if (n & 1)
    {
        if (cnt % 4 == 1)
            puts("Alice");
        else
            puts("Bob");
    }
    else
        puts("Alice");
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}