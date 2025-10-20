#include<bits/extc++.h>
using namespace std;
int m;
vector<int> ans;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m;
    while (m)
    {
        ans.push_back((m + 1) >> 1);
        m >>= 1;
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << '\n';
    for (auto i : ans)
        cout << i << ' ';
    return 0;
}