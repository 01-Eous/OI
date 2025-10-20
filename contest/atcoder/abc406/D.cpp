#include<bits/extc++.h>
using namespace std;
using pii = pair<int,int>;
const int maxn = 2e5 + 5;
int h,w,n,q;
set<pii> col[maxn],row[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> h >> w >> n;
    pii tmp;
    while (n--)
    {
        auto &[x,y] = tmp;
        cin >> x >> y;
        col[x].insert(tmp);
        row[y].insert(tmp);                
    }
    cin >> q;
    int op,x;
    while (q--)
    {
        cin >> op >> x;
        if (op == 1)
        {
            cout << col[x].size() << '\n';
            for (auto [i,j] : col[x])
                row[j].erase({i,j});
            col[x].clear();
        }
        else
        {
            cout << row[x].size() << '\n';
            for (auto [i,j] : row[x])
                col[i].erase({i,j});
            row[x].clear();
        }
    }
    return 0;
}