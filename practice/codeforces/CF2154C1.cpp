#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
using pii = pair<int,int>;
const int maxn = 2e5 + 5;
int n;
pii a[maxn << 1];
int b[maxn],min1[maxn];
stack<int,vector<int>> stk;
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
        a[i].second = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        a[i + n].first = a[i].first + 1;
        a[i + n].second = b[i];
    }
    int ans = inf;
    for (int i = 1; i <= n << 1; i++)
    {
        for (int j = 1; j * j <= a[i].first; j++)
        {
            if (a[i].first % j)
                continue;
            int x = j;
            if (x != 1)
            {
                stk.push(x);
                ans = min(ans,a[i].second + min1[x]);
                min1[x] = min(min1[x],a[i].second);
            }
            x = a[i].first / j;
            if (x != 1 && x != j)
            {
                stk.push(x);
                ans = min(ans,a[i].second + min1[x]);
                min1[x] = min(min1[x],a[i].second);
            }
        }
    }
    while (!stk.empty())
    {
        min1[stk.top()] = inf;
        stk.pop();
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(min1,0x3f,sizeof(min1));
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}