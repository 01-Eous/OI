#include<bits/extc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n,a[5005];
bool vis[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int j = 1; j < i; j++)
            vis[abs(a[i] - a[j])] = 1;
    }
    for (int i = n; i <= 1e6; i++)
    {
        bool fl = 1;
        for (int j = i; j <= 1e6; j += i)
        {
            if (vis[j])
            {
                fl = 0;
                break;
            }
        }
        if (fl)
            return cout << i,0;
    }
    return 0;
}