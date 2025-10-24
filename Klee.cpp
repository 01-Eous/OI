#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;
int cur, n, m, s, t;
int head[1005], p[1005];
int dis[1005][1005], nxt[1005][1005];
bool vis[1005], visit[1005][1005];
double f[1005][1005];
struct EDGE
{
    int v, nxt;
} e[2005];
#define INF 0x3f3f3f3f

void add(int a, int b)
{
    cur++;
    e[cur].v = b;
    e[cur].nxt = head[a];
    head[a] = cur;
}

queue<int> q;
void SPFA(int *dis, int *nxt, int s)
{
    dis[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int h = head[u]; h != -1; h = e[h].nxt)
        {
            int v = e[h].v;
            if (dis[u] + 1 < dis[v])
            {
                dis[v] = dis[u] + 1;
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
}
double dfs(int u, int w)
{
    if (u == w)
        return 0;
    if (f[u][w])
        return f[u][w];
    int fi = nxt[u][w], se = nxt[fi][w];
    if (fi == w || se == w)
        return 1;
    f[u][w] = 1;
    for (int h = head[w]; h != -1; h = e[h].nxt)
    {
        int v = e[h].v;
        f[u][w] += dfs(se, v) / (p[w] + 1);
    }
    f[u][w] += dfs(se, w) / (p[w] + 1);
    return f[u][w];
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    memset(head, -1, sizeof head);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
        p[a]++;
        p[b]++;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            dis[i][j] = nxt[i][j] = INF;
    }
    for (int i = 1; i <= n; i++)
    {
        SPFA(dis[i], nxt[i], i);
    }
    for (int i = 1; i <= n; i++)
        for (int h = head[i]; ~h; h = e[h].nxt)
        {
            int t = e[h].v;
            for (int j = 1; j <= n; j++)
                if (dis[i][j] - 1 == dis[t][j])
                {
                    nxt[i][j] = min(nxt[i][j], t);
                }
        }
    printf("%.3lf", dfs(s, t));
    return 0;
}
