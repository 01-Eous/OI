#include<bits/extc++.h>
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5;
int n,m;
int a[maxn];
struct Nahida
{
    int l,r;
    int max1,min1;//最大，最小
    int max2,min2;//次大，次小
    int cmax,cmin;//最大，最小值计数
    ll sum;
    int add,tmax,tmin;//tags
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
        tree[rt].cmax = tree[ls].cmax;
    }
    else if (tree[ls].max1 < tree[rs].max1)
    {
        tree[rt].max1 = tree[rs].max1;
        tree[rt].max2 = max(tree[ls].max1,tree[rs].max2);
        tree[rt].cmax = tree[rs].cmax;
    }
    else
    {
        tree[rt].max1 = tree[ls].max1;
        tree[rt].max2 = max(tree[ls].max2,tree[rs].max2);
        tree[rt].cmax = tree[ls].cmax + tree[rs].cmax;
    }
    if (tree[ls].min1 < tree[rs].min1)
    {
        tree[rt].min1 = tree[ls].min1;
        tree[rt].min2 = min(tree[ls].min2,tree[rs].min1);
        tree[rt].cmin = tree[ls].cmin;
    }
    else if (tree[ls].min1 > tree[rs].min1)
    {
        tree[rt].min1 = tree[rs].min1;
        tree[rt].min2 = min(tree[ls].min1,tree[rs].min2);
        tree[rt].cmin = tree[rs].cmin;
    }
    else
    {
        tree[rt].min1 = tree[ls].min1;
        tree[rt].min2 = min(tree[ls].min2,tree[rs].min2);
        tree[rt].cmin = tree[ls].cmin + tree[rs].cmin;
    }
}
inline void tag_add(int rt,int x)//a[i] += x
{
    tree[rt].sum += (tree[rt].r - tree[rt].l + 1LL) * x;
    tree[rt].max1 += x,tree[rt].min1 += x;
    if (tree[rt].max2 != -inf)
        tree[rt].max2 += x;
    if (tree[rt].min2 != inf)
        tree[rt].min2 += x;
    if (tree[rt].tmax != -inf)
        tree[rt].tmax += x;
    if (tree[rt].tmin != inf)
        tree[rt].tmin += x;
    tree[rt].add += x;
}
inline void tag_min(int rt,int tag)//a[i] -> min(a[i],x)
{
    if (tree[rt].max1 <= tag)
        return;
    tree[rt].sum += (1LL * tag - tree[rt].max1) * tree[rt].cmax;
    if (tree[rt].min2 == tree[rt].max1)
        tree[rt].min2 = tag;
    if (tree[rt].min1 == tree[rt].max1)
        tree[rt].min1 = tag;
    tree[rt].tmax = min(tree[rt].tmax,tag);
    tree[rt].max1 = tree[rt].tmin = tag;
}
inline void tag_max(int rt,int tag)//a[i] -> max(a[i],x)
{
    if (tree[rt].min1 >= tag)
        return;
    tree[rt].sum += (1LL * tag - tree[rt].min1) * tree[rt].cmin;
    if (tree[rt].max2 == tree[rt].min1)
        tree[rt].max2 = tag;
    if (tree[rt].max1 == tree[rt].min1)
        tree[rt].max1 = tag;
    tree[rt].tmin = max(tree[rt].tmin,tag);
    tree[rt].min1 = tree[rt].tmax = tag;
}
inline void push_down(int rt)
{
    if (tree[rt].add != 0)
    {
        tag_add(ls,tree[rt].add);
        tag_add(rs,tree[rt].add);
    }
    if (tree[rt].tmax != -inf)
    {
        tag_max(ls,tree[rt].tmax);
        tag_max(rs,tree[rt].tmax);
    }
    if (tree[rt].tmin != inf)
    {
        tag_min(ls,tree[rt].tmin);
        tag_min(rs,tree[rt].tmin);
    }
    tree[rt].add = 0;
    tree[rt].tmax = -inf;
    tree[rt].tmin = inf;
}
void build(int l,int r,int rt)
{
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].add = 0;
    tree[rt].tmax = -inf;
    tree[rt].tmin = inf;
    if (l == r)
    {
        tree[rt].max1 = tree[rt].min1 = tree[rt].sum = a[l];
        tree[rt].max2 = -inf;
        tree[rt].min2 = inf;
        tree[rt].cmax = tree[rt].cmin = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    push_up(rt);
}
void add(int ql,int qr,int x,int rt = 1)//a[i] += x
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
        return tag_add(rt,x);
    push_down(rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        add(ql,qr,x,ls);
    if (qr > mid)
        add(ql,qr,x,rs);
    push_up(rt);
}
void to_min(int ql,int qr,int x,int rt = 1)//a[i] -> min(a[i],x)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (tree[rt].max1 <= x)
        return;
    if (ql <= l && r <= qr && tree[rt].max2 < x)
        return tag_min(rt,x);
    push_down(rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        to_min(ql,qr,x,ls);
    if (qr > mid)
        to_min(ql,qr,x,rs);
    push_up(rt);
}
void to_max(int ql,int qr,int x,int rt = 1)//a[i] = max(a[i],x)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (tree[rt].min1 >= x)
        return;
    if (ql <= l && r <= qr && tree[rt].min2 > x)
        return tag_max(rt,x);
    push_down(rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        to_max(ql,qr,x,ls);
    if (qr > mid)
        to_max(ql,qr,x,rs);
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
int que_max(int ql,int qr,int rt = 1)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
        return tree[rt].max1;
    push_down(rt);
    int mid = (l + r) >> 1,ret = -inf;
    if (ql <= mid)
        ret = max(ret,que_max(ql,qr,ls));
    if (qr > mid)
        ret = max(ret,que_max(ql,qr,rs));
    return ret;
}
int que_min(int ql,int qr,int rt = 1)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
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
    read(n);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    build(1,n,1);
    read(m);
    int op,l,r,x;
    while (m--)
    {
        read(op),read(l),read(r);
        if (op <= 3)
        {
            read(x);
            if (op == 1)
                add(l,r,x);
            else if (op == 2)
                to_max(l,r,x);
            else
                to_min(l,r,x);
        }
        else if (op == 4)
            printf("%lld\n",que_sum(l,r));
        else if (op == 5)
            printf("%d\n",que_max(l,r));
        else
            printf("%d\n",que_min(l,r));
    }
    return 0;
}