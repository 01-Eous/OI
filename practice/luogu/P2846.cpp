#include<bits/extc++.h>
#define ls (rt << 1)
#define rs (rt << 1 | 1)
using namespace std;
const int maxn = 1e5 + 5;
int n,m;
struct Nahida{int l,r,val,tag;}tree[maxn << 2];
void push_up(int rt){tree[rt].val = tree[ls].val + tree[rs].val;}
void push_down(int rt)
{
    if (!tree[rt].tag)
        return;
    tree[ls].val = tree[ls].r - tree[ls].l + 1 - tree[ls].val;
    tree[rs].val = tree[rs].r - tree[rs].l + 1 - tree[rs].val;
    tree[ls].tag ^= 1,tree[rs].tag ^= 1;
    tree[rt].tag = 0;
}
void build(int l,int r,int rt = 1)
{
    tree[rt].l = l,tree[rt].r = r;
    tree[rt].tag = tree[rt].val = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
}
void upd(int ql,int qr,int rt = 1)
{
    int l = tree[rt].l,r = tree[rt].r;
    if (ql <= l && r <= qr)
    {
        tree[rt].val = r - l + 1 - tree[rt].val;
        tree[rt].tag ^= 1;
        return;
    }
    push_down(rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        upd(ql,qr,ls);
    if (qr > mid)
        upd(ql,qr,rs);
    push_up(rt);
}
int que(int ql,int qr,int rt = 1)
{
    int l = tree[rt].l,r = tree[rt].r;
    if (ql <= l && r <= qr)
        return tree[rt].val;
    push_down(rt);
    int mid = (l + r) >> 1,res = 0;
    if (ql <= mid)
        res += que(ql,qr,ls);
    if (qr > mid)
        res += que(ql,qr,rs);
    return res;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    build(1,n,1);
    int op,l,r;
    while (m--)
    {
        cin >> op >> l >> r;
        if (!op)
            upd(l,r);
        else
            cout << que(l,r) << '\n';
    }
    return 0;
}