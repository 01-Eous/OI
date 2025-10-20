#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n,q;
int a[maxn];
vector<int> apr[maxn],fac[maxn];
void init(int n = 1e5)
{
    for (int i = 2; i <= n; i++)
        for (int j = i; j <= n; j += i)
            fac[j].push_back(i);
}
int next(int k,int l)
{
    int res = n + 1;
    for (auto x : fac[k])
        if (auto it = upper_bound(apr[x].begin(),apr[x].end(),l); it != apr[x].end())
            res = min(res,*it);
    return res;
}
void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        apr[a[i]].push_back(i);
    }
    int k,l,r;
    while (q--)
    {
        cin >> k >> l >> r;
        l--;
        int ans = -k,nxt;
        while ((nxt = next(k,l)) <= r)
        {
            ans += k * (nxt - l);
            while (k % a[nxt] == 0)
                k /= a[nxt];
            l = nxt;
        }
        ans += (r - l + 1) * k;
        cout << ans << '\n';
    }
    for (int i = 1; i <= n; i++)
        apr[a[i]].clear();
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