#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;
int n;
int a[maxn],siz[maxm],apr[maxm];
int pool[maxm * 20],head[maxm],tail[maxm];
void init(int n = 1e6)
{
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i)
            siz[j]++;
    for (int i = 1; i <= n; i++)
    {
        head[i] = head[i - 1] + siz[i - 1];
        tail[i] = head[i] - 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i)
            pool[++tail[j]] = i;
}
signed main()
{
    init();
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        apr[a[i]]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
            continue;
        for (int j = head[a[i]] + 1; j <= tail[a[i]]; j++)
        {
            if (a[i] / pool[j] <= pool[j])
                break;
            ans += apr[pool[j]] * apr[a[i] / pool[j]];
        }
    }
    printf("%lld",ans);
    return 0;
}