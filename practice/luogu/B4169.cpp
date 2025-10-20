#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
using namespace std;
const int maxn = 1e5 + 5;
int n,m;
int a[maxn];
struct Nahida{int l,r,sum,_max;}tree[maxn << 2];
void push_up(int rt)
{
    tree[rt].sum = tree[ls].sum + tree[rs].sum;
    tree[rt]._max = max(tree[ls]._max,tree[rs]._max);
}
void build(int l,int r,int rt = 1)
{
    tree[rt].l = l,tree[rt].r = r;
    if (l == r)
    {
        tree[rt].sum = tree[rt]._max = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    push_up(rt);
}
void upd(int pos,int x,int rt = 1)
{
    int l = tree[rt].l,r = tree[rt].r;
    if (l == r)
    {
        tree[rt].sum = tree[rt]._max = x;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        upd(pos,x,ls);
    else
        upd(pos,x,rs);
    push_up(rt);
}
int que_sum(int ql,int qr,int rt = 1)
{
    int l = tree[rt].l,r = tree[rt].r;
    if (ql <= l && r <= qr)
        return tree[rt].sum;
    int mid = (l + r) >> 1,res = 0;
    if (ql <= mid)
        res += que_sum(ql,qr,ls);
    if (qr > mid)
        res += que_sum(ql,qr,rs);
    return res;
}
int que_max(int ql,int qr,int rt = 1)
{
    int l = tree[rt].l,r = tree[rt].r;
    if (ql <= l && r <= qr)
        return tree[rt]._max;
    int mid = (l + r) >> 1,res = 0;
    if (ql <= mid)
        res = max(res,que_max(ql,qr,ls));
    if (qr > mid)
        res = max(res,que_max(ql,qr,rs));
    return res;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1,n,1);
    int op,l,r;
    while (m--)
    {
        cin >> op >> l >> r;
        if (op == 1)
            cout << que_sum(l,r) * que_max(l,r) << '\n';
        else
            upd(l,r);
    }
    return 0;
}