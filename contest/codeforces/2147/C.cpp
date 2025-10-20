#include<bits/extc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n,m;
char s[maxn];
void solve()
{
    cin >> n >> (s + 1);
    bool fl = s[1] == '1';
    int cnt = s[1] == '0';
    for (int i = 2; i <= n; i++)
    {
        if (s[i] == '0')
            cnt++;
        if (s[i] == s[i - 1])
        {
            if (s[i] == '0')
                fl = 0;
            else
            {
                if (fl && (cnt & 1))
                    return (void)(cout << "NO\n");
                fl = 1,cnt = 0;
            }
        }
    }
    if (s[n] == '1' && fl && (cnt & 1))
        return (void)(cout << "NO\n");
    cout << "YES\n";
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