#include<bits/extc++.h>
using namespace std;
int n;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int>a(n + 5);
        int cnt[2] = {};
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            cnt[a[i] & 1]++;
        }
        if (cnt[1] == n)
            cout << n - 1 << "\n";
        else
            cout << cnt[1] + 1 << "\n";
    }
    return 0;
}