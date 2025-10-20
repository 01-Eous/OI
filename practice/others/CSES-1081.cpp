#include<bits/extc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;
int n;
int a[maxn],cnt[maxm];
int siz[maxm],head[maxm],lst[maxm],pool[maxm * 20];
void init(int n = 1e6)
{
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i)
            siz[j]++;
    for (int i = 1; i <= n; i++)
        head[i] = lst[i] = head[i - 1] + siz[i - 1];
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i)
            pool[lst[j]++] = i;
}
signed main()
{
    init();
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",a + i);
        for (int j = head[a[i]]; j < lst[a[i]]; j++)
            cnt[pool[j]]++;
    }
    int ans = 1;
    for (int i = 1e6; i >= 1; i--)
    {
        if (cnt[i] >= 2)
        {
            ans = i;
            break;
        }
    }
    printf("%d",ans);
    return 0;
}