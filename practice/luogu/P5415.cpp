#include<bits/extc++.h>
using namespace std;
typedef double ld;
int n,m,k,lim;
ld a[105][105],ans[105];
int toint(int x,int y){return (x - 1) * (m + 1) + y + 1;}
void gauss(int n)
{
    for (int i = 1; i <= n; i++)
    {
        int pos = i;
        for (int j = i + 1; j <= n; j++)
            if (abs(a[pos][i]) < abs(a[j][i]))
                pos = j;
        swap(a[pos],a[i]);
        ld tmp = a[i][i];
        for (int j = i; j <= n + 1; j++)
            a[i][j] /= tmp;
        for (int j = i + 1; j <= n; j++)
        {
            tmp = a[j][i];
            for (int k = i; k <= n + 1; k++)
                a[j][k] -= tmp * a[i][k];
        }
    }
    ans[n] = a[n][n + 1];
    for (int i = n - 1; i >= 1; i--)
    {
        ans[i] = a[i][n + 1];
        for (int j = i + 1; j <= n; j++)
            ans[i] -= a[i][j] * ans[j];
    }
}
void solve()
{
    cin >> n >> m >> k;
    lim = n * (m + 1);
    for (int i = 1; i <= lim; i++)
        for (int j = 1; j <= lim + 1; j++)
            a[i][j] = 0;
    for (int i = 1; i <= lim; i++)
        ans[i] = 0;
    a[toint(1,m)][lim + 1] = a[toint(1,m)][toint(1,m)] = 1;
    for (int i = 2; i <= n; i++)
    {
        a[toint(i,m)][toint(i,m)] = 1;
        a[toint(i,m)][lim + 1] = 0;
    }
    for (int j = 0; j < m; j++)
    {
        a[toint(1,j)][toint(1,j)] = 1;
        a[toint(1,j)][toint(1,j + 1)] -= 0.25;
        a[toint(1,j)][toint(n - 2,1)] -= 0.75;
    }
    for (int j = 0; j < m; j++)
    {
        a[toint(2,j)][toint(2,j)] = 1;
        a[toint(2,j)][toint(1,1)] -= 0.25;
        a[toint(2,j)][toint(n - 2,j + 1)] -= 0.25;
        a[toint(2,j)][toint(n - 1,1)] -= 0.5;
    }
    for (int j = 0; j < m; j++)
    {
        a[toint(3,j)][toint(3,j)] = 1;
        a[toint(3,j)][toint(1,1)] -= 0.25;
        a[toint(3,j)][toint(n - 1,j + 1)] -= 0.25;
        a[toint(3,j)][toint(n - 1,1)] -= 0.25;
        a[toint(3,j)][toint(n,1)] -= 0.25;
    }
    for (int j = 0 ; j < m; j++)
    {
        a[toint(4,j)][toint(4,j)] = 1;
        a[toint(4,j)][toint(1,1)] -= 0.25;
        a[toint(4,j)][toint(n,j + 1)] -= 0.25;
        a[toint(4,j)][toint(n,1)] -= 0.5;
    }
    for (int i = 5; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[toint(i,j)][toint(i,j)] = 1;
            a[toint(i,j)][toint(i - 3,j + 1)] -= 0.25;
            a[toint(i,j)][toint(i - 3,1)] -= 0.75;
        }
    }
    gauss(lim);
    cout << ans[toint(k,0)] << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(6);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}