#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n,m,p;
int top[maxn];
char a[maxn],b[maxn];
void solve()
{
    scanf("%d%d",&n,&m);
    scanf("%s%s",a,b);
    p = -114514;
    for (int i = 0; i < m; i++)
    {
        if (b[i] == '0')
            p = i;
        top[i] = p;
    }
    p = 0;
    for (int i = 0; i < n && p >= 0; i++)
    {
        if (p < m && a[i] == b[p])
            p++;
        else if (p < m && a[i] == '0' && b[p] == '1')
            p = top[p] + 1;
        else if (p == m && a[i] == '0' && b[p - 1] == '1')
            p = top[p - 1] + 1;
    }
    puts(p == m ? "yes" : "no");
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}