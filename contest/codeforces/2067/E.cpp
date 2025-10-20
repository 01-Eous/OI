#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,cnt0;
void solve()
{
    cin >> n;
    vector<int>a(n + 5);
    cnt0 = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt0 += a[i] == 0;
    }
    if (cnt0 == 0)
    {
        cout << n << '\n';
        return;
    }
    bool fl = 1;
    int idx = 0;
    vector<int>b(n + 5,0),pmin(n + 5,0),smex(n + 5,0);
    vector<bool>apr(n + 5,0);
    pmin[0] = inf;
    for (int i = 1; i <= n; i++)
    {
        if (fl || a[i])
        {
            b[++idx] = a[i];
            if (!a[i])
                fl = 0;
        }
    }
    for (int i = 1; i <= idx; i++)
        pmin[i] = min(pmin[i - 1],b[i]);
    int mex = 0;
    for (int i = idx; i >= 1; i--)
    {
        if (b[i] <= n)
            apr[b[i]] = 1;
        while (apr[mex])
            mex++;
        smex[i] = mex;
    }
    fl = 1;
    for (int i = 1; i < idx; i++)
    {
        if (pmin[i] < smex[i + 1])
        {
            fl = 0;
            break;
        }
    }
    if (fl)
        cout << n - cnt0 + 1 << '\n';
    else
        cout << n - cnt0 << '\n';
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