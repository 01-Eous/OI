#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 8e4 + 5;
const int maxm = 1e5 + 5;
int n;
int a[maxn],f[maxm],g[maxm];
vector<int> fac[maxm];
void init(int n = 1e5)
{
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i)
            fac[j].push_back(i);
    for (int i = 1; i <= n; i++)
        reverse(fac[i].begin(),fac[i].end());
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memset(f,0,sizeof f);
    memset(g,0,sizeof g);
    sort(a + 1,a + n + 1);
    int ans = 0,tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += tmp;
        for (auto j : fac[a[i]])
        {
            f[j] = g[j];
            for (auto k : fac[a[i] / j])
                if (k != 1)
                    f[j] -= f[k * j];
            tmp += j * f[j];
        }
        for (auto j : fac[a[i]])
            g[j]++;
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}