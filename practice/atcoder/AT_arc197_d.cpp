#include<bits/extc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;
int n;
ll fac[405],ans;
int fa[405],siz[405];
bitset<405> a[405];
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
void merge(int x,int y)
{
    x = find(x),y = find(y);
    fa[x] = y;
}
void solve()
{
    scanf("%d",&n);
    iota(fa + 1,fa + n + 1,1);    
    fill(siz + 1,siz + n + 1,0);
    for (int i = 1; i <= n; i++)
    {
        a[i].reset();
        for (int j = 1,x; j <= n; j++)
        {
            scanf("%d",&x);
            a[i][j] = x;
        }
    }
    ans = 0;
    if (a[1].count() != n)
        goto Nahida;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!a[i][j])
                continue;
            if (a[i] == a[j])
                merge(i,j);
            else if ((a[i] & a[j]) != a[i] && (a[i] & a[j]) != a[j])
                goto Nahida;
        }
    }
    ans = 1;
    for (int i = 2; i <= n; i++)
        ans = ans * ++siz[find(i)] % mod;
    Nahida:
    printf("%lld\n",ans);
}
signed main()
{
    fac[0] = 1;
    for (int i = 1; i <= 400; i++)
        fac[i] = fac[i - 1] * i % mod;
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}