#include<bits/extc++.h>
using namespace std;
const int maxn = 1.5e5 + 5;
int n,m,len;
int a[maxn],sum[405][405];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    len = sqrt(n);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= len; i++)
        for (int j = 1; j <= n; j++)
            sum[i][j % i] += a[j];
    char op;
    int x,y;
    while (m--)
    {
        cin >> op >> x >> y;
        if (op == 'A')
        {
            if (x <= len)
                cout << sum[x][y] << '\n';
            else
            {
                int ans = 0;
                for (int i = y; i <= n; i += x)
                    ans += a[i];
                cout << ans << '\n';
            }
        }
        else
        {
            for (int i = 1; i <= len; i++)
                sum[i][x % i] += y - a[x];
            a[x] = y;
        }
    }
    return 0;
}