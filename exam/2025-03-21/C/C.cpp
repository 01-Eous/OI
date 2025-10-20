#include<bits/extc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxn = 1e6 + 5;
const int dir[4][2] = {1,0,-1,0,0,1,0,-1};
int n,m,cnt,idx;
bool mp[maxn],vis[maxn],ans[maxn];
int bel[maxn],dis[maxn],low[maxn],head[maxn];
struct edge{int v,w,nxt;}e[maxn << 1];
int toint(int x,int y){return (x - 1) * m + y;}
bool legal(int x,int y){return x >= 1 && y >= 1 && x <= n && y <= m;}
void dfs(int x,int y,int id)
{
    bel[toint(x,y)] = id;
    for (int i = 0; i < 4; i++)
    {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (legal(tx,ty) && mp[toint(tx,ty)] && !bel[toint(tx,ty)])
            dfs(tx,ty,id);
    }
}
void adde(int u,int v,int w)
{
    e[++idx] = {v,w,head[u]};
    head[u] = idx;
}
void dij(int st)
{
    priority_queue<pii,vector<pii>,greater<pii>> q;
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    dis[st] = 0;
    q.push({dis[st],st});
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].v,w = e[i].w;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push({dis[v],v});
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    char ch;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> ch;
            mp[toint(i,j)] = ch == '#';
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!bel[toint(i,j)] && mp[toint(i,j)])
                dfs(i,j,++cnt);
    // low[j] 表示 j 所在的这一列最下面的那个位置的 i
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!mp[toint(i,j)])
                continue;
            if (low[j] && bel[toint(i,j)] != bel[toint(low[j],j)])
                adde(bel[toint(i,j)],bel[toint(low[j],j)],i - low[j] - 1);
            low[j] = i;
        }
    }
    for (int j = 1; j <= m; j++)
        if (low[j])
            adde(0,bel[toint(low[j],j)],n - low[j]);
    dij(0);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (mp[toint(i,j)])
                ans[toint(i + dis[bel[toint(i,j)]],j)] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << ".#"[ans[toint(i,j)]];
        cout << '\n';
    }
    return 0;
}