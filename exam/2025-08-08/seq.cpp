#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int n,m,k,idx,ans;
bool vis[maxn];
int pr[maxn],cnt[maxn];
void sieve()
{
    for (int i = 2; i <= m; i++)
    {
        if (!vis[i])
            pr[++idx] = i;
        for (int j = 1; j <= idx && i * pr[j] <= m; j++)
        {
            vis[i * pr[j]] = 1;
            if (i % pr[j] == 0)
                break;
        }
    }
}
signed main()
{
    scanf("%lld%lld",&m,&k);
    sieve(),ans = 1;
    fill(cnt + 1,cnt + idx + 1,k - 1);
    for (int i = 1; i <= m; i++)
    {
        int val = pr[i];
        while (cnt[i] && val <= m)
        {
            ans++;
            val *= pr[i];
            cnt[i]--;
        }
    }
    int i = 1,j = idx;
    while (i < j)
    {
        int pos = i;
        while (cnt[j] && pos < j)
        {
            int val = pr[pos] * pr[j];
            while (val <= m && cnt[pos] && cnt[j])
            {
                ans++;
                val *= pr[pos];
                cnt[pos]--,cnt[j]--;
            }
            pos++;
            while (!cnt[i])
                i++;
        }
        j--;
    }
    printf("%lld",ans);
    return 0;
}