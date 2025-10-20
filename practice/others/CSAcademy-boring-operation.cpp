#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n;
int a[maxn];
signed main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",a + i);
        if (a[i] > 5e8)
            a[i] = 1e9 - a[i];
    }
    sort(a + 1,a + n + 1);
    printf("%d",a[n] - a[1]);
    return 0;
}