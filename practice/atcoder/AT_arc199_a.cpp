#include<bits/extc++.h>
using namespace std;
int n;
int r[1005],c[1005];
bool a[1005][1005],x[1005],y[1005];
void solve()
{
    cin >> n;
    memset(x,0,sizeof(bool) * (n + 5));
    memset(y,0,sizeof(bool) * (n + 5));
    char ch;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> ch;
            a[i][j] = ch == '1';
        }
    }
        
    for (int i = 1; i <= n; i++)
        cin >> r[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];

    for (int j = 1; j <= n; j++)
    {
        if (a[1][j])
        {
            for (int i = 1; i <= n; i++)
                a[i][j] ^= 1;
            y[j] ^= 1;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
            sum += a[i][j];
        if (sum < (n + 1) >> 1)
            continue;
        
        for (int j = 1; j <= n; j++)
            a[i][j] ^= 1;
        x[i] ^= 1;
    }
    
    for (int j = 1; j <= n; j++)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
            sum += a[i][j];
        if (sum < (n + 1) >> 1)
            continue;
        
        for (int i = 1; i <= n; i++)
            a[i][j] ^= 1;
        y[j] ^= 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            r[i] -= a[i][j];
            c[j] -= a[i][j];
        }        
    }
    
    for (int i = 1; i <= n; i++)
        if (r[i] || c[i])
            return (void)(cout << "No\n");
    
    cout << "Yes\n";
    for (int i = 1; i <= n; i++)
        cout << x[i];
    cout << '\n';
    for (int i = 1; i <= n; i++)
        cout << y[i];
    cout << '\n';
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