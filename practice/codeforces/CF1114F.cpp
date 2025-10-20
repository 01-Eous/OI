#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
using namespace std;
const int maxn = 4e5 + 5;
const int mod = 1e9 + 7;
int n,q,cnt;
int a[maxn];
bool ipr[305];
int pr[305],f[305];
struct Nahida
{
    int mul,fac;
    int tagm,tagf;
}tree[maxn << 2];
int binpow(int x,int y)
{
    int res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}
void init(int n = 300)
{
    for (int i = 2; i <= n; i++)
    {
        if (!ipr[i])
            pr[++cnt] = i;
        for (int j = 1; j <= cnt && i * pr[j] <= n; j++)
        {
            ipr[i * pr[j]] = 1;
            if (i % pr[j] == 0)
                break;
        }
    }
    for (int i = 1; i <= cnt; i++)
        f[i] = (pr[i] - 1) * binpow(pr[i],mod - 2) % mod;
}
void push_up(int rt)
{
    tree[rt].fac = tree[ls].fac | tree[rs].fac;
    tree[rt].mul = tree[ls].mul * tree[rs].mul % mod;
}
void tag_down(int fac,int mul,int l,int r,int rt)
{
    tree[rt].fac |= fac;
    tree[rt].mul = tree[rt].mul * binpow(mul,r - l + 1) % mod;
    tree[rt].tagf |= fac;
    tree[rt].tagm = tree[rt].tagm * mul % mod;
}
void push_down(int l,int r,int rt)
{
    if (!tree[rt].tagf)
        return;
    int mid = (l + r) >> 1;
    tag_down(tree[rt].tagf,tree[rt].tagm,l,mid,ls);
    tag_down(tree[rt].tagf,tree[rt].tagm,mid + 1,r,rs);
    tree[rt].tagf = 0,tree[rt].tagm = 1;
}
void build(int l,int r,int rt)
{
    tree[rt].tagf = 0,tree[rt].tagm = 1;
    if (l == r)
    {
        for (int i = 1; i <= cnt; i++)
            if (a[l] % pr[i] == 0)
                tree[rt].fac |= 1LL << (i - 1);
        tree[rt].mul = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    push_up(rt);
}
void upd(int ql,int qr,int fac,int mul,int l = 1,int r = n,int rt = 1)
{
    if (ql <= l && r <= qr)
        return tag_down(fac,mul,l,r,rt);
    push_down(l,r,rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        upd(ql,qr,fac,mul,l,mid,ls);
    if (qr > mid)
        upd(ql,qr,fac,mul,mid + 1,r,rs);
    push_up(rt);
}
Nahida que(int ql,int qr,int l = 1,int r = n,int rt = 1)
{
    if (ql <= l && r <= qr)
        return tree[rt];
    push_down(l,r,rt);
    int mid = (l + r) >> 1;
    Nahida res;
    res.fac = 0,res.mul = 1;
    if (ql <= mid)
    {
        Nahida tmp = que(ql,qr,l,mid,ls);
        res.fac |= tmp.fac;
        res.mul = res.mul * tmp.mul % mod;
    }
    if (qr > mid)
    {
        Nahida tmp = que(ql,qr,mid + 1,r,rs);
        res.fac |= tmp.fac;
        res.mul = res.mul * tmp.mul % mod;
    }
    return res;
}
signed main()
{
    init();
    scanf("%lld%lld",&n,&q);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    build(1,n,1);
    char op[15];
    int l,r,mul;
    while (q--)
    {
        scanf("%s%lld%lld",op,&l,&r);
        if (op[0] != 'T')
        {
            scanf("%lld",&mul);
            int fac = 0;
            for (int i = 1; i <= cnt; i++)
                if (mul % pr[i] == 0)
                    fac |= 1LL << (i - 1);
            upd(l,r,fac,mul);
        }
        else
        {
            Nahida tmp = que(l,r);
            int ans = tmp.mul,fac = tmp.fac;
            for (int i = 1; i <= cnt; i++)
                if (fac & (1LL << (i - 1)))
                    ans = ans * f[i] % mod;
            printf("%lld\n",ans);
        }
    }
    return 0;
}