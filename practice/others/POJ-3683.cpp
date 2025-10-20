#include<stack>
#include<vector>
#include<cstdio>
using namespace std;
typedef pair<int,int> pii;
const int maxn = 2005;
int n;
pii a[maxn];
bool vis[maxn];
int st[maxn],top;
vector<int>g[maxn];
bool cross(int x,int y)
{
    if (a[x].second <= a[y].first || a[x].first >= a[y].second)
        return 0;
    else
        return 1;
}
bool dfs(int u)
{
    if (vis[u ^ 1])
        return 0;
    if (vis[u])
        return 1;
    vis[u] = 1;
    st[++top] = u;
    for (vector<int>::iterator v = g[u].begin(); v != g[u].end(); v++)
        if (!dfs(*v))
            return 0;
    return 1;
}
bool check()
{
    for (int i = 0; i < (n << 1); i += 2)
    {
        if (!vis[i] && !vis[i | 1])
        {
            top = 0;
            if (!dfs(i))
            {
                while (top)
                    vis[st[top--]] = 0;
                if (!dfs(i | 1))
                    return 0;
            }
        }
    }
    return 1;
}
void solve()
{
    fill(vis,vis + (n << 1),0);
    fill(g,g + (n << 1),vector<int>());
    int h1,m1,h2,m2,d;
    for (int i = 0; i < n; i++)
    {
        scanf("%d:%d %d:%d %d",&h1,&m1,&h2,&m2,&d);
        a[i << 1].first = h1 * 60 + m1;
        a[i << 1].second = a[i << 1].first + d;
        a[i << 1 | 1].second = h2 * 60 + m2;
        a[i << 1 | 1].first = a[i << 1 | 1].second - d;
    }
    for (int i = 0; i < (n << 1); i += 2)
    {
        for (int j = 0; j < (n << 1); j += 2)
        {
            if (i == j)
                continue;
            if (cross(i,j))
            {
                g[i].push_back(j | 1);
                g[j].push_back(i | 1);
            }
            if (cross(i,j | 1))
            {
                g[i].push_back(j);
                g[j | 1].push_back(i | 1);
            }
            if (cross(i | 1,j))
            {
                g[j].push_back(i);
                g[i | 1].push_back(j | 1);
            }
            if (cross(i | 1,j | 1))
            {
                g[i | 1].push_back(j);
                g[j | 1].push_back(i);
            }
        }
    }
    if (check())
    {
        puts("YES");
        for (int i = 0; i < n; i++)
        {
            if (vis[i << 1])
                printf("%02d:%02d %02d:%02d\n",a[i << 1].first / 60,a[i << 1].first % 60,a[i << 1].second / 60,a[i << 1].second % 60);
            else
                printf("%02d:%02d %02d:%02d\n",a[i << 1 | 1].first / 60,a[i << 1 | 1].first % 60,a[i << 1 | 1].second / 60,a[i << 1 | 1].second % 60);
        }
    }
    else
        puts("NO");
}
signed main()
{
    while (scanf("%d",&n) != EOF)
        solve();
    return 0;
}