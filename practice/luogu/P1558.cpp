#include<bits/extc++.h>
#define ls (rt << 1)
#define rs (rt << 1 | 1)
using namespace std;
const int maxn = 1e5 + 5;
int n,m,q;
struct Nahida
{
    int val,tag;
    void tag_down(int x)
    {
        val = 1 << (x - 1);
        tag = x;
    }
}tree[maxn << 2];
void push_up(int rt){tree[rt].val = tree[ls].val | tree[rs].val;}
void push_down(int rt)
{
    int tag = tree[rt].tag;
    if (!tag)
        return;
    tree[ls].tag_down(tag);
    tree[rs].tag_down(tag);
    tree[rt].tag = 0;
}
void build(int l,int r,int rt)
{
    tree[rt].tag = 0;
    if (l == r)
    {
        tree[rt].val = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    push_up(rt);
}
void upd(int ql,int qr,int x,int l = 1,int r = n,int rt = 1)
{
    if (ql <= l && r <= qr)
        return tree[rt].tag_down(x);
    int mid = (l + r) >> 1;
    push_down(rt);
    if (ql <= mid)
        upd(ql,qr,x,l,mid,ls);
    if (qr > mid)
        upd(ql,qr,x,mid + 1,r,rs);
    push_up(rt);
}
int que(int ql,int qr,int l = 1,int r = n,int rt = 1)
{
    if (ql <= l && r <= qr)
        return tree[rt].val;
    int mid = (l + r) >> 1,res = 0;
    push_down(rt);
    if (ql <= mid)
        res |= que(ql,qr,l,mid,ls);
    if (qr > mid)
        res |= que(ql,qr,mid + 1,r,rs);
    return res;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    build(1,n,1);
    char op;
    int l,r,x;
    while (q--)
    {
        cin >> op >> l >> r;
        if (l > r)
            swap(l,r);
        if (op == 'C')
        {
            cin >> x;
            upd(l,r,x);
        }
        else
            cout << __builtin_popcount(que(l,r)) << '\n';
    }
    return 0;
}