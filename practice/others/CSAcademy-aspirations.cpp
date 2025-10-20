#include<bits/extc++.h>
using namespace std;
int l,r,d;
signed main()
{
    cin >> l >> r >> d;
    vector<int> ans;
    for (int i = r / d * d; i >= l; i -= d)
        ans.push_back(i);
    if (ans.size() <= 1 && ans.front() != d)
        return cout << "impossible",0;
    sort(ans.begin(),ans.end());
    cout << ans.size() << '\n';
    for (auto i : ans)
        cout << i << ' ';
    return 0;
}