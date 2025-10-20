#include<bits/extc++.h>
using namespace std;
typedef double ld;
int n,m;
ld d;
ld a[65][65],ans[65];
void gauss()
{
    for (int i = 1; i <= n; i++)
    {
        int pos = i;
        for (int j = i + 1; j <= n; j++)
            if (fabs(a[pos][i]) < fabs(a[j][i]))
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
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin >> d >> a[1][n + 1] >> a[n][n + 1];
    a[1][1] = a[n][n] = 1;
    for (int i = 2; i < n; i++)
    {
        a[i][i - 1] = -0.5;
        a[i][i] = 1;
        a[i][i + 1] = 0.5;
        a[i][n + 1] = d;
    }
    gauss();
    cout << fixed << setprecision(3) << ans[m];
    return 0;
}