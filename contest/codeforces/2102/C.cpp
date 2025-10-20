#include<bits/extc++.h>
using namespace std;
using pii = pair<int,int>;
int n;
map<pii,int> ans;
void solve()
{
    cin >> n;
    ans.clear();
    ans[{0,0}] = 0;
    int val = 1;
    pii mi = {1,0},mx = {0,1};
    for (int i = 1; i < n; i++)
    {
        int f = i & 1 ? -1 : 1;
        for (int j = 0; j < i; j++)
        {
            pii cur = mi;
            cur.second += f * j;
            ans[cur] = val++;
        }
        for (int j = 0; j < i; j++)
        {
            pii cur = mx;
            cur.first += f * j;
            ans[cur] = val++;
        }
        mi.first += f * (i + 1);
        mi.second += f * (i - 1);
        mx.first += f * (i - 1);
        mx.second += f * (i + 1);
        int tmp = -f * ((i + 1) >> 1);
        ans[{tmp,tmp}] = val++;
    }
    for (int i = n >> 1; i >= -((n - 1) >> 1); i--)
    {
        for (int j = -((n - 1) >> 1); j <= (n >> 1); j++)
            cout << ans[{i,j}] << ' ';
        cout << '\n';
    }
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