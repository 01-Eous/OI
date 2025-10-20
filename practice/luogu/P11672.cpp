#include<bits/extc++.h>
using namespace std;
const int maxn = 1005;
int n,x,y;
int a[maxn][maxn],cnt[maxn << 1];
int ans1[maxn << 1],ans2[maxn << 1];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            cnt[a[i][j]]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (cnt[a[i][j]] == 1)
            {
                if (!x)
                    x = i;
                else
                    y = i;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans1[a[x][i]] = cnt[a[x][i]] + 1;
        ans1[a[y][i]] = 2 * n - cnt[a[y][i]] + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        ans2[a[x][i]] = 2 * n - cnt[a[x][i]] + 1;
        ans2[a[y][i]] = cnt[a[y][i]] + 1;
    }
    char op = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!op && ans1[a[i][j]] ^ ans2[a[i][j]])
                op = ans1[a[i][j]] < ans2[a[i][j]] ? 1 : 2;
            if (op == 0 || op == 1)
                cout << ans1[a[i][j]];
            else
                cout << ans2[a[i][j]];
            cout << " \n"[j == n];
        }
    }
    return 0;
}