#include<bits/extc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int n,k;
bool ipr[maxn];
int pr[maxn],idx;
void init()
{
    for (int i = 2; i <= n; i++)
    {
        if (!ipr[i])
            pr[++idx] = i;
        for (int j = 1; j <= idx && i * pr[j] <= n; j++)
            if (ipr[i * pr[j]] = 1; i % pr[j] == 0)
                break;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    init();
    bool fl = 0;
    for (int i = 1; i <= idx; i++)
    {
        int j = lower_bound(pr + i + 1,pr + idx + 1,pr[i] + k) - pr;
        if (pr[j] == pr[i] + k)
            fl = 1,cout << pr[i] << ' ' << pr[j] << '\n';
    }
    if (!fl)
        cout << "empty";
    return 0;
}