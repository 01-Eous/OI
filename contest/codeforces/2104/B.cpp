#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int n;
int a[maxn];
void solve()
{
    scanf("%lld",&n);
    multiset<int,greater<>> pre;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        pre.insert(a[i]);
    }
    int sum = 0;
    for (int i = n; i >= 1; i--)
    {
        pre.erase(pre.find(a[i]));
        sum += a[i];
        printf("%lld%c",max(sum,sum - a[i] + *pre.begin())," \n"[i == 1]);
    }
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}