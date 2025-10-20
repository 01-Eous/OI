#include<bits/extc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n,i,l,r;
int a[maxn];
void solve()
{
    scanf("%d",&n);
    int cnt = n,ans = 0;
    for (i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        a[i] = ch - '0';
        cnt += a[i] != a[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == a[i - 1])
            continue;
        int l = i - 1,r = i;
        while (~l && a[i - 1] == a[l])
            l--;
        while (r <= n && a[r] == a[i])
            r++;
        ans = max(ans,(l != -1) + (r != n + 1));
    }
    printf("%d\n",cnt - ans);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}