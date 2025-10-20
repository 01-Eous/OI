#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n,a,b,idx;
int pr[maxn];
bool ipr[maxn];
vector<int> fac;
void init(int n = 1e5)
{
    for (int i = 2; i <= n; i++)
    {
        if (!ipr[i])
            pr[++idx] = i;
        for (int j = 1; j <= idx && i * pr[j] <= n; j++)
        {
            ipr[i * pr[j]] = 1;
            if (i % pr[j] == 0)
                break;
        }
    }
}
void get_fac(int n)
{
    fac.clear();
    for (int i = 1; i <= idx && pr[i] * pr[i] <= n; i++)
    {
        if (n % pr[i] == 0)
        {
            fac.push_back(pr[i]);
            while (n % pr[i] == 0)
                n /= pr[i];            
        }
    }
    if (n > 1)
        fac.push_back(n);
}
int calc(int n)
{
    int res = 0,m = fac.size();
    for (int s = 1; s < 1 << m; s++)
    {
        int x = 0,y = 1;
        for (int i = 0; i < m; i++)
            if (s & (1 << i))
                x++,y *= fac[i];
        res += (x & 1 ? 1 : -1) * (n / y);
    }
    return res;
}
signed main()
{
    init();
    int t;
    scanf("%lld",&t);
    for (int i = 1; i <= t; i++)
    {
        scanf("%lld%lld%lld",&a,&b,&n),get_fac(n);
        printf("Case #%lld: %lld\n",i,b - a + 1 - (calc(b) - calc(a - 1)));
    }
    return 0;
}