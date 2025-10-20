#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n;
int a[maxn];
map<int,int> l,r;
signed main()
{
    scanf("%d",&n);
    int ans = 0;
    for (int i = 1,x; i <= n; i++)
    {
        scanf("%d",&x);
        a[i] = a[i - 1] + (x ? 1 : -1);
        if (a[i] == 0)
            ans = i;
        if (!l[a[i]])
            l[a[i]] = i;
        r[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        if (l[a[i]] && r[a[i]])
            ans = max(ans,r[a[i]] - l[a[i]]);
    cout << ans;
    return 0;
}