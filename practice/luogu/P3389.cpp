#include<bits/extc++.h>
using namespace std;
typedef double ld;
const ld eps = 1e-8;
int n;
ld a[105][105],ans[105];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n + 1; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
    {
        int m = i;
        for (int j = i + 1; j <= n; j++)
            if (abs(a[m][i]) < abs(a[j][i]))
                m = j;
        if (abs(a[m][i]) < eps)
            return cout << "No Solution",0;
        swap(a[m],a[i]);
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
    cout << fixed << setprecision(2);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
    return 0;
}