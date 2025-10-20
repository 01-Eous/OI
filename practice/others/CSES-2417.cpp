#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;
int n;
int a[maxn],cnt[maxm];
int lpf[maxm],mo[maxm];
void init(int n = 1e6)
{
    for (int i = 2; i <= n; i++)
    {
        if (lpf[i])
            continue;
        lpf[i] = i;
            for (int j = i; j <= n; j += i)
                lpf[j] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            mo[i] = 1;
            continue;
        }
        if (lpf[i] == lpf[i / lpf[i]])
            mo[i] = 0;
        else
            mo[i] = -1 * mo[i / lpf[i]];
    }
}
signed main()
{
    init();
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        cnt[a[i]]++;        
    }
    int ans = 0;
    for (int i = 1; i <= 1e6; i++)
    {
        if (!mo[i])
            continue;
        int tmp = 0;
        for (int j = i; j <= 1e6; j += i)
            tmp += cnt[j];
        ans += tmp * (tmp - 1) / 2 * mo[i];
    }
    printf("%lld",ans);
    return 0;
}