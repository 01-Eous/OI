#include<bits/extc++.h>
#define int long long
#define lowbit(x) (x & -x)
using namespace std;
typedef pair<int,int> pii;
const int maxn = 2e5 + 5;
const int mod = 998244353;
int n,m;
int y[maxn],tree[maxn],p2[maxn];
pii a[maxn],pre[maxn],suf[maxn];
void upd(int i,int val)
{
    for (; i <= 2e5; i += lowbit(i))
        tree[i] += val;
}
int que(int i)
{
    int ret = 0;
    for (; i; i -= lowbit(i))
        ret += tree[i];
    return ret;
}
void init()
{
    p2[0] = 1;
    for (int i = 1; i <= 2e5; i++)
        p2[i] = (p2[i - 1] << 1) % mod;
}
signed main()
{
    init();
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld%lld",&a[i].first,&a[i].second);
    sort(a + 1,a + n + 1);
    for (int i = 1; i <= n; i++)
        y[i] = a[i].second;
    sort(y + 1,y + n + 1);
    m = unique(y + 1,y + n + 1) - y - 1;
    for (int i = 1; i <= n; i++)
        a[i].second = lower_bound(y + 1,y + m + 1,a[i].second) - y;
    for (int i = 1; i <= n; i++)
    {
        pre[i].first = que(a[i].second);
        pre[i].second = i - 1 - pre[i].first;
        upd(a[i].second,1);
    }
    memset(tree,0,sizeof tree);
    for (int i = n; i >= 1; i--)
    {
        suf[i].first = que(a[i].second);
        suf[i].second = n - i - suf[i].first;
        upd(a[i].second,1);
    }
    int ans = (p2[n] - 1) * n % mod;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + p2[pre[i].first]) % mod;
        ans = (ans + p2[pre[i].second]) % mod;
        ans = (ans + p2[suf[i].first]) % mod;
        ans = (ans + p2[suf[i].second]) % mod;
        ans = ((ans - p2[pre[i].first + suf[i].first]) % mod + mod) % mod;
        ans = ((ans - p2[pre[i].second + suf[i].second]) % mod + mod) % mod;
        ans = ((ans - p2[pre[i].first + pre[i].second]) % mod + mod) % mod;
        ans = ((ans - p2[suf[i].second + suf[i].first]) % mod + mod) % mod;
    }
    printf("%lld",ans);
    return 0;
}