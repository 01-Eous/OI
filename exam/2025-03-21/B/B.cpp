#include<bits/extc++.h>
#define int long long
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
using namespace std;
typedef pair<int,int> pii;
const int maxn = 8e5 + 5;
int n,m;
bool vis[maxn];
int dis[maxn],head[maxn],idx;
struct edge{int v,w,nxt;}e[maxn * 5];
int toint(int u,int x){return u + (x - 1) * n;}
void adde(int u,int v,int w)
{
    e[++idx] = {v,w,head[u]};
    head[u] = idx;
}
void add(int u,int v,int w)
{
    adde(toint(u,1),toint(v,1),w);
    adde(toint(u,2),toint(v,2),w);
    adde(toint(u,3),toint(v,3),w);
    adde(toint(u,4),toint(v,4),w);

    adde(toint(u,1),toint(v,3),w << 1);
    adde(toint(u,2),toint(v,4),w << 1);

    adde(toint(u,1),toint(v,2),0);
    adde(toint(u,3),toint(v,4),0);

    adde(toint(u,1),toint(v,4),w);
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
    int u,v,w;
    while (m--)
    {
        cin >> u >> v >> w;
        add(u,v,w);
        add(v,u,w);
    }
    dij(1);
    for (int i = 2; i <= n; i++)
        cout << dis[toint(i,4)] << ' ';
    return 0;
}