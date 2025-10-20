#include<bits/extc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n,L,R;
int f[maxn],g[maxn],ans[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i <= 5e5; i++)
        for (int j = i; j <= 5e5; j += i)
            f[j]++;
    for (int i = 1; i * i <= 5e5; i++)
    {
        memcpy(g,f,sizeof f);
        int tmp = i * i;
        for (int j = 5e5 - tmp; j >= i; j--)
            g[j] += g[j - i];
        for (int j = i; j <= 5e5 - tmp; j++)
            g[j] += g[j - i];
        for (int j = 0; j <= 5e5 - tmp; j++)
            ans[tmp + j] += g[j];
    }
    cin >> n;
    while (n--)
    {
        cin >> L >> R;
        int p = max_element(ans + L,ans + R + 1) - ans;
        cout << p << ' ' << ans[p];
        if (n)
            cout << '\n';
    }
    return 0;
}