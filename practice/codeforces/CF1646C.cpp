#include<bits/extc++.h>
#define int long long
using namespace std;
int n,ans,idx;
int fac[16];
void dfs(int pos,int cnt,int x)
{
    if (pos > idx)
    {
        ans = min(ans,cnt + __popcount(x));
        return ;
    }
    if (x >= fac[pos] && cnt < ans)
        dfs(pos + 1,cnt + 1,x - fac[pos]);
    dfs(pos + 1,cnt,x);
}
void solve()
{
    scanf("%lld",&n);
    ans = __popcount(n);
    dfs(1,0,n);
    printf("%lld\n",ans);
}
signed main()
{
    fac[0] = 1;
    while (1)
    {
        idx++;
        fac[idx] = fac[idx - 1] * idx;
        if (fac[idx] > 1e12)
        {
            idx--;
            break;
        }
    }
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}