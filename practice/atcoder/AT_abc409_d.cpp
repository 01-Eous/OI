#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n;
char s[maxn];
void solve()
{
    scanf("%d",&n);
    memset(s,0,sizeof(char) * (n + 5));
    scanf("%s",s + 1);
    int p1 = 0,p2 = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] > s[i + 1])
        {
            p1 = i;
            break;
        }
    }
    p2 = n;
    for (int i = p1 + 1; i <= n; i++)
    {
        if (s[i] > s[p1])
        {
            p2 = i - 1;
            break;
        }
    }
    char tmp = s[p1];
    for (int i = p1; i < p2; i++)
        s[i] = s[i + 1];
    s[p2] = tmp;
    puts(s + 1);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}