#include<bits/extc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;
using i128 = __int128_t;
int n;
vector<pii> ans;
int chk(int mid,int len)
{
    i128 mul = 1;
    for (int i = mid + 1; i <= mid + len; i++)
    {
        mul *= (i128)i;
        if (mul > n)
            return 1;
    }
    return mul == n ? 0 : -1;
}
void solve()
{
    scanf("%lld",&n);
    if (n == 1)
        return (void)puts("-1");
    ans.clear();
    for (int i = 1; i <= 20; i++)
    {
        int l = 1,r = n,mid;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            int tmp = chk(mid,i);
            if (tmp < 0)
                l = mid + 1;
            else if (tmp > 0)
                r = mid - 1;
            else
            {
                ans.push_back({mid + i,mid});
                break;
            }
        }
    }
    sort(ans.begin(),ans.end());
    printf("%u\n",ans.size());
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