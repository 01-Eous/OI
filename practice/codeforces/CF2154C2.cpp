#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 2e5 + 5;
int n;
int a[maxn],b[maxn],cnt[maxn],p[maxn];
vector<int> fac[maxn];
stack<int,vector<int>> stk;
void init(int n = 2e5)
{
    for (int i = 2; i <= n; i++)
        if (fac[i].empty())
            for (int j = i; j <= n; j += i)
                fac[j].emplace_back(i);
}
bool cmp(int x,int y){return b[x] < b[y];}
void solve()
{
    cin >> n;
    int ans = inf;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (auto j : fac[a[i]])
        {
            stk.push(j);
            if (cnt[j])
                ans = 0;
            cnt[j]++;
        }
    }
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
    {
        for (auto j : fac[a[i]])
            cnt[j]--;
        for (auto j : fac[a[i] + 1])
            if (cnt[j])
                ans = min(ans,b[i]);
        for (auto j : fac[a[i]])
            cnt[j]++;
    }
    iota(p + 1,p + n + 1,1);
    sort(p + 1,p + n + 1,cmp);
    ans = min(ans,b[p[1]] + b[p[2]]);
    for (int i = 2; i <= n; i++)
    {
        for (auto j : fac[a[p[i]]])
        {
            int val = (j - a[p[1]] % j) % j;
            ans = min(ans,val * b[p[1]]);
        }
    }
    while (!stk.empty())
    {
        cnt[stk.top()] = 0;
        stk.pop();
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