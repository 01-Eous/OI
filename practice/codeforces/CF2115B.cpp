#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
int n,q,cnt,idx;
int x[maxn],y[maxn],z[maxn];
int a[maxn],b[maxn],tmp[maxn];
int head[maxn],cur[maxn],in[maxn];
struct edge{int v,nxt;}e[maxn << 2];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void topsort()
{
    queue<int> q;
    for (int i = 1; i <= cnt; i++)
        if (!in[i])
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].v;
            a[v] = max(a[v],a[u]);
            if (!--in[v])
                q.push(v);
        }
    }
}
bool chk()
{
    memcpy(tmp,a,sizeof(int) * (n + 5));
    for (int i = 1; i <= q; i++)
        tmp[z[i]] = min(tmp[x[i]],tmp[y[i]]);
    for (int i = 1; i <= n; i++)
        if (tmp[i] != b[i])
            return 0;
    return 1;
}
void solve()
{
    scanf("%lld%lld",&n,&q);
    fill(a + 1,a + n + q + 1,0);
    fill(in + 1,in + n + q + 1,0);
    fill(head + 1,head + n + q + 1,0);
    for (int i = 1; i <= n; i++)
        scanf("%lld",b + i),cur[i] = i;
    cnt = n,idx = 0;
    for (int i = 1; i <= q; i++)
    {
        scanf("%lld%lld%lld",x + i,y + i,z + i);
        int tx = cur[x[i]],ty = cur[y[i]];
        cur[z[i]] = ++cnt;
        adde(cur[z[i]],tx);
        adde(cur[z[i]],ty);
        in[tx]++,in[ty]++;
    }
    for (int i = 1; i <= n; i++)
        a[cur[i]] = b[i];
    topsort();
    if (!chk())
        return (void)puts("-1");
    for (int i = 1; i <= n; i++)
        printf("%lld ",a[i]);
    putchar('\n');
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}