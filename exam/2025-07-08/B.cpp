#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 5e5 + 5;
const int dir[4][2] = {-1,0,0,1,1,0,0,-1};
int n,m,q,idx;
char mp[maxn];
int id[maxn][4],nxt[maxn << 2],cir[maxn << 2];
int toint(int x,int y){return (x - 1) * m + y;}
bool bound(int x,int y){return 1 <= x && x <= n && 1 <= y && y <= m;}
bool chk(int x,int y){return bound(x,y) && mp[toint(x,y)] == '.';}
signed main()
{
    freopen("pokemon.in","r",stdin);
    freopen("pokemon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mp[toint(i,j)];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (mp[toint(i,j)] == '.')
                for (int p = 0; p < 4; p++)
                    if (int x = i + dir[p][0],y = j + dir[p][1]; chk(x,y))
                        id[toint(i,j)][p] = ++idx;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int p = 0; p < 4; p++)
            {
                if (!id[toint(i,j)][p])
                    continue;
                int x = i + dir[p][0],y = j + dir[p][1];
                if (!chk(x,y))
                    continue;
                int u = toint(i,j),v = toint(x,y);
                int r = (p + 1) % 4,l = (p + 3) % 4;
                int xr = x + dir[r][0],yr = y + dir[r][1];  // right
                int xs = x + dir[p][0],ys = y + dir[p][1];  // straight
                int xl = x + dir[l][0],yl = y + dir[l][1];  // left

                if (chk(xr,yr))                             // right
                    nxt[id[u][p]] = id[v][r];
                else if (chk(xs,ys))                        // straight
                    nxt[id[u][p]] = id[v][p];
                else if (chk(xl,yl))                        // left
                    nxt[id[u][p]] = id[v][l];
                else                                        // back
                    nxt[id[u][p]] = id[v][(p + 2) % 4];
            }
        }
    }
    int cnt = 0;
    cir[1] = ++cnt;
    for (int i = nxt[1]; i != 1; i = nxt[i])
        cir[i] = ++cnt;
    cin >> q;
    int sx,sy,tx,ty;
    char d;
    while (q--)
    {
        cin >> sx >> sy >> tx >> ty >> d;
        if (d == 'U')
            d = 0;
        else if (d == 'R')
            d = 1;
        else if (d == 'D')
            d = 2;
        else
            d = 3;
        int st = cir[id[toint(sx,sy)][d]],ed,ans = inf;
        for (int p = 0; p < 4; p++)
        {
            if (id[toint(tx,ty)][p])
            {
                ed = cir[id[toint(tx,ty)][p]];
                if (ed >= st)
                    ans = min(ans,ed - st);
                else
                    ans = min(ans,ed + cnt - st);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}