#include<bits/extc++.h>
#define int long long
#define ls rt << 1
#define rs rt << 1 | 1
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 5e5 + 5;
int n,m,tim;
int a[maxn],u[maxn],v[maxn];
struct Nahida
{
    int minx,cnt,sumy;
    int tagx,tagy;
    void push_up(const Nahida &lson,const Nahida &rson)
    {
        if (lson.minx < rson.minx)
        {
            minx = lson.minx;
            cnt = lson.cnt;
            sumy = lson.sumy;
        }
        else if (lson.minx > rson.minx)
        {
            minx = rson.minx;
            cnt = rson.cnt;
            sumy = rson.sumy;
        }
        else
        {
            minx = lson.minx;
            cnt = lson.cnt + rson.cnt;
            sumy = lson.sumy + rson.sumy;
        }
    }
    void tag_down(int x,int y)
    {
        minx += x,sumy += cnt * y;
        tagx += x,tagy += y;
    }
}tree[maxn << 2];
void push_down(int rt)
{
    int &tagx = tree[rt].tagx;
    int &tagy = tree[rt].tagy;
    if (!tagx && !tagy)
        return;
    tree[ls].tag_down(tagx,tagy);
    tree[rs].tag_down(tagx,tagy);
    tagx = tagy = 0;
}
void build(int l,int r,int rt)
{
    tree[rt].tagx = tree[rt].tagy = 0;
    if (l == r)
    {
        tree[rt].minx = n - l;
        tree[rt].sumy = l;
        tree[rt].cnt = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    tree[rt].push_up(tree[ls],tree[rs]);
}
void updx(int ql,int qr,int x,int l = 1,int r = tim,int rt = 1)
{
    if (ql > qr)
        return;
    if (ql <= l && r <= qr)
        return tree[rt].tag_down(x,0);
    int mid = (l + r) >> 1;
    push_down(rt);
    if (ql <= mid)
        updx(ql,qr,x,l,mid,ls);
    if (qr > mid)
        updx(ql,qr,x,mid + 1,r,rs);
    tree[rt].push_up(tree[ls],tree[rs]);
}
void updy(int ql,int qr,int y,int l = 1,int r = tim,int rt = 1)
{
    if (ql > qr)
        return;
    if (ql <= l && r <= qr)
        return tree[rt].tag_down(0,y);
    int mid = (l + r) >> 1;
    push_down(rt);
    if (ql <= mid)
        updy(ql,qr,y,l,mid,ls);
    if (qr > mid)
        updy(ql,qr,y,mid + 1,r,rs);
    tree[rt].push_up(tree[ls],tree[rs]);
}
void upde(int u,int v,int x)
{
    updx(1,min(a[u],a[v]) - 1,x);
    updy(max(a[u],a[v]),tim,x);
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    for (int i = 1; i < n; i++)
        scanf("%lld%lld",u + i,v + i);
    a[1] = inf,tim = n - 1;// 只有 n - 1 个时刻
    for (int i = 1,x; i <= tim; i++)
        scanf("%lld",&x),a[x] = i;
    build(1,tim,1);
    for (int i = 1; i < n; i++)
        upde(u[i],v[i],-1);
    printf("%lld\n",tree[1].sumy);
    int su,sv,tu,tv;
    while (m--)
    {
        scanf("%lld%lld%lld%lld",&su,&sv,&tu,&tv);
        upde(su,sv,1),upde(tu,tv,-1);
        printf("%lld\n",tree[1].sumy);
    }
    return 0;
}