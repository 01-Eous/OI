#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 3e5 + 5;
int n;
int a[maxn];
vector<int> apr[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i <= n; i++)
        apr[i].push_back(0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        apr[a[i]].push_back(i);
    }
    for (int i = 0; i <= n; i++)
        apr[i].push_back(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = a[i] - 1;
        int l = *(lower_bound(apr[x].begin(),apr[x].end(),i) - 1);
        int r = min(
            *upper_bound(apr[a[i]].begin(),apr[a[i]].end(),i),
            *upper_bound(apr[x].begin(),apr[x].end(),i)
        );
        ans += (i - l) * (r - i);
    }
    cout << ans;
    return 0;
}