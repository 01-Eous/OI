#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n;
int a[55];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1,a + n + 1);
    int ans = 1;
    for (int i = 1; i <= n; i++)
        ans = ans * (a[i] - i + 1) % mod;
    cout << ans;
    return 0;
}