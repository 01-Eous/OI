#include<bits/extc++.h>
using namespace std;
const int maxn = 1e7 + 5;
int n,idx;
bool vis[maxn];
int stk[maxn],ans[1005],top;
int pr[maxn],low[maxn],mu[maxn],sum[maxn];
struct query
{
    int v,id;
    bool operator<(const query &x){return v < x.v;}
}a[1005];
int read()
{
    int x = 0,f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = x * 10 + (ch ^ 48); ch = getchar();}
    return x * f;
}
void init(int n = 1e7)
{
    mu[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            pr[++idx] = i;
            low[i] = i;
            mu[i] = -1;
        }
        for (int j = 1; j <= idx && i * pr[j] <= n; j++)
        {
            vis[i * pr[j]] = 1;
            low[i * pr[j]] = pr[j];
            if (i % pr[j] == 0)
                break;
            mu[i * pr[j]] = -mu[i];
        }
    }
}
int dfs(int val,int pos,int x)
{
    if (pos > top)
        return mu[val] * (sum[val] += mu[x]);
    return dfs(val,pos + 1,x) + dfs(val * stk[pos],pos + 1,x);
}
signed main()
{
    init();
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = {read(),i};
    sort(a + 1,a + n + 1);
    int id = 1,res = 0;
    for (int i = 1; i <= a[n].v; i++)
    {
        int tmp = 0;
        if (mu[i])
        {
            top = 0;
            for (int x = i; x > 1; x /= low[x])
                stk[++top] = low[x];
            tmp = dfs(1,1,i);
        }
        res += tmp * mu[i];
        while (i == a[id].v)
            ans[a[id++].id] = res;
    }
    for (int i = 1; i <= n; i++)
        printf("%d\n",ans[i]);
    return 0;
}