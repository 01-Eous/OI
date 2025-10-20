#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
int n,a[maxn],cnt;
bool apr[maxn];
vector<int>b[maxn],pos;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        if (b[i].size() >= 2)
            pos.push_back(b[i][b[i].size() - 2]);
    sort(pos.begin(),pos.end());
    int ans = 0;
    auto now = pos.begin();
    for (int i = 1; i <= n; i++)
    {
        if (!apr[a[i]])
        {
            cnt++;
            apr[a[i]] = 1;
        }
        if (i == *now)
        {
            ans += cnt - 1;
            now++;
        }
    }
    cout << ans;
    return 0;
}