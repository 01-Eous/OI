#include<cstdio>
#include<cctype>
#include<algorithm>
#define ls (rt << 1)
#define rs (rt << 1 | 1)
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
int n,q;
int a[maxn];
struct Nahida
{
    int l,r,tag,cnt;
    int max1,max2;
    ll sum;
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
inline void push_up(int rt)
{
    tree[rt].sum = tree[ls].sum + tree[rs].sum;
    if (tree[ls].max1 > tree[rs].max1)
    {
        tree[rt].max1 = tree[ls].max1;
        tree[rt].max2 = max(tree[ls].max2,tree[rs].max1);
        tree[rt].cnt = tree[ls].cnt;
    }
    else if (tree[ls].max1 < tree[rs].max1)
    {
        tree[rt].max1 = tree[rs].max1;
        tree[rt].max2 = max(tree[ls].max1,tree[rs].max2);
        tree[rt].cnt = tree[rs].cnt;
    }
    else
    {
        tree[rt].max1 = tree[ls].max1;
        tree[rt].max2 = max(tree[ls].max2,tree[rs].max2);
        tree[rt].cnt = tree[ls].cnt + tree[rs].cnt;
    }
}
inline void tag_down(int rt,int tag)
{
    if (tag >= tree[rt].max1)
        return;
    tree[rt].sum += (1LL * tag - tree[rt].max1) * tree[rt].cnt;
    tree[rt].max1 = tree[rt].tag = tag;
}
inline void push_down(int rt)
{
    if (tree[rt].tag == -1)
        return;
    tag_down(ls,tree[rt].tag);
    tag_down(rs,tree[rt].tag);
    tree[rt].tag = -1;
}
void build(int l,int r,int rt)
{
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].tag = -1;
    if (l == r)
    {
        tree[rt].max1 = tree[rt].sum = a[l];
        tree[rt].max2 = -1;
        tree[rt].cnt = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    push_up(rt);
}
void upd(int ql,int qr,int x,int rt = 1)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (tree[rt].max1 <= x)
        return;
    if (ql <= l && r <= qr && tree[rt].max2 < x)
    {
        tag_down(rt,x);
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
int que_max(int ql,int qr,int rt = 1)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
        return tree[rt].max1;
    push_down(rt);
    int mid = (l + r) >> 1,ret = -1;
    if (ql <= mid)
        ret = max(ret,que_max(ql,qr,ls));
    if (qr > mid)
        ret = max(ret,que_max(ql,qr,rs));
    return ret;
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
inline void solve()
{
    read(n),read(q);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    build(1,n,1);
    int op,l,r,x;
    while (q--)
    {
        read(op),read(l),read(r);
        if (op == 0)
        {
            read(x);
            upd(l,r,x);
        }
        else if (op == 1)
            printf("%d\n",que_max(l,r));
        else
            printf("%lld\n",que_sum(l,r));
    }
}
signed main()
{
    int t;
    read(t);
    while (t--)
        solve();
    return 0;
}