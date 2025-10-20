#include<bits/extc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n,m;
int a[maxn],b[maxn];
void solve()
{
    cin >> n >> m;
    multiset<int,greater<int>>st1,st2;
    int sum1 = 0,sum2 = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        st1.insert(a[i]);
        sum1 += a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        st2.insert(b[i]);
        sum2 += b[i];
    }
    if (sum1 != sum2)
    {
        cout << "NO\n";
        return;
    }
    while (!st1.empty() || !st2.empty())
    {
        int x = *st1.begin(),y = *st2.begin();
        if (x == y)
        {
            st1.erase(st1.find(x));
            st2.erase(st2.find(y));
        }
        else if (x < y)
        {
            st2.erase(st2.find(y));
            st2.insert(y >> 1);
            st2.insert((y + 1) >> 1);
        }
        else
        {
            cout << "NO\n";
            return;
        }
    }
    if (st1.empty() && st2.empty())
        cout << "YES\n";
    else
        cout << "NO\n";
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