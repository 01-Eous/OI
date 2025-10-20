#include<bits/extc++.h>
#define int long long
using namespace std;
int n;
int a[305],c[305];
map<int,int> dp;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++)
    {
        if (dp.find(a[i]) == dp.end())
            dp[a[i]] = c[i];
        else
            dp[a[i]] = min(dp[a[i]],c[i]);
        for (auto j : dp)
        {
            int val = j.first,cost = j.second;
            val = __gcd(val,a[i]);
            if (dp.find(val) == dp.end())
                dp[val] = cost + c[i];
            else
                dp[val] = min(dp[val],cost + c[i]);
        }
    }
    cout << (dp.find(1) == dp.end() ? -1 : dp[1]);
    return 0;
}