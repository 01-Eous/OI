#include<bits/extc++.h>
#define int long long
using namespace std;
int n;
int d[65];
pair<int,int> a[1005];
bool ins(int x)
{
    for (int i = 60; i >= 0; i--)
    {
        if (x & (1LL << i))
        {
            if (d[i])
                x ^= d[i];
            else
            {
                d[i] = x;
                break;
            }
        }
    }
    return x;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].second >> a[i].first;
    sort(a + 1,a + n + 1,greater<>());
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (ins(a[i].second))
            ans += a[i].first;
    cout << ans;
    return 0;
}