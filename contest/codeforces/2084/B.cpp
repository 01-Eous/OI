#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n,a[maxn];
void solve()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    sort(a + 1,a + n + 1);
    vector<int> vec;
    for (int i = 2; i <= n; i++)
        if (a[i] % a[1] == 0)
            vec.push_back(a[i]);
    int gcd = 0;
    for (auto i : vec)
        gcd = __gcd(gcd,i);
    if (gcd == a[1])
        puts("Yes");
    else
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