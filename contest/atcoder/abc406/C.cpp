#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 3e5 + 5;
int n;
int a[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> vec;
    int pos = 0;
    for (int i = 1; i < n; i++)
    {
        if (!pos && a[i] < a[i + 1])
        {
            pos = i;
            vec.push_back(i);
            continue;
        }
        if (pos && a[i - 1] < a[i] && a[i] > a[i + 1])
            vec.push_back(i);
        if (pos && a[i - 1] > a[i] && a[i] < a[i + 1])
            vec.push_back(i);
    }
    vec.push_back(n);
    int ans = 0;
    for (int i = 1; i + 2 < vec.size(); i += 2)
        ans += (vec[i] - vec[i - 1]) * (vec[i + 2] - vec[i + 1]);
    cout << ans;
    return 0;
}