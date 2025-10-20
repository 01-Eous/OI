#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n,q;
int a[maxn];
struct Nahida
{
    int l,r;
    int sum,max1;
    void push_up(const Nahida &ls,const Nahida &rs)
    {
        this->sum = ls.sum + rs.sum;
        this->max1 = max(ls.max1,rs.max1);
    }
}tree[maxn << 2];
#define ls (rt << 1)
#define rs (rt << 1 | 1)
void build(int l,int r,int rt)
{
    tree[rt].l = l;
    tree[rt].r = r;
    if (l == r)
    {
        tree[rt].max1 = tree[rt].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    tree[rt].push_up(tree[ls],tree[rs]);
}
void upd(int ql,int qr,int rt = 1)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (tree[rt].max1 <= 1)
        return;
    if (l == r)
    {
        tree[rt].sum = floor(sqrt(tree[rt].sum));
        tree[rt].max1 = floor(sqrt(tree[rt].max1));
        return;
    }
    int mid = (l + r) >> 1;
    if (ql <= mid)
        upd(ql,qr,ls);
    if (qr > mid)
        upd(ql,qr,rs);
    tree[rt].push_up(tree[ls],tree[rs]);
}
int que(int ql,int qr,int rt = 1)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
        return tree[rt].sum;
    int mid = (l + r) >> 1,ret = 0;
    if (ql <= mid)
        ret += que(ql,qr,ls);
    if (qr > mid)
        ret += que(ql,qr,rs);
    return ret;
}
#undef ls
#undef rs
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    scanf("%lld",&q);
    build(1,n,1);
    int op,l,r;
    while (q--)
    {
        scanf("%lld%lld%lld",&op,&l,&r);
        if (l > r)
            swap(l,r);
        if (op)
            printf("%lld\n",que(l,r));
        else
            upd(l,r);
    }
    return 0;
}