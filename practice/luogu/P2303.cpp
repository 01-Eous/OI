#include<bits/extc++.h>
#define int long long
using namespace std;
int n;
int phi(int x)
{
    int up = x,res = x;
    for (int i = 2; i * i <= up; i++)
    {
        if (x % i == 0)
        {
            res = res / i * (i - 1);
            while (x % i == 0)
                x /= i;
        }
    }
    if (x != 1)
        res = res / x * (x - 1);
    return res;
}
signed main()
{
    cin >> n;
    int ans = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i)
            continue;
        int x = i,y = n / i;
        ans += x * phi(y);
        if (x != y)
            ans += y * phi(x);
    }
    cout << ans;
    return 0;
}