#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 2e5 + 5;
int n,q;
int a[maxn];
struct Nahida
{
    int l,r;
    int max1,min1,sum,tag;
    void push_up(const Nahida &lson,const Nahida &rson)
    {
        this->max1 = max(lson.max1,rson.max1);
        this->min1 = min(lson.min1,rson.min1);
        this->sum = lson.sum + rson.sum;
    }
    void tag_down(int tag)
    {
        this->max1 += tag;
        this->min1 += tag;
        this->sum += (tag * (this->r - this->l + 1));
        this->tag += tag;
    }
}tree[maxn << 2];
inline void push_up(int rt){tree[rt].push_up(tree[ls],tree[rs]);}
inline void push_down(int rt)
{
    if (!tree[rt].tag)
        return;
    tree[ls].tag_down(tree[rt].tag);
    tree[rs].tag_down(tree[rt].tag);
    tree[rt].tag = 0;
}
void build(int l,int r,int rt)
{
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].tag = 0;
    if (l == r)
    {
        tree[rt].max1 = tree[rt].min1 = tree[rt].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    push_up(rt);
}
void upd_add(int ql,int qr,int x,int rt = 1)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
        return tree[rt].tag_down(x);
    push_down(rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        upd_add(ql,qr,x,ls);
    if (qr > mid)
        upd_add(ql,qr,x,rs);
    push_up(rt);
}
void upd_div(int ql,int qr,int x,int rt = 1)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
    {
        int a = tree[rt].max1 - floor(1.0 * tree[rt].max1 / x);
        int b = tree[rt].min1 - floor(1.0 * tree[rt].min1 / x);
        if (a == b)
            return tree[rt].tag_down(-a);
    }
    push_down(rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        upd_div(ql,qr,x,ls);
    if (qr > mid)
        upd_div(ql,qr,x,rs);
    push_up(rt);
}
int que_min(int ql,int qr,int rt = 1)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
        return tree[rt].min1;
    push_down(rt);
    int mid = (l + r) >> 1,ret = inf;
    if (ql <= mid)
        ret = min(ret,que_min(ql,qr,ls));
    if (qr > mid)
        ret = min(ret,que_min(ql,qr,rs));
    return ret;
}
int que_sum(int ql,int qr,int rt = 1)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
        return tree[rt].sum;
    push_down(rt);
    int mid = (l + r) >> 1,ret = 0;
    if (ql <= mid)
        ret += que_sum(ql,qr,ls);
    if (qr > mid)
        ret += que_sum(ql,qr,rs);
    return ret;
}
signed main()
{
    scanf("%lld%lld",&n,&q);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    build(1,n,1);
    int op,l,r,x;
    while (q--)
    {
        scanf("%lld%lld%lld",&op,&l,&r);
        l++,r++;
        if (op == 1)
        {
            scanf("%lld",&x);
            upd_add(l,r,x);
        }
        else if (op == 2)
        {
            scanf("%lld",&x);
            upd_div(l,r,x);
        }
        else if (op == 3)
            printf("%lld\n",que_min(l,r));
        else
            printf("%lld\n",que_sum(l,r));
    }
    return 0;
}