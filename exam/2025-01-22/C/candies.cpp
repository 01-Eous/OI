#include<bits/extc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n,sum;
int a[205];
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1,a + n + 1);
    vector<int>f(sum + 5);
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = sum; j >= a[i]; j--)
            f[j] = (f[j] + f[j - a[i]]) % mod;
    int _max = 0,x,y;
    for (int i = 1; i <= n; i++)
    {
        auto tmp = f;
        for (int j = a[i]; j <= sum; j++)
            tmp[j] = (tmp[j] - tmp[j - a[i]]) % mod;
        int cnt = 0;
        for (int j = 1; j <= sum; j++)
            cnt += bool(tmp[j]);
        if (cnt > _max)
        {
            _max = cnt;
            x = a[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == x)
        {
            a[i] = 0;
            break;
        }
    }
    for (int i = 1; i <= n; i++)
        a[i + n] = -a[i];
    n <<= 1;
    bitset<7000 * 100 + 5>dp;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > 0)
            dp |= (dp << a[i]);
        else
            dp |= (dp >> -a[i]);
    }
    for (int i = 1; i <= sum; i++)
    {
        if (!dp[i])
        {
            y = i;
            break;
        }
    }
    cout << x << " " << y;
    return 0;
}