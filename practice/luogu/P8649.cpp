#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n,k;
int cnt[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    cnt[0] = 1;
    int sum = 0,ans = 0;
    for (int i = 1,x; i <= n; i++)
    {
        cin >> x;
        sum = (sum + x) % k;
        ans += cnt[sum]++;
    }
    cout << ans;
    return 0;
}