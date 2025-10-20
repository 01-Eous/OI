#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
using pii = pair<int,int>;
const int dir[4][2] = {1,0,-1,0,0,1,0,-1};
int n,m;
int sx,sy,tx,ty;
char mp[1005][1005];
int dis[1005][1005];
bool vis[1005][1005];
bool bound(int x,int y){return 1 <= x && x <= n && 1 <= y && y <= m;}
void bfs()
{
    memset(dis,0x3f,sizeof(dis));
    queue<pii> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j] == 'P')
            {
                dis[i][j] = 0;
                q.push({i,j});
            }
        }
    }
    while (!q.empty())
    {
        auto [x,y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dir[i][0],yy = y + dir[i][1];
            if (!bound(xx,yy))
                continue;
            if (dis[xx][yy] == inf)
            {
                dis[xx][yy] = dis[x][y] + 1;
                q.push({xx,yy});
            }
        }
    }
}
bool chk(int mid)
{
    assert(mid > 0);
    if (dis[sx][sy] < mid)
        return 0;
    memset(vis,0,sizeof(vis));
    queue<pii> q;
    vis[sx][sy] = 1;
    q.push({sx,sy});
    while (!q.empty())
    {
        auto [x,y] = q.front();
        q.pop();
        if (x == tx && y == ty)
            return 1;
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dir[i][0],yy = y + dir[i][1];
            if (!bound(xx,yy))
                continue;
            if (!vis[xx][yy] && dis[xx][yy] >= mid)
            {
                vis[xx][yy] = 1;
                q.push({xx,yy});
            }
        }
    }
    return 0;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == 'S')
                sx = i,sy = j;
            else if (mp[i][j] == 'F')
                tx = i,ty = j;
        }
    }
    bfs();
    int l = 1,r = n << 1,mid,ans = 0;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (chk(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    if (!ans)
        cout << "impossible";
    else
        cout << ans;
    return 0;
}