#include<bits/extc++.h>
#define int long long
using namespace std;
int n,k;
bool chk(int mid,vector<int> a,vector<int> b)
{
    stack<int> stk;
    int res = 0;
    for (int i = 0; i < (n << 1); i++)
    {
        if (a[i])
            stk.push(i);
        while (!stk.empty() && b[i])
        {
            int cur = stk.top();
            if (i - cur + 1 > mid)
            {
                res += a[cur];
                a[cur] = 0;
                if (cur < n)
                    a[cur + n] = 0;
                stk.pop();
            }
            else
            {
                int _min = min(a[cur],b[i]);
                a[cur] -= _min,b[i] -= _min;
                if (i < n)
                    a[cur + n] -= _min,b[i + n] -= _min;
                if (!a[cur])
                    stk.pop();
            }
        }
    }
    return res <= k;
}
void solve()
{
    cin >> n >> k;
    vector<int> a(n << 1),b(n << 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        b[i + n] = b[i];
    }
    int l = 0,r = n,mid,ans = n;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (chk(mid,a,b))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
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