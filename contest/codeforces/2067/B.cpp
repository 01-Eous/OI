#include<bits/extc++.h>
using namespace std;
int n;
void solve()
{
    scanf("%d",&n);
    vector<int>a(n + 5),b(n + 5);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        b[a[i]]++;
    }
    for (int i = n; i >= 1; i--)
    {
        if (!(b[i] & 1))
            continue;
        int need = 1,j = i - 1;
        for (; j >= 1; j--)
        {
            if (b[j] >= need + 2)
                break;
            need = need + 2 - b[j];
        }
        if (j < 1)
        {
            puts("NO");
            return;
        }
        for (; j < i; j++)
        {
            int tmp = b[j + 1];
            b[j] -= need;
            b[j + 1] += need;
            need = need - 2 + tmp;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (b[i] & 1)
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