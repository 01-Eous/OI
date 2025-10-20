#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
int n,m;
bool b[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1,x; i <= m; i++)
    {
        cin >> x;
        b[x] = 1;
    }
    int ans = 1,tmp = 1;
    for (int i = n; i >= 1; i--)
    {
        ans = ans * tmp % mod;
        tmp += b[i] ? -1 : 1;
    }
    cout << ans;
    return 0;
}