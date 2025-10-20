#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 1e5 + 5;
int n,k,cnt;
int a[maxn];
void solve()
{
    cin >> n >> k;
    int sum = 0,min1 = inf,max1 = -inf;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
        min1 = min(min1,a[i]);
        if (max1 < a[i])
        {
            cnt = 1;
            max1 = a[i];
        }
        else if (max1 == a[i])
            cnt++;
    }
    if (max1 - min1 > k + 1 || (max1 - min1 > k && cnt > 1))
        puts("Jerry");
    else if (sum & 1)
        puts("Tom");
    else
        puts("Jerry");
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
