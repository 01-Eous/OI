#include<bits/extc++.h>
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5;
int n,q;
int a[maxn];
struct Nahida
{
    int l,r;
    int max1,max2,_max1,cnt;
    int add1,_add1,add2,_add2;
    ll sum;
    void clear_tag(){add1 = _add1 = add2 = _add2 = 0;}
    void push_up(const Nahida &lson,const Nahida &rson)
    {
        this->_max1 = max(lson._max1,rson._max1);
        this->sum = lson.sum + rson.sum;
        if (lson.max1 > rson.max1)
        {
            this->max1 = lson.max1;
            this->max2 = max(lson.max2,rson.max1);
            this->cnt = lson.cnt;
        }
        else if (lson.max1 < rson.max1)
        {
            this->max1 = rson.max1;
            this->max2 = max(lson.max1,rson.max2);
            this->cnt = rson.cnt;
        }
        else
        {
            this->max1 = lson.max1;
            this->max2 = max(lson.max2,rson.max2);
            this->cnt = lson.cnt + rson.cnt;
        }
    }
    void tag_down(int tag1,int _tag1,int tag2,int _tag2)
    {
        this->sum += 1LL * tag1 * this->cnt + 1LL * tag2 * (this->r - this->l + 1 - this->cnt);

        this->_max1 = max(this->_max1,this->max1 + _tag1);
        this->max1 += tag1;
        this->_add1 = max(this->_add1,this->add1 + _tag1);
        this->add1 += tag1;

        if (this->max2 != -inf)
            this->max2 += tag2;
        this->_add2 = max(this->_add2,this->add2 + _tag2);
        this->add2 += tag2;
    }
}tree[maxn << 2];
template<typename tp>
inline void read(tp &x)
{
    x = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
inline void push_up(int rt){tree[rt].push_up(tree[ls],tree[rs]);}
inline void push_down(int rt)
{
    int max1 = max(tree[ls].max1,tree[rs].max1);
    if (tree[ls].max1 == max1)
        tree[ls].tag_down(tree[rt].add1,tree[rt]._add1,tree[rt].add2,tree[rt]._add2);
    else
        tree[ls].tag_down(tree[rt].add2,tree[rt]._add2,tree[rt].add2,tree[rt]._add2);
    if (tree[rs].max1 == max1)
        tree[rs].tag_down(tree[rt].add1,tree[rt]._add1,tree[rt].add2,tree[rt]._add2);
    else
        tree[rs].tag_down(tree[rt].add2,tree[rt]._add2,tree[rt].add2,tree[rt]._add2);
    tree[rt].clear_tag();
}
void build(int l,int r,int rt)
{
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].clear_tag();
    if (l == r)
    {
        tree[rt].max1 = tree[rt]._max1 = tree[rt].sum = a[l];
        tree[rt].max2 = -inf;
        tree[rt].cnt = 1;
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
        return tree[rt].tag_down(x,x,x,x);
    push_down(rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        upd_add(ql,qr,x,ls);
    if (qr > mid)
        upd_add(ql,qr,x,rs);
    push_up(rt);
}
void upd_min(int ql,int qr,int x,int rt = 1)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (x >= tree[rt].max1)
        return;
    if (ql <= l && r <= qr && x > tree[rt].max2)
        return tree[rt].tag_down(x - tree[rt].max1,x - tree[rt].max1,0,0);
    push_down(rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        upd_min(ql,qr,x,ls);
    if (qr > mid)
        upd_min(ql,qr,x,rs);
    push_up(rt);
}
ll que_sum(int ql,int qr,int rt = 1)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
        return tree[rt].sum;
    push_down(rt);
    int mid = (l + r) >> 1;
    ll ret = 0;
    if (ql <= mid)
        ret += que_sum(ql,qr,ls);
    if (qr > mid)
        ret += que_sum(ql,qr,rs);
    return ret;
}
int que_max(int ql,int qr,int op,int rt = 1)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
        return op == 4 ? tree[rt].max1 : tree[rt]._max1;
    push_down(rt);
    int mid = (l + r) >> 1,ret = -inf;
    if (ql <= mid)
        ret = max(ret,que_max(ql,qr,op,ls));
    if (qr > mid)
        ret = max(ret,que_max(ql,qr,op,rs));
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
            upd_add(l,r,x);
        }
        else if (op == 2)
        {
            read(x);
            upd_min(l,r,x);
        }
        else if (op == 3)
            printf("%lld\n",que_sum(l,r));
        else
            printf("%d\n",que_max(l,r,op));
    }
    return 0;
}