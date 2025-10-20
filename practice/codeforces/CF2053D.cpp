#include<bits/extc++.h>
#define int long long
#define inv(x) binpow(x,mod - 2)
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 998244353;
int n,q;
int a1[maxn],b1[maxn],a2[maxn],b2[maxn];
inline void read(int &x)
{
    x = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
int binpow(int x,int y)
{
    int ret = 1;
    while (y)
    {
        if (y & 1)
            ret = ret * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ret;
}
void solve()
{
    read(n),read(q);
    for (int i = 1; i <= n; i++)
    {
        read(a1[i]);
        a2[i] = a1[i];
    }
    for (int i = 1; i <= n; i++)
    {
        read(b1[i]);
        b2[i] = b1[i];
    }
    sort(a2 + 1,a2 + n + 1);
    sort(b2 + 1,b2 + n + 1);
    int ans = 1;
    for (int i = 1; i <= n; i++)
        ans = ans * min(a2[i],b2[i]) % mod;
    printf("%lld ",ans);
    int op,x;
    while (q--)
    {
        read(op),read(x);
        int pos;
        if (op == 1)
        {
            pos = upper_bound(a2 + 1,a2 + n + 1,a1[x]) - a2 - 1;
            ans = ans * inv(min(a2[pos],b2[pos])) % mod;
            a1[x]++,a2[pos]++;
        }
        else
        {
            pos = upper_bound(b2 + 1,b2 + n + 1,b1[x]) - b2 - 1;
            ans = ans * inv(min(a2[pos],b2[pos])) % mod;
            b1[x]++,b2[pos]++;
        }
        ans = ans * min(a2[pos],b2[pos]) % mod;
        printf("%lld ",ans);
    }
    putchar('\n');
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
/*
1
1 2
1
1
2 1
2 1
*/