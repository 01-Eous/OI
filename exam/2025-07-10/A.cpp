#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
using pii = pair<int,int>;
const int maxn = 2e5 + 5;
const int mod = 998244353;
int n;
char s[maxn];
pii min1[maxn];
int pw[maxn],inv[maxn];
int binpow(int x,int y)
{
    int res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}
void init()
{
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
        pw[i] = pw[i - 1] * 10 % mod;
    inv[n] = binpow(pw[n],mod - 2);
    for (int i = n - 1; ~i; i--)
        inv[i] = inv[i + 1] * 10 % mod;
}
signed main()
{
    scanf("%s",s + 1);
    n = strlen(s + 1),init();
    min1[n + 1] = {inf,n + 1};
    for (int i = n; i >= 1; i--)
        min1[i] = min(min1[i + 1],{s[i] - '0',i});
    int ans = 0;
    for (int i = min1[1].second,j = 1; i <= n; i = min1[i + 1].second)
        ans = (ans + ('9' - s[i]) * inv[j++]) % mod;
    printf("%lld",ans);
    return 0;
}
