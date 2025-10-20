#include<bits/extc++.h>
using namespace std;
int n,x,sum;
vector<int> a;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> x >> n;
    a.resize(n);
    for (auto &i : a)
        cin >> i;
    sort(a.begin(),a.end());
    int ans = 0;
    while (sum < x)
    {
        vector<int>::iterator it = upper_bound(a.begin(),a.end(),sum + 1) - 1;
        if (it < a.begin())
            return cout<< "-1",0;
        sum += *it,ans++;
    }
    cout << ans;
    return 0;
}