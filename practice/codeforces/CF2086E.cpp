#include<bits/extc++.h>
#define int long long
using namespace std;
int l,r,k;
int bas[35];
map<int,int> dp[135];
int dfs(int n,int k)
{
    if (k <= 0 || k > 130 || n <= 0)
        return 0;
    if (dp[k].count(n))
        return dp[k][n];
    int pos = 32;
    while (pos && bas[pos] > n)
        pos--;
    int res = 0,tmp = 0;
    for (int i = 0; i <= n; i += bas[pos],tmp++)
    {
        if (i + bas[pos] <= n)
            res += dfs(bas[pos] - 1,k - tmp);
        else
            res += dfs(n % i,k - tmp);
        if (tmp == k)
            res++;
    }
    return dp[k][n] = res;
}
void solve()
{
    scanf("%lld%lld%lld",&l,&r,&k);
    for (int i = 1; i <= 32; i++)
        bas[i] = bas[i - 1] << 2 | 1;
    printf("%lld\n",dfs(r,k) - dfs(l - 1,k));
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}