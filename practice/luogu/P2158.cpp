#include<bits/extc++.h>
#define int long long
#define sq(x) ((x) * (x))
using namespace std;
const int maxn = 4e4 + 5;
int idx,n;
bool ipr[maxn];
int pr[maxn],mu[maxn];
void init(int n = 4e4)
{
    mu[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!ipr[i])
        {
            mu[i] = -1;
            pr[++idx] = i;
        }
        for (int j = 1; j <= idx && i * pr[j] <= n; j++)
        {
            ipr[i * pr[j]] = 1;
            if (i % pr[j] == 0)
                break;
            mu[i * pr[j]] = -mu[i];
        }
    }
}
signed main()
{
    init();
    scanf("%lld",&n);
    if (!--n)
        return puts("0"),0;
    int ans = 2;
    for (int i = 1; i <= n; i++)
        ans += sq(n / i) * mu[i];
    printf("%lld",ans);
    return 0;
}
