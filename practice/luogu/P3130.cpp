#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 2e5 + 5;
int n,q,a[maxn];
struct Nahida{int l,r,sum,min1,tag;}tree[maxn * 3];
void push_up(int rt)
{
    tree[rt].sum = tree[ls].sum + tree[rs].sum;
    tree[rt].min1 = min(tree[ls].min1,tree[rs].min1);
}
void push_down(int rt)
{
    tree[ls].sum += (tree[ls].r - tree[ls].l + 1) * tree[rt].tag;
    tree[rs].sum += (tree[rs].r - tree[rs].l + 1) * tree[rt].tag;
    tree[ls].min1 += tree[rt].tag;
    tree[rs].min1 += tree[rt].tag;
    tree[ls].tag += tree[rt].tag;
    tree[rs].tag += tree[rt].tag;
    tree[rt].tag = 0;
}
void build(int l,int r,int rt)
{
    tree[rt].l = l,tree[rt].r = r;
    tree[rt].tag = 0;
    if (l == r)
    {
        tree[rt].sum = tree[rt].min1 = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    push_up(rt);
}
void upd(int ql,int qr,int x,int rt = 1)
{
    int l = tree[rt].l,r = tree[rt].r;
    if (ql <= l && r <= qr)
    {
        tree[rt].sum += (r - l + 1) * x;
        tree[rt].min1 += x;
        tree[rt].tag += x;
        return;
    }
    push_down(rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        upd(ql,qr,x,ls);
    if (qr > mid)
        upd(ql,qr,x,rs);
    push_up(rt);
}
int que_sum(int ql,int qr,int rt = 1)
{
    int l = tree[rt].l,r = tree[rt].r;
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
int que_min(int ql,int qr,int rt = 1)
{
    int l = tree[rt].l,r = tree[rt].r;
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
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1,n,1);
    char op;
    int a,b,c;
    while (q--)
    {
        cin >> op >> a >> b;
        if (op == 'M')
            cout << que_min(a,b) << '\n';
        else if (op == 'S')
            cout << que_sum(a,b) << '\n';
        else
        {
            cin >> c;
            upd(a,b,c);
        }
    }
    return 0;
}