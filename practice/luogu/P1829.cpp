#include<bits/extc++.h>
#define int long long
#define sq(x) ((x) * (x) % mod)
using namespace std;
const int maxn = 1e7 + 5;
const int mod = 20101009;
int n,m,idx;
bool ipr[maxn];
int pr[maxn],mo[maxn],sum[maxn];
void init(int n = 1e7)
{
    mo[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!ipr[i])
        {
            mo[i] = -1;
            pr[++idx] = i;
        }
        for (int j = 1; j <= idx && i * pr[j] <= n; j++)
        {
            ipr[i * pr[j]] = 1;
            if (i % pr[j] == 0)
                break;
            mo[i * pr[j]] = -mo[i];
        }
    }
    for (int i = 1; i <= n; i++)
        sum[i] = (sum[i - 1] + sq(i) * (mo[i] + mod)) % mod;
}
int g(int n,int m){return ((n * (n + 1) >> 1) % mod) * ((m * (m + 1) >> 1) % mod) % mod;}
int f(int n,int m)
{
    int up = min(n,m),res = 0;
    for (int l = 1,r; l <= up; l = r + 1)
    {
        r = min(n / (n / l),m / (m / l));
        res = (res + (sum[r] - sum[l - 1] + mod) * g(n / l,m / l) % mod) % mod;
    }
    return res;
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    int up = min(n,m),ans = 0;
    init(up);
    for (int l = 1,r; l <= up; l = r + 1)
    {
        r = min(n / (n / l),m / (m / l));
        ans = (ans + ((l + r) * (r - l + 1) >> 1) * f(n / l,m / l) % mod) % mod;
    }
    printf("%lld",ans);
    return 0;
}