#include<bits/extc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
using namespace std;
int n,l,r;
void solve()
{
    cin >> n >> l >> r;
    vector<int>a,b,c;
    int sum1,sum2,sum = 0,ans = inf;
    for (int i = 1,x; i <= n; i++)
    {
        cin >> x;
        if (i < l)
            a.push_back(x);
        else if (i > r)
            c.push_back(x);
        else
        {
            sum += x;
            b.push_back(x);
        }
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),greater<int>());
    sort(c.begin(),c.end());
    ans = min(ans,sum);
    sum1 = sum2 = 0;
    for (int i = 0; i < min(a.size(),b.size()); i++)
    {
        sum1 += a[i],sum2 += b[i];
        ans = min(ans,sum + sum1 - sum2);
    }
    sum1 = sum2 = 0;
    for (int i = 0; i < min(c.size(),b.size()); i++)
    {
        sum1 += c[i],sum2 += b[i];
        ans = min(ans,sum + sum1 - sum2);
    }
    cout << ans << '\n';
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