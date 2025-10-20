#include<bits/extc++.h>
#define int long long
using namespace std;
int n,k;
void solve()
{
    scanf("%lld%lld",&n,&k);
    if (k > n * (n - 1) * (n - 2) / 6 + 1)
        return (void)puts("No");
    puts("Yes");
    for (int i = 1,j = n; i < n;)
    {
        int x = i;
        while (k < (j - 1) * (j - 2) / 2 && j > 1 && i < n - 1)
        {
            printf("%lld %lld\n",x,++i);
            j--;
        }
        k -= (j - 1) * (j - 2) / 2;
        printf("%lld %lld\n",x, ++i);
        j--;
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