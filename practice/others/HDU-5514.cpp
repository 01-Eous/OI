#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e4 + 5;
int n,m;
int a[maxn],val[maxn];
vector<int> fac;
int calc(int x,int cnt){return x * cnt + cnt * (cnt - 1) / 2 * x;}
void solve(int t)
{
    scanf("%lld%lld",&n,&m);
    fac.clear();
    for (int i = 1; i * i <= m; i++)
    {
        if (m % i)
            continue;
        fac.push_back(i);
        if (m / i != i)
            fac.push_back(m / i);
    }
    memset(val,0,sizeof(int) * (fac.size() + 5));
    sort(fac.begin(),fac.end());
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        a[i] = __gcd(a[i],m);
        for (int j = 0; j < fac.size(); j++)
            if (fac[j] % a[i] == 0)
                val[j] = 1;
    }
    int ans = 0;
    for (int i = 0; i < fac.size(); i++)
    {
        ans += val[i] * calc(fac[i],(m - 1) / fac[i]);
        for (int j = i + 1; j < fac.size(); j++)
            if (fac[j] % fac[i] == 0)
                val[j] -= val[i];
    }
    printf("Case #%lld: %lld\n",t,ans);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    for (int i = 1; i <= t; i++)
        solve(i);
    return 0;
}