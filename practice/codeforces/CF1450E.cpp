#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef pair<int,int> pii;
int n,m;
int u[2005],v[2005];
int dis[205][205];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(dis,0x3f,sizeof dis);
    for (int i = 1; i <= n; i++)
        dis[i][i] = 0;
    for (int i = 1,b; i <= m; i++)
    {
        cin >> u[i] >> v[i] >> b;
        dis[u[i]][v[i]] = 1;
        dis[v[i]][u[i]] = b ? -1 : 1;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][j] > dis[i][k] + dis[k][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    if (dis[i][j] < -inf)
                    {
                        cout << "NO";
                        return 0;
                    }
                }
            }
        }
    }
    pii ans = {-1,1};
    for (int i = 1; i <= n; i++)
    {
        if (dis[i][i] < 0)
        {
            cout << "NO";
            return 0;
        }
        for (int j = 1; j <= n; j++)
            ans = max(ans,{dis[i][j],i});
    }
    for (int i = 1; i <= m; i++)
    {
        if (dis[ans.second][u[i]] == dis[ans.second][v[i]])
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n" << ans.first << '\n';
    for (int i = 1; i <= n; i++)
        cout << dis[ans.second][i] << ' ';
    return 0;
}