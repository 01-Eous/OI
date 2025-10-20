#include<bits/extc++.h>
#define int long long
using namespace std;
int n;
int a[155];
int c[155][155];
void init()
{
    for (int i = 0; i <= n; i++)
        c[i][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n,init();
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i] - 1;
        if (!a[i] && n != 1)
            return cout << '0',0;
    }
    if (n == 1)
        return cout << !a[1],0;
    if (sum != n - 2)
        return cout << '0',0;
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= c[sum][a[i] - 1];
        sum -= a[i] - 1;
    }
    cout << ans;
    return 0;
}