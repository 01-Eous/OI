#include<bits/extc++.h>
#define inf 0x3f3f3f3f
#define chkmin(x,y) x = min(x,y)
using namespace std;
const int maxn = 5e4 + 5;
int n,m,q;
int a[205],f[205][205];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(f,0x3f,sizeof(f));
    for (int i = 0; i < n; i++)
        cin >> a[i],f[i][i] = 0;
    while (m--)
    {
        int u,v,w;
        cin >> u >> v >> w;
        f[u][v] = f[v][u] = w;
    }
    cin >> q;
    while (q--)
    {
        static int u = 0;
        int x,y,z;
        cin >> x >> y >> z;
        while (u < n && a[u] <= z)
        {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    chkmin(f[i][j],f[i][u] + f[u][j]);
            u++;
        }
        if (f[x][y] == inf || a[x] > z || a[y] > z)
            cout << "-1\n";
        else
            cout << f[x][y] << '\n';
    }
    return 0;
}