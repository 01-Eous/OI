#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cmath>
#define int long long
using namespace std;
typedef long double ld;
const ld eps = 1e-10;
const ld inf = 1e18;
int n,m,st,ed,dir;
bool vis[205];
ld p[205],a[205][205],ans[205];
int read()
{
    int f = 1,x = 0;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    return x * f;
}
bool bfs()
{
    memset(vis,0,sizeof vis);
    queue<int> q;
    vis[st] = 1;
    q.push(st);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 1; i <= m; i++)
        {
            if (p[i] < eps)
                continue;
            int v = (u + i) % n;
            if (!vis[v])
            {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    if (!vis[ed] && !vis[((n - ed) % n + n) % n])
        return 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;
        a[i][i] = 1;
        a[i][n] = inf;
    }
    return 1;
}
bool gauss()
{
    for (int i = 0; i < n; i++)
    {
        int pos = i;
        for (int j = i + 1; j < n; j++)
            if (abs(a[pos][i]) < abs(a[j][i]))
                pos = j;
        if (abs(a[pos][i]) < eps)
            return 0;
        swap(a[pos],a[i]);
        ld tmp = a[i][i];
        for (int j = i; j <= n; j++)
            a[i][j] /= tmp;
        for (int j = i + 1; j < n; j++)
        {
            tmp = a[j][i];
            for (int k = i; k <= n; k++)
                a[j][k] -= tmp * a[i][k];
        }
    }
    ans[n - 1] = a[n - 1][n];
    for (int i = n - 2; i >= 0; i--)
    {
        ans[i] = a[i][n];
        for (int j = i + 1; j < n; j++)
            ans[i] -= a[i][j] * ans[j];
    }
    return 1;
}
void solve()
{
    n = read(),m = read(),ed = read(),st = read(),dir = read();
    for (int i = 1; i <= m; i++)
        p[i] = read() / 100.0;
    if (n == 1)
        return (void)puts("0.00");
    n = 2 * (n - 1);
    if (dir == -1)
    {
        if (!st)
            dir = 0;
        else
            dir = 1;
    }
    if (dir >= 1)
        st = (n - st) % n;
    if (st == ed)
        return (void)puts("0.00");
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
            a[i][j] = 0;
    if (!bfs())
        return (void)puts("Impossible !");
    for (int u = 0; u < n; u++)
    {
        if (!vis[u])
            continue;
        a[u][u] = 1;
        if (u == ed || u == (n - ed) % n)
            continue;
        for (int j = 1; j <= m; j++)
        {
            int v = ((u + j) % n + n) % n;
            a[u][v] += -p[j];
            a[u][n] += p[j] * j;
        }
    }
    if (!gauss() || ans[st] >= inf)
        return (void)puts("Impossible !");
    printf("%.2Lf\n",ans[st]);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}