#include<bits/extc++.h>
using namespace std;
const int dir[2][2] = {-1,0,0,-1};
int n;
int a[55][55];
struct Klee
{
    int x,y;
    int c[6];
    Klee(int x,int y,int col[]):x(x),y(y){memcpy(c,col,sizeof c);}
};
bool bfs()
{
    int tmp[] = {a[n][n],-1,-1,-1,-1,-1};
    queue<Klee> q;
    q.push(Klee(n,n,tmp));
    while (!q.empty())
    {
        Klee u = q.front();
        q.pop();
        if (u.x == 1 && u.y == 1)
        {
            for (int i = 0; i < 6; i++)
                if (!~u.c[i])
                    u.c[i] = a[1][1];
            cout << "Yes\n";
            for (int i = 0; i < 6; i++)
                cout << u.c[i] << " \n"[i == 5];
            return 1;
        }
        for (int i = 0; i < 2; i++)
        {
            int tx = u.x + dir[i][0];
            int ty = u.y + dir[i][1];
            if (tx < 1 || tx > n || ty < 1 || ty > n)
                continue;
            if (i)
            {
                if (!~u.c[1] || u.c[1] == a[tx][ty])
                {
                    tmp[0] = a[tx][ty];
                    tmp[1] = u.c[5];
                    tmp[2] = u.c[2];
                    tmp[3] = u.c[3];
                    tmp[4] = u.c[0];
                    tmp[5] = u.c[4];
                    q.push(Klee(tx,ty,tmp));
                }
            }
            else
            {
                if (!~u.c[2] || u.c[2] == a[tx][ty])
                {
                    tmp[0] = a[tx][ty];
                    tmp[1] = u.c[1];
                    tmp[2] = u.c[5];
                    tmp[3] = u.c[0];
                    tmp[4] = u.c[4];
                    tmp[5] = u.c[3];
                    q.push(Klee(tx,ty,tmp));
                }
            }
        }
    }
    return 0;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    if (!bfs())
        cout << "No\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}