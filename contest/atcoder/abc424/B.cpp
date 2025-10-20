#include<bits/extc++.h>
using namespace std;
int n,m,q;
int b[15];
vector<int> ans;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    int x,y;
    while (q--)
    {
        cin >> x >> y;
        if (++b[x] == m)
            ans.push_back(x);
    }
    for (auto i : ans)
        cout << i << ' ';
    return 0;
}