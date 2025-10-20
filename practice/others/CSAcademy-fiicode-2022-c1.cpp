#include<bits/extc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;
const int maxn = 2e6 + 5;
const int mod = 998244353;
int q,idx;
int cnt[10];
pii vec[maxn];
int sum[maxn],inv[55];
int binpow(int x,int y)
{
    int res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}
int c(int n,int m)
{
    if (n < 0 || m < 0 || n < m)
        return 0;
    int res = 1;
    for (int i = n; i > n - m; i--)
        res = res * (i % mod) % mod;
    for (int i = 1; i <= m; i++)
        res = res * inv[i] % mod;
    return res;
}
int calc(int len)
{
    int res = 1;
    for (int i = 2; i < 10; i++)
    {
        res = res * c(len,cnt[i]) % mod;
        len -= cnt[i];
    }
    return res;
}
void dfs(int lst,int len,int mul,int add)
{
    int tmp = len + mul - add;
    vec[++idx] = {tmp,calc(tmp)};
    for (int i = lst; i < 10; i++)
    {
        if (mul * i > 1e12)
            break;
        cnt[i]++;
        dfs(i,len + 1,mul * i,add + i);
        cnt[i]--;
    }
}
signed main()
{
    for (int i = 1; i <= 50; i++)
        inv[i] = binpow(i,mod - 2);
    dfs(2,0,1,0);
    sort(vec + 1,vec + idx + 1);
    for (int i = 1; i <= idx; i++)
        sum[i] = (sum[i - 1] + vec[i].second) % mod;
    scanf("%lld",&q);
    int l,r;
    while (q--)
    {
        scanf("%lld%lld",&l,&r),l--;
        int lp = lower_bound(vec + 1,vec + idx + 1,pii{l + 1,0}) - vec - 1;
        int rp = lower_bound(vec + 1,vec + idx + 1,pii{r + 1,0}) - vec - 1;
        printf("%lld\n",(sum[rp] - sum[lp] + mod) % mod);
    }
    return 0;
}