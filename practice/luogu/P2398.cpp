#include<bits/extc++.h>
#define int long long
#define sq(x) ((x) * (x))
using namespace std;
const int maxn = 1e5 + 5;
int n,idx;
bool ipr[maxn];
int pr[maxn],phi[maxn];
void init(int n = 1e5)
{
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!ipr[i])
        {
            pr[++idx] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= idx && i * pr[j] <= n; j++)
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
}
signed main()
{
    init();
    scanf("%lld",&n);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += sq(n / i) * phi[i];
    printf("%lld",ans);
    return 0;
}