#include<bits/extc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
using namespace std;
const int maxn = 5e5 + 5;
int n,q;
int a[maxn];
struct Nahida
{
    int l,r;
    int min1,_min1,min2;
    int add1,_add1,add2,_add2;
    void clear_tag(){add1 = add2 = _add1 = _add2 = 0;}
    void push_up(Nahida lson,Nahida rson)
    {
        this->_min1 = min(lson._min1,rson._min1);
        if (lson.min1 < rson.min1)
        {
            this->min1 = lson.min1;
            this->min2 = min(lson.min2,rson.min1);
        }
        else if (lson.min1 > rson.min1)
        {
            this->min1 = rson.min1;
            this->min2 = min(lson.min1,rson.min2);
        }
        else
        {
            this->min1 = lson.min1;
            this->min2 = min(lson.min2,rson.min2);
        }
    }
    void tag_down(int tag1,int _tag1,int tag2,int _tag2)
    {
        this->_min1 = min(this->_min1,this->min1 + _tag1);
        this->min1 += tag1;
        this->_add1 = min(this->_add1,this->add1 + _tag1);
        this->add1 += tag1;

        this->_add2 = min(this->_add2,this->add2 + _tag2);
        this->add2 += tag2;
        if (this->min2 != inf)
            this->min2 += tag2;
    }
}tree[maxn << 2];
template<typename type>
inline void read(type &x)
{
    x = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
void push_down(int rt)
{
    if (!tree[rt].add1 && !tree[rt]._add1 && !tree[rt].add2 && !tree[rt]._add2)
        return;
    int minVal = min (tree[ls].min1,tree[rs].min1);
    if (tree[ls].min1 == minVal)
        tree[ls].tag_down(tree[rt].add1,tree[rt]._add1,tree[rt].add2,tree[rt]._add2);
    else
        tree[ls].tag_down(tree[rt].add2,tree[rt]._add2,tree[rt].add2,tree[rt]._add2);
    if (tree[rs].min1 == minVal)
        tree[rs].tag_down(tree[rt].add1,tree[rt]._add1,tree[rt].add2,tree[rt]._add2);
    else
        tree[rs].tag_down(tree[rt].add2,tree[rt]._add2,tree[rt].add2,tree[rt]._add2);
    tree[rt].clear_tag();
}
void build(int l,int r,int rt)
{
    tree[rt].l = l;
    tree[rt].r = r;
    if (l == r)
    {
        tree[rt].min1 = tree[rt]._min1 = a[l];
        tree[rt].min2 = inf;
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    tree[rt].push_up(tree[ls],tree[rs]);
}
void upd_add(int ql,int qr,int x,int rt)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
        return tree[rt].tag_down(x,x,x,x);
    push_down(rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        upd_add(ql,qr,x,ls);
    if (qr > mid)
        upd_add(ql,qr,x,rs);
    tree[rt].push_up(tree[ls],tree[rs]);
}
void upd_max(int ql,int qr,int x,int rt)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (x <= tree[rt].min1)
        return;
    if (ql <= l && r <= qr && x < tree[rt].min2)
        return tree[rt].tag_down(x - tree[rt].min1,max(0LL,x - tree[rt].min1),0,0);
    push_down(rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        upd_max(ql,qr,x,ls);
    if (qr > mid)
        upd_max(ql,qr,x,rs);
    tree[rt].push_up(tree[ls],tree[rs]);
}
int que(int ql,int qr,int op,int rt)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
        return op == 3 ? tree[rt].min1 : tree[rt]._min1;
    push_down(rt);
    int mid = (l + r) >> 1,ret = inf;
    if (ql <= mid)
        ret = min(ret,que(ql,qr,op,ls));
    if (qr > mid)
        ret = min(ret,que(ql,qr,op,rs));
    return ret;
}
signed main()
{
    read(n),read(q);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    build(1,n,1);
    int op,l,r,x;
    while (q--)
    {
        read(op),read(l),read(r);
        if (op == 1)
        {
            read(x);
            upd_add(l,r,x,1);
        }
        else if (op == 2)
        {
            read(x);
            upd_max(l,r,x,1);
        }
        else
            printf("%lld\n",que(l,r,op,1));
    }
    return 0;
}