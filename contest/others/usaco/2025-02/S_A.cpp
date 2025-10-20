#include<bits/extc++.h>
using namespace std;
typedef pair<int,int> pii;
int n;
bool cmp(const pii &x,const pii &y)
{return x.first ^ y.first ? x.first > y.first : x.second < y.second;}
void solve()
{
    cin >> n;
    vector<int>a(n + 5),ans;
    vector<pii>b(n + 5);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = {a[i],i};
    }
    sort(b.begin() + 1,b.begin() + n + 1,cmp);
    int lst = 0,now = 1;
    for (int i = 2; i <= n; i++)
    {
        if (b[now].second > b[i].second)
        {
            if (b[lst].second < b[i].second)
            {
                b[now].second = b[lst].second;
                break;
            }
        }
        else
        {
            lst = now;
            now = i;
        }
    }
    int pos = 0;
    for (int i = 1; i <= n; i++)
    {
        if (b[i].second >= pos)
        {
            ans.push_back(b[i].first);
            pos = b[i].second;
        }
    }
    for (auto i = ans.begin(); i != ans.end(); i++)
        cout << *i << " \n"[i == ans.end() - 1];
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
