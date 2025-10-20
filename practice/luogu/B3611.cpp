#include<bits/extc++.h>
using namespace std;
int n;
bool g[105][105],f[105][105];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> g[i][j];
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                g[i][j] |= g[i][k] && g[k][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cout << g[i][j] << " \n"[j == n];
    return 0;
}