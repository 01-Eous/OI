#include<bits/extc++.h>
#define int long long
#define inv(x) binpow(x,mod - 2)
using namespace std;
const int maxn = 3e5 + 5;
const int mod = 998244353;
int n,m,r,k,sum,idx = 1;
int a[maxn],b[maxn],head[maxn];
int in[maxn],out[maxn],ori[maxn];
struct edge{int v,w,nxt;}e[maxn << 2];
int binpow(int x,int y)
{
    int res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}
void adde(int u,int v,int w)
{
    e[++idx] = {v,w,head[u]};
    head[u] = idx;
}
void topsort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!in[i])
            q.push(i);
    while (!q.empty())
    {
        int u = q.front(),tmp = a[u] * inv(out[u]) % mod;
        q.pop();
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].v;
            a[v] = (a[v] + tmp) % mod;
            if (!--in[v])
                q.push(v);
        }
    }
}
signed main()
{
    scanf("%lld%lld%lld%lld",&n,&m,&r,&k);
    while (k--)
    {
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        out[u]++,in[v]++,ori[v]++;
        sum = (sum + w) % mod;
        adde(u,v,w);
    }
    sum = inv(sum);
    for (int i = 1; i <= m; i++)
        a[i] = b[i] = 1;
    topsort();
    for (int u = 1; u <= n - r; u++)
    {
        int q = a[u] * inv(out[u]) % mod,p = a[u] * inv(out[u] - 1) % mod;
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].v,w = e[i].w * sum % mod;
            b[u] = (b[u] + (p - q + mod) % mod * out[u] % mod * w % mod) % mod;
            b[v] = (b[v] - w * p % mod + mod) % mod;
        }
    }
    memcpy(in,ori,sizeof(int) * (n + 5));
    memcpy(a,b,sizeof(int) * (n + 5));
    topsort();
    for (int i = n - r + 1; i <= n; i++)
        printf("%lld ",a[i]);
    return 0;
}