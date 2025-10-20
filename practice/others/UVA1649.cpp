#include<bits/extc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;
int m;
vector<pii> ans;
char chk(int n,int k)
{
    int val = 1;
    for (int i = 1; i <= k; i++)
    {
        if (!(m * i / (n - i + 1) / val))
            return 1;
        val = val * (n - i + 1) / i;
    }
    return val == m ? 0 : -1;
}
void solve()
{
    cin >> m;
    ans.clear();
    for (int k = 1; k <= 30; k++)
    {
        int l = k,r = m,mid;
        while (l <= r)
        {
            char tmp = chk(mid = (l + r) >> 1,k);
            if (tmp < 0)
                l = mid + 1;
            else if (tmp > 0)
                r = mid - 1;
            else
            {
                ans.push_back({mid,k});
                ans.push_back({mid,mid - k});
                break;
            }
        }
    }
    sort(ans.begin(),ans.end());
    vector<pii>::iterator ed = unique(ans.begin(),ans.end()),it = ans.begin();
    cout << ans.size() << "\n(" << it->first << "," << it->second << ")";
    for (it++; it != ed; it++)
        cout << " (" << it->first << "," << it->second << ")";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        if (t)
            cout << '\n';
    }
    return 0;
}