#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 3e5 + 5;
const int mod = 998244353;
int n,m;
int fac[maxn],inv[maxn];
int val[maxn],sum[maxn][45];
int l[maxn],r[maxn],a[25],b[25];
int binpow(int x,int y)
{
    int res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}
void init(int n = 3e5)
{
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv[n] = binpow(fac[n],mod - 2);
    for (int i = n - 1; ~i; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}
int c(int n,int m)
{
    if (n < 0 || m < 0 || n < m)
        return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
signed main()
{
    init();
    scanf("%lld%lld",&n,&m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld",l + i,r + i);
        val[l[i]]++,val[r[i] + 1]--;
    }
    for (int i = 1; i <= m; i++)
        scanf("%lld%lld",a + i,b + i);
    for (int i = 1; i <= n; i++)
    {
        val[i] += val[i - 1];
        for (int j = 0; j <= m << 1; j++)
            sum[i][j] = sum[i - 1][j] + c(val[i] - j,i - j);
    }
    int ans = 0;
    for (int s = 0; s < (1 << m); s++)
    {
        int tl = 1,tr = n,cnt = 0;
        set<int> st;
        for (int i = 1; i <= m; i++)
        {
            if ((s >> (i - 1)) & 1)
            {
                cnt++;
                tl = max({tl,l[a[i]],l[b[i]]});
                tr = min({tr,r[a[i]],r[b[i]]});
                st.insert(a[i]),st.insert(b[i]);
            }
        }
        if (tl > tr)
           continue;
        int c = st.size();
        ans = (ans + (cnt & 1 ? -1 : 1) * (sum[tr][c] - sum[tl - 1][c] + mod) % mod + mod) % mod;
    }
    printf("%lld",ans);
    return 0;
}
