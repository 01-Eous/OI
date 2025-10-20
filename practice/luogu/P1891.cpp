#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
int n;
bool ipr[maxn];
int pr[maxn],phi[maxn],f[maxn];
void init(int n = 1e6)
{
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!ipr[i])
        {
            pr[++pr[0]] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= pr[0] && i * pr[j] <= n; j++)
        {
            ipr[i * pr[j]] = 1;
            if (i % pr[j] == 0)
            {
                phi[i * pr[j]] = phi[i] * pr[j];
                break;
            }
            phi[i * pr[j]] = phi[i] * (pr[j] - 1);
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i)
            f[j] += (phi[i] * i + 1) >> 1;
}
signed main()
{
    init();
    int t;
    scanf("%lld",&t);
    while (t--)
    {
        scanf("%lld",&n);
        printf("%lld\n",f[n] * n);
    }
    return 0;
}