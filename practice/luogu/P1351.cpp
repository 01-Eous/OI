#include<bits/extc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 10007;
int n,idx;
int head[maxn],a[maxn];
struct edge{int v,nxt;}e[maxn << 1];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
int sq(int x){return x * x % mod;}
signed main()
{
    scanf("%d",&n);
    for (int i = 1,u,v; i < n; i++)
    {
        scanf("%d%d",&u,&v);
        adde(u,v),adde(v,u);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d",a + i);
    int ans1 = 0,ans2 = 0;
    for (int u = 1; u <= n; u++)
    {
        int max1 = 0,max2 = 0,sum1 = 0,sum2 = 0;
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].v;
            if (a[v] >= max1)
            {
                max2 = max1;
                max1 = a[v];
            }
            else if (a[v] > max2)
                max2 = a[v];
            sum1 = (sum1 + a[v]) % mod;
            sum2 = (sum2 + sq(a[v])) % mod;
        }
        sum1 = sq(sum1) % mod;
        ans1 = max(ans1,max1 * max2);
        ans2 = (ans2 + sum1 - sum2 + mod) % mod;
    }
    printf("%d %d",ans1,ans2);
    return 0;
}