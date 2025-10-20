#include<bits/extc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxn = 2e5 + 5;
int n;
string s[maxn],t,ans;
vector<pii>v[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    cin >> t;
    for (int i = 1; i <= n; i++)
    {
        int p = 0;
        for (int j = 0; j < s[i].length(); j++)
            if (p < t.length() && s[i][j] == t[p])
                v[p++].push_back({i,j});
        v[p].push_back({i,s[i].length()});
    }
    vector<int>lst(n + 5,-1);
    for (int p = 0; p < t.length(); p++)
    {
        bool fl = 0;
        for (auto &[i,j] : v[p])
        {
            for (int k = lst[i] + 1; k < j; k++)
                ans.push_back(s[i][k]);
            lst[i] = j;
            if (j != s[i].length())
                fl = 1;
        }
        if (fl)
            ans.push_back(t[p]);
    }
    int p = 0;
    for (int i = 0; i < ans.length(); i++)
        if (p < t.length() && ans[i] == t[p])
            p++;
    if (p == t.length())
        cout << "NO";
    else
        cout << "YES\n" << ans;
    return 0;
}