#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 4e5 + 5;
struct Nahida{int val,l,r,tag;}tree[maxn << 2];
int n;
int a[maxn],b[maxn];

#define ls (rt << 1)
#define rs (rt << 1 | 1)
void push_up(int rt){tree[rt].val = min(tree[ls].val,tree[rs].val);}
void push_down(int rt)
{
    tree[ls].val += tree[rt].tag;
    tree[rs].val += tree[rt].tag;
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
        tree[rt].val = l;
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
        tree[rt].val += x;
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
int que(int ql,int qr,int rt = 1)
{
    int l = tree[rt].l,r = tree[rt].r;
    if (ql <= l && r <= qr)
        return tree[rt].val;
    push_down(rt);
    int mid = (l + r) >> 1,ret = inf;
    if (ql <= mid)
        ret = min(ret,que(ql,qr,ls));
    if (qr > mid)
        ret = min(ret,que(ql,qr,rs));
    return ret;
}
#undef ls
#undef rs

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    n = n * 2 + 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[a[i]] = min(i,n - i + 1);
    }
    build(1,n,1);
    int ans = 0,l = 1,r = 1;
    while (l <= n)
    {
        while (r <= n)
        {
            if (que(b[r],n) <= 0)
                break;
            upd(b[r++],n,-1);
        }
        ans = max(ans,r - l);
        upd(b[l++],n,1);
    }
    cout << ans;
    return 0;
}