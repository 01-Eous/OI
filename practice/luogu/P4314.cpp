#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define inf 0x3f3f3f3f3f3f3f3f
#define endl "\n"
using namespace std;
const int maxn = 1e5 + 5;
int n;
int a[maxn];
class Nahida
{
    public:
    int l,r;
    int max1,_max1;
    int add,_add;
    int tag,_tag;

    void clear_tag()
    {
        add = _add = 0;
        tag = _tag = -inf;
    }
    void push_up(const Nahida &lson,const Nahida &rson)
    {
        this->max1 = max(lson.max1,rson.max1);
        this->_max1 = max(lson._max1,rson._max1);
    }
    void tag_add(int tag,int _tag)
    {
        this->_max1 = max(this->_max1,this->max1 + _tag);
        this->max1 += tag;
        if (this->tag == -inf)
        {
            this->_add = max(this->_add,this->add + _tag);
            this->add += tag;
        }
        else
        {
            this->_tag = max(this->_tag,this->tag + _tag);
            this->tag += tag;
        }
    }
    void tag_set(int tag,int _tag)
    {
        this->_max1 = max(this->_max1,_tag);
        this->max1 = tag;
        this->_tag = max(this->_tag,_tag);
        this->tag = tag;
    }
}tree[maxn << 2];
inline void push_down(int rt)
{
    if (tree[rt].add || tree[rt]._add)
    {
        tree[ls].tag_add(tree[rt].add,tree[rt]._add);
        tree[rs].tag_add(tree[rt].add,tree[rt]._add);
    }
    if (tree[rt].tag != -inf || tree[rt]._tag != -inf)
    {
        tree[ls].tag_set(tree[rt].tag,tree[rt]._tag);
        tree[rs].tag_set(tree[rt].tag,tree[rt]._tag);
    }
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
void upd_add(int ql,int qr,int x,int rt = 1)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
        return tree[rt].tag_add(x,max(x,0LL));
    push_down(rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        upd_add(ql,qr,x,ls);
    if (qr > mid)
        upd_add(ql,qr,x,rs);
    tree[rt].push_up(tree[ls],tree[rs]);
}
void upd_set(int ql,int qr,int x,int rt = 1)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
        return tree[rt].tag_set(x,x);
    push_down(rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        upd_set(ql,qr,x,ls);
    if (qr > mid)
        upd_set(ql,qr,x,rs);
    tree[rt].push_up(tree[ls],tree[rs]);
}
int que(int ql,int qr,int rt = 1)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
        return tree[rt].max1;
    push_down(rt);
    int mid = (l + r) >> 1,ret = -inf;
    if (ql <= mid)
        ret = max(ret,que(ql,qr,ls));
    if (qr > mid)
        ret = max(ret,que(ql,qr,rs));
    return ret;
}
int history(int ql,int qr,int rt = 1)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
        return tree[rt]._max1;
    push_down(rt);
    int mid = (l + r) >> 1,ret = -inf;
    if (ql <= mid)
        ret = max(ret,history(ql,qr,ls));
    if (qr > mid)
        ret = max(ret,history(ql,qr,rs));
    return ret;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1,n,1);
    string op;
    int q,l,r,x;
    cin >> q;
    while (q--)
    {
        cin >> op >> l >> r;
        if (op == "Q")
            cout << que(l,r) << endl;
        else if (op == "A")
            cout << history(l,r) << endl;
        else if (op == "P")
        {
            cin >> x;
            upd_add(l,r,x);
        }
        else
        {
            cin >> x;
            upd_set(l,r,x);
        }
    }
    return 0;
}