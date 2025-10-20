#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 1e6 + 5;
int n,b;
int pr[maxn];
bool ipr[maxn];
void init(int n = 1e6)
{
    for (int i = 2; i <= n; i++)
    {
        if (!ipr[i])
            pr[++pr[0]] = i;
        for (int j = 1; j <= pr[0] && i * pr[j] <= n; j++)
        {
            ipr[i * pr[j]] = 1;
            if (i % pr[j] == 0)
                break;
        }
    }
}
signed main()
{
    init();
    scanf("%lld%lld",&n,&b);
    int ans = inf;
    for (int i = 1; i <= pr[0]; i++)
    {
        if (b % pr[i] == 0)
        {
            int cnt = 0,sum = 0;
            while (b % pr[i] == 0)
            {
                cnt++;
                b /= pr[i];
            }
            for (__int128 j = pr[i]; j <= n; j *= (__int128)pr[i])
                sum += n / j;
            ans = min(ans,sum / cnt);
        }
    }
    if (b > 1)
    {
        int sum = 0;
        for (__int128 j = b; j <= n; j *= (__int128)b)
            sum += n / j;
        ans = min(ans,sum);
    }
    printf("%lld",ans);
    return 0;
}