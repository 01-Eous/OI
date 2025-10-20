#include<bits/extc++.h>
using namespace std;
using pii = pair<int,int>;
int n;
vector<pii> ans;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 2; i <= n; i++)
        for (int j = i - 1; j >= 1; j -= 2)
            ans.push_back({j,i});
    cout << ans.size() << '\n';
    for (auto [u,v] : ans)
        cout << u << ' ' << v << '\n';
    return 0;
}