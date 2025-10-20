#include<bits/extc++.h>
using namespace std;
int n;
void solve()
{
    scanf("%d",&n);
    vector<int>a(n + 5,0);
    for (int i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    for (int i = 2; i <= n; i++)
    {
        int tmp = min(a[i],a[i - 1]);
        a[i] -= tmp,a[i - 1] -= tmp;
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i + 1])
        {
            puts("NO");
            return;
        }
    }
    puts("YES");
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}