#include<bits/extc++.h>
using namespace std;
int n,m;
multiset<int> a;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1,x; i <= n; i++)
        cin >> x,a.insert(x);
    for (int i = 1,x; i <= m; i++)
    {
        cin >> x;
        auto it = a.find(x);
        if (it != a.end())
            a.erase(it);
    }
    for (auto i : a)
        cout << i << ' ';
    return 0;
}