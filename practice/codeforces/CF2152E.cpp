#include<bits/extc++.h>
using namespace std;
const int maxn = 1e4 + 6;
int n,m,len;
int dfn[maxn];
vector<int> ask,res;
void solve()
{
    cin >> n;
    m = n * n + 1;
    memset(dfn,0,sizeof(int) * (m + 5));
    for (int i = 1; i <= n; i++)
    {
        ask.clear();
        for (int j = 1; j <= m; j++)
            if (!dfn[j])
                ask.push_back(j);
        cout << "? " << ask.size();
        for (auto j : ask)
            cout << ' ' << j;
        cout << endl;
        cin >> len;
        res.resize(len);
        for (int j = 0; j < len; j++)
        {
            cin >> res[j];
            dfn[res[j]] = i;
        }
        if (len > n)
        {
            cout << '!';
            for (int i = 0; i <= n; i++)
                cout << ' ' << res[i];
            cout << endl;
            return;
        }
    }
    for (int i = 1; i <= m; i++)
        if (!dfn[i])
            dfn[i] = n + 1;
    res.clear();
    int p = n + 1;
    for (int i = m; i >= 1; i--)
        if (dfn[i] == p)
            res.push_back(i),p--;
    reverse(res.begin(),res.end());
    cout << '!';
    for (auto i : res)
        cout << ' ' << i;
    cout << endl;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}