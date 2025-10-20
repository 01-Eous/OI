#include<bits/extc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n;
char col[maxn];
bool vis[maxn];
int in[maxn],tmp[maxn];
vector<int> g[maxn];
void topsort(char ch)
{
    memcpy(tmp,in,sizeof(int) * (n + 5));
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (tmp[i] == 1 && col[i] == ch)
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        vis[u] = 1;
        q.pop();
        for (auto v : g[u])
            if (col[v] == ch)
                if (--in[v] == 1)
                    q.push(v);
    }
}
signed main()
{
    scanf("%d%s",&n,col + 1);
    for (int i = 1,u,v; i < n; i++)
    {
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
        in[u]++,in[v]++;
    }
    topsort('R');
    topsort('G');
    topsort('B');
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += !vis[i];
    printf("%d",ans);
    return 0;
}