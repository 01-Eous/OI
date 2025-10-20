#include<bits/extc++.h>
using namespace std;
using pii = pair<int,int>;
const int dir[4][2] = {1,0,-1,0,0,1,0,-1};
int n,m;
int hei[505][505];
bool mp[505][505],vis[505][505];
int bound(int x,int y){return 1 <= x && x <= n && 1 <= y && y <= m;}
void bfs(int d)
{
    queue<pii> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j])
            {
                vis[i][j] = 1;
                q.push({i,j});
                goto Nahida;
            }
        }
    }
    Nahida:
    while (!q.empty())
    {
        int i = q.front().first,j = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int x = i + dir[k][0],y = j + dir[k][1];
            if (bound(x,y) && !vis[x][y] && abs(hei[i][j] - hei[x][y]) <= d)
            {
                vis[x][y] = 1;
                q.push({x,y});
            }
        }
    }
}
bool chk(int d)
{
    memset(vis,0,sizeof(vis));
    bfs(d);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (mp[i][j] && !vis[i][j])
                return 0;
    return 1;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> hei[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];
    int l = 0,r = 1e9,mid,ans = 1e9;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (chk(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans;
    return 0;
}