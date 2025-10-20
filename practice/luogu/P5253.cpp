#include<bits/extc++.h>
#define int long long
using namespace std;
int n;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int ans = 1;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i)
            continue;
        int tmp = 0;
        while (n % i == 0)
        {
            tmp++;
            n /= i;
        }
        ans *= tmp << 1 | 1;
    }
    if (n > 1)
        ans *= 3;
    cout << ((ans + 1) >> 1);
    return 0;
}