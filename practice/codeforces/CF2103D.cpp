#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 5e5 + 5;
int n,idx,tim,lg;
int a[maxn],head[maxn];
int in[maxn],dis[maxn],l[maxn],r[maxn];
struct edge{int v,nxt;}e[maxn];
void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
void topsort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (!in[i])
        {
            dis[i] = ++tim;
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].v;
            if (!--in[v])
            {
                dis[v] = ++tim;
                q.push(v);
            }
        }
    }
}
void solve()
{
    scanf("%lld",&n);
    idx = tim = 0;
    fill(in + 1,in + n + 1,0);
    fill(dis + 1,dis + n + 1,inf);
    fill(head + 1,head + n + 1,0);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        a[i] = ~a[i] ? a[i] : inf;
        l[i] = i - 1,r[i] = i + 1;
    }
    lg = __lg(n) + 1;
    for (int i = 1; i <= lg; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[j] > i)
            {
                if (i & 1)
                {
                    if (l[j])
                        adde(j,l[j]),in[l[j]]++;
                    if (r[j] <= n)
                        adde(j,r[j]),in[r[j]]++;
                }
                else
                {
                    if (l[j])
                        adde(l[j],j),in[j]++;
                    if (r[j] <= n)
                        adde(r[j],j),in[j]++;
                }
            }
        }
        bool fl = 0;
        for (int j = 1; j <= n; j++)
        {
            if (a[j] == i)
            {
                int k = r[j];
                while (k <= n && a[k] == i)
                {
                    if (!fl)
                    {
                        if (i & 1)
                            adde(k,l[k]),in[l[k]]++;
                        else
                            adde(l[k],k),in[k]++;
                    }
                    else
                    {
                        if (i & 1)
                            adde(l[k],k),in[k]++;
                        else
                            adde(k,l[k]),in[l[k]]++;
                    }
                    k = r[k];
                }
                j = k;
            }
            if (a[j] >= i)
                fl = 1;
        }
        for (int j = 1; j <= n; j++)
        {
            if (a[j] == i)
            {
                l[r[j]] = l[j];
                r[l[j]] = r[j];
            }
        }
    }
    topsort();
    for (int i = 1; i <= n; i++)
        printf("%lld%c",dis[i]," \n"[i == n]);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}
