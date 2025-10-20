#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
int n;
char s[maxn];
int ans[maxn];
void solve()
{
    scanf("%lld%s",&n,s + 1);
    int val = n,cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int p = i;
        while (s[p] == '1')
            p++;
        for (int j = p; j >= i; j--)
            ans[j] = val--;
        cnt += (p - i + 1) * (n - p);
        i = p;
    }
    printf("%lld\n",cnt);
    for (int i = 1; i <= n; i++)
        printf("%lld ",ans[i]);
    putchar('\n');
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}