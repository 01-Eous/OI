#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e4 + 5;
const int maxm = 1e6 + 5;
int n;
int apr[maxm];
int a[maxn],b[maxn];
bool chk(int x)
{
    for (int i = 1; i <= n; i++)
        apr[b[i]]++;
    bool fl = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!apr[a[i] % x])
        {
            fl = 0;
            break;
        }
        apr[a[i] % x]--;
    }
    for (int i = 1; i <= n; i++)
        apr[b[i]] = 0;
    return fl;
}
void solve()
{
    cin >> n;
    int dlt = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dlt += a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        dlt -= b[i];
    }
    if (!dlt)
    {
        cout << (chk(1919810) ? "1910810\n" : "-1\n");
        return;
    }
    for (int i = 1; i * i <= dlt; i++)
    {
        if (dlt % i)
            continue;
        if (chk(i))
            return cout << i << '\n',void();
        else if (dlt / i <= 1e6 && chk(dlt / i))
            return cout << dlt / i << '\n',void(); 
    }
    cout << "-1\n";
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