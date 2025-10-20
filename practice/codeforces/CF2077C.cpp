#include<bits/extc++.h>
#define int long long
#define sq(x) ((x) * (x))
using namespace std;
const int mod = 998244353,inv8 = 873463809;
const int maxn = 2e5 + 5;
int n,q;
char s[maxn];
void solve()
{
    scanf("%lld%lld%s",&n,&q,s + 1);
    int tmp1 = 499122177,tmp2 = 0;
    for (int i = 1; i <= n; i++)
    {
        tmp1 = (tmp1 << 1) % mod;
        tmp2 += s[i] - '0';
    }
    tmp2 = (tmp2 << 1) - n;
    int x;
    while (q--)
    {
        scanf("%lld",&x);
        if (s[x] == '0')
        {
            s[x] = '1';
            tmp2 += 2;
        }
        else
        {
            s[x] = '0';
            tmp2 -= 2;
        }
        printf("%lld\n",tmp1 * (sq(tmp2) % mod + n - 2) % mod * inv8 % mod);
    }
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}