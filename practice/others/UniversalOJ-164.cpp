#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef pair<int,int> pii;
const int maxn = 5e5 + 5;
int n,q;
int a[maxn];
inline pii operator+(const pii &x,const pii &y)
{return {max(-inf,x.first + y.first),max(x.second + y.first,y.second)};}
inline pii operator*(const pii &x,const pii &y)
{return {max(x.first,y.first),max(x.second,y.second)};}
struct Nahida
{
    int l,r;
    int max1,_max1;
    pii tag,_tag;
    void clear_tag(){tag = _tag = {0,-inf};}
    void push_up(const Nahida &lson,const Nahida &rson)
    {
        this->max1 = max(lson.max1,rson.max1);
        this->_max1 = max(lson._max1,rson._max1);
    }
    void tag_down(pii tag,pii _tag)
    {
        this->_tag = this->_tag * (this->tag + _tag);
        this->tag = this->tag + tag;
        this->_max1 = max(this->_max1,max(this->max1 + _tag.first,_tag.second));
        this->max1 = max(this->max1 + tag.first,tag.second);
    }
}tree[maxn << 1];
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
void push_down(int rt)
{
    tree[ls].tag_down(tree[rt].tag,tree[rt]._tag);
    tree[rs].tag_down(tree[rt].tag,tree[rt]._tag);
    tree[rt].clear_tag();
}
void build(int l,int r,int rt)
{
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].clear_tag();
    if (l == r)
    {
        tree[rt].max1 = tree[rt]._max1 = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    tree[rt].push_up(tree[ls],tree[rs]);
}
void upd(int ql,int qr,pii x,int rt = 1)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
        return tree[rt].tag_down(x,x);
    push_down(rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        upd(ql,qr,x,ls);
    if (qr > mid)
        upd(ql,qr,x,rs);
    tree[rt].push_up(tree[ls],tree[rs]);
}
int que(int pos,int op,int rt = 1)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (l == r)
        return op == 4 ? tree[rt].max1 : tree[rt]._max1;
    push_down(rt);
    int mid = (l + r) >> 1;
    if (pos <= mid)
        return que(pos,op,ls);
    else
        return que(pos,op,rs);
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
        read(op);
        if (op == 1)
        {
            read(l),read(r),read(x);
            upd(l,r,{x,-inf});
        }
        else if (op == 2)
        {
            read(l),read(r),read(x);
            upd(l,r,{-x,0});
        }
        else if (op == 3)
        {
            read(l),read(r),read(x);
            upd(l,r,{-inf,x});
        }
        else
        {
            read(x);
            printf("%lld\n",que(x,op));
        }
    }
    return 0;
}