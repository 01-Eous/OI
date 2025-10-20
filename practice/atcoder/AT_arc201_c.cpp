#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 5;
const int mod = 998244353;
int n,len,rt,cnt;
char s[maxn];
int dp[maxn],pw[maxn],c[maxn];
struct Klee
{
    int l,r;
    bool ed;
}ac[maxn];
void init(int n = 5e5)
{
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
        pw[i] = (pw[i - 1] << 1) % mod;
}
void dfs(int &u,int pos)
{
    if (!u)
        u = ++cnt;
    auto &[l,r,ed] = ac[u];
    if (pos > len)
    {
        ed = 1;
        goto Nahida;
    }
    if (s[pos] == 'A')
        dfs(l,pos + 1);
    else
        dfs(r,pos + 1);
    Nahida:
    c[u] = c[l] + c[r] + ed;
    dp[u] = dp[l] * dp[r] % mod;
    if (ed)
        dp[u] = (dp[u] + pw[c[u] - 1]) % mod;
}
signed main()
{
    init();
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s",s + 1);
        len = strlen(s + 1);
        dfs(rt,1);
        printf("%lld\n",dp[rt]);
    }
    return 0;
}
