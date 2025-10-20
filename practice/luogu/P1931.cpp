#include<bits/extc++.h>
using namespace std;
int n,m;
double dis[35][35];
map<string,int>id;
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        id[s] = i;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dis[i][j] = 0;
    for (int i = 1; i <= n; i++)
        dis[i][i] = 1.0;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        string s1,s2;
        double x;
        cin >> s1 >> x >> s2;
        dis[id[s1]][id[s2]] = x;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dis[i][j] < dis[i][k] * dis[k][j])
                    dis[i][j] = dis[i][k] * dis[k][j];
    for (int i = 1; i <= n; i++)
    {
        if (dis[i][i] > 1.0)
        {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int t = 0;
    while (n)
    {
        cout << "Case " << ++t << ": ";
        solve();
        cin >> n;
    }
    return 0;
}