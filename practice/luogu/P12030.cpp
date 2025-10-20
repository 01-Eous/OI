#include<bits/extc++.h>
#define int long long
#define sq(x) ((x) * (x) % mod)
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int n,d,x,y,ans;
int a[maxn];
bool chk(int mid)
{
    int tim = 0,sum = 0,cnt = 0;
    for (int i = 1; i <= x; i++)
    {
        if (a[i] < mid)
        {
            sum = (sum + sq(a[i])) % mod;
            continue;
        }
        int dlt = min(d,a[i] - mid);
        tim += dlt;
        if (dlt < d)
            cnt++;
        else
            sum = (sum + sq(a[i] - d)) % mod;
    }
    if (tim > d * y)
        return 0;
    for (int i = x + 1; i <= n; i++)
        sum = (sum + sq(a[i])) % mod;
    int tmp = mid ? min(cnt,d * y - tim) : 0;
    sum = (sum + tmp * sq(mid - 1)) % mod;
    sum = (sum + (cnt - tmp) * sq(mid)) % mod;
    return ans = sum,1;
}
signed main()
{
    scanf("%lld%lld%lld%lld",&n,&d,&x,&y);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    sort(a + 1,a + n + 1,greater<>());
    for (int i = 1; i <= x; i++)
        a[i] += d;
    int l = 0,r = 2e9,mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (chk(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    printf("%lld",ans);
    return 0;
}